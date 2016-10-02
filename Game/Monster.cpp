#include "DXUT.h"
#include "Monster.h"
#include "SpriteRenderer.h"
#include "Texture.h"

Monster::Monster()
: Object()
, mRendererPtr(new SpriteRenderer())
, mHP(rand()%10)
{
	Respawn();
}


Monster::~Monster()
{
	SAFE_DELETE(mRendererPtr);
}

HRESULT	Monster::Load()
{
	HRESULT hr;
	mTexturePtr = make_shared<Texture>();
	V_RETURN(mTexturePtr->Load(L"Resources/Monster.png"));
	mRendererPtr->SetTexture(mTexturePtr);
	return S_OK;
}

void	Monster::Update()
{
	
}

void	Monster::Render()
{
	D3DXMatrixTranslation(&mWorldTM, mPosition.x, mPosition.y, mPosition.z);
	Renderer::sD3dxSpritePtr->SetTransform(&mWorldTM);
	mRendererPtr->Render();
}

void	Monster::Respawn()
{
	mHP = rand() % 10;
	mPosition = D3DXVECTOR3(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT, 0);
}

const RECT& Monster::GetRect()
{
	mRect = { mPosition.x,
		mPosition.y,
		mPosition.x + mTexturePtr->GetInfo().Width,
		mPosition.y + mTexturePtr->GetInfo().Height };
	return mRect;
}

void	Monster::SetHP(int hp)
{
	mHP = hp;
}

int		Monster::GetHP()
{
	return mHP;
}
