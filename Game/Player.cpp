#include "DXUT.h"
#include "Player.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "Texture.h"
#include "Bullet.h"

Player::Player()
: Object()
, mRendererPtr(new SpriteRenderer())
, mfDelay(0.f)
, BulletAudio(nullptr)
{
	mPosition = D3DXVECTOR3(100.f, 100.f, 0);

	BulletAudio = ResourceManager::Get().LoadAudioClip(L"Resources/Laser.wav");
}


Player::~Player()
{
	SAFE_DELETE(mRendererPtr);

	auto iter = mBulletlst.begin();
	auto iter_end = mBulletlst.end();

	while (iter != iter_end)
	{
		SAFE_DELETE((*iter));
		iter++;
	}
	mBulletlst.clear();

	BulletAudio = nullptr;
}

HRESULT	Player::Load()
{
	HRESULT hr;
	mTexturePtr = make_shared<Texture>();
	V_RETURN(mTexturePtr->Load(L"Resources/Player.png"));
	mRendererPtr->SetTexture(mTexturePtr);
	return S_OK;
}

void	Player::Update()
{
	Move();
	Attack();

	auto iter = mBulletlst.begin();
	auto iter_end = mBulletlst.end();
	while (iter != iter_end)
	{
		if ((*iter)->GetErase())
		{
			auto temp = iter;
			temp++;
			SAFE_DELETE((*iter));
			mBulletlst.erase(iter);
			iter = temp;
			continue;
		}
		(*iter)->Update();
		iter++;
	}
}

void	Player::Render()
{
	auto iter = mBulletlst.begin();
	auto iter_end = mBulletlst.end();
	while (iter != iter_end)
	{
		(*iter)->Render();
		iter++;
	}

	D3DXMatrixTranslation(&mWorldTM, mPosition.x, mPosition.y, mPosition.z);
	Renderer::sD3dxSpritePtr->SetTransform(&mWorldTM);
	mRendererPtr->Render();
}

const RECT& Player::GetRect()
{
	mRect = { mPosition.x,
		mPosition.y,
		mPosition.x + mTexturePtr->GetInfo().Width,
		mPosition.y + mTexturePtr->GetInfo().Height };
	return mRect;
}

void Player::Move()
{
	float speed = 15;
	if (GetAsyncKeyState('W') & 0x8000)
	{
		mPosition.y -= speed;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		mPosition.x -= speed;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		mPosition.y += speed;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		mPosition.x += speed;
	}
}

void Player::Attack()
{
	mfDelay += DXUTGetElapsedTime() * 1.0f;

	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(DXUTGetHWND(), &pt);

	if (mfDelay >= 0.1f)
	{
		if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000))
		{
			mfDelay = 0;
			BulletAudio->Play(false);

			mBulletlst.push_back(new Bullet(mPosition, D3DXVECTOR3(pt.x, pt.y, 0)));
		}

		if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000))
		{
			mfDelay = 0;
			BulletAudio->Play(false);

			for (int i = -1; i < 2; i++)
			{
				mBulletlst.push_back(new Bullet(
					  mPosition
					, D3DXVECTOR3(pt.x, pt.y, 0)
					, 30 * i));
			}
		}
	}
}

bool Player::CollisionBullet(const RECT& rc)
{
	auto iter = mBulletlst.begin();
	auto iter_end = mBulletlst.end();

	while (iter != iter_end)
	{
		if (InCollision(rc, (*iter)->GetRect()))
		{
			SAFE_DELETE((*iter));
			mBulletlst.erase(iter);
			return true;
		}

		iter++;
	}
	return false;
}
