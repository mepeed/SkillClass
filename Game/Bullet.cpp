#include "DXUT.h"
#include "Bullet.h"
#include "SpriteRenderer.h"
#include "Texture.h"

Bullet::Bullet(D3DXVECTOR3 pos, D3DXVECTOR3 mouse)
: Object()
, mRendererPtr(new SpriteRenderer())
, mIsErase(false)
{
	mPosition = (pos);

	D3DXVECTOR3 direct =  mouse - pos;
	D3DXVec3Normalize(&mDirect, &direct);

	D3DXMatrixRotationZ(&mRotationMatrix, atan2(mDirect.y, mDirect.x));

	Load();
}

Bullet::Bullet(D3DXVECTOR3 pos, D3DXVECTOR3 mouse, float degree)
: Object()
, mRendererPtr(new SpriteRenderer())
, mIsErase(false)
{
	mPosition = pos;

	D3DXVECTOR3 direct = mouse - pos;
	D3DXVec3Normalize(&direct, &direct);

	D3DXMATRIX r;
	D3DXMatrixRotationZ(&r, D3DXToRadian(degree));

	mRotationMatrix = r;

	D3DXVec3TransformCoord(&direct, &direct, &r);
	D3DXVec3Normalize(&mDirect, &direct);

	Load();
}


Bullet::~Bullet()
{
	SAFE_DELETE(mRendererPtr);
}

HRESULT	Bullet::Load()
{
	HRESULT hr;
	mTexturePtr = make_shared<Texture>();
	V_RETURN(mTexturePtr->Load(L"Resources/Bullet.png"));
	mRendererPtr->SetTexture(mTexturePtr);
	return S_OK;
}

void	Bullet::Update()
{
	mPosition += mDirect * 35;
	CheckDisplay();
}

void	Bullet::Render()
{
	D3DXMATRIX s, r, t;
	D3DXMatrixScaling(&s, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&r, D3DXToRadian(90.f));
	D3DXMatrixTranslation(&t, mPosition.x, mPosition.y, mPosition.z);
	
	r *= mRotationMatrix;

	mWorldTM = s * r * t;

	Renderer::sD3dxSpritePtr->SetTransform(&mWorldTM);
	mRendererPtr->Render();
}

const RECT& Bullet::GetRect()
{
	mRect = { mPosition.x,
		mPosition.y,
		mPosition.x + mTexturePtr->GetInfo().Width,
		mPosition.y + mTexturePtr->GetInfo().Height };
	return mRect;
}

void Bullet::CheckDisplay()
{
	RECT display = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };

	if (!InCollision(display, GetRect()))
	{
		mIsErase = true;
	}
}

bool Bullet::GetErase()
{
	return mIsErase;
}
