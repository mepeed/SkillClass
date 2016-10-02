#include "DXUT.h"
#include "Renderer.h"
#include "Texture.h"

LPD3DXSPRITE	Renderer::sD3dxSpritePtr;

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void		Renderer::SetTexture(shared_ptr<Texture> texturePtr)
{
	mTexturePtr = texturePtr;
}

void		Renderer::Release()
{
	SAFE_RELEASE(sD3dxSpritePtr);
}

HRESULT	Renderer::CreateSprite()
{
	HRESULT hr;
	V_RETURN(D3DXCreateSprite(DXUTGetD3D9Device(), &sD3dxSpritePtr));
	return S_OK;
}
