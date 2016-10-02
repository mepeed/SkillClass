#pragma once
#include "Texture.h"
class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

public:
	virtual	void	SetTexture(shared_ptr<Texture> texturePtr);
	virtual	void	Render() PURE;

public:
	static 	void	Release();

protected:
	shared_ptr<Texture>	mTexturePtr;

//Sprite Begin
public:
	static		HRESULT		CreateSprite();

public:
	static		LPD3DXSPRITE	sD3dxSpritePtr;
//Sprite End
};

