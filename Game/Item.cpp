#include "DXUT.h"
#include "Item.h"
#include "SpriteRenderer.h"

Item::Item()
: Object()
, mRendererPtr(new SpriteRenderer())
{
}


Item::~Item()
{
	SAFE_DELETE(mRendererPtr);
}

void	Item::Respawn()
{
	mPosition = D3DXVECTOR3(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT, 0);
}

HRESULT Item::Load()
{
	HRESULT hr;
	mTexturePtr = make_shared<Texture>();
	V_RETURN(mTexturePtr->Load(L"Resources/Item.png"));
	mRendererPtr->SetTexture(mTexturePtr);

	Respawn();
	return S_OK;
}

void	Item::Render()
{
	D3DXMatrixTranslation(&mWorldTM, mPosition.x, mPosition.y, mPosition.z);
	Renderer::sD3dxSpritePtr->SetTransform(&mWorldTM);
	mRendererPtr->Render();
}

const RECT& Item::GetRect()
{
	mRect = {	mPosition.x, 
					mPosition.y, 
					mPosition.x + mTexturePtr->GetInfo().Width, 
					mPosition.y + mTexturePtr->GetInfo().Height };
	return mRect;
}
