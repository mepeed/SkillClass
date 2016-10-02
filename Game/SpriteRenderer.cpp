#include "DXUT.h"
#include "SpriteRenderer.h"


SpriteRenderer::SpriteRenderer()
{
}


SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Render()
{
	if (SUCCEEDED(sD3dxSpritePtr->Begin(D3DXSPRITE_ALPHABLEND)))
	{
		sD3dxSpritePtr->Draw(mTexturePtr->Get(),
			nullptr,
			nullptr,
			nullptr,
			D3DCOLOR_XRGB(255, 255, 255));
		sD3dxSpritePtr->End();
	}
}
