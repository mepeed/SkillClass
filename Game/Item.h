#pragma once
#include "Object.h"

class Texture;
class SpriteRenderer;
class Item :
	public Object
{
public:
	Item();
	virtual ~Item();

public:
	void	Respawn();
	virtual	HRESULT Load() override;
	virtual	void	Render() override;

	const RECT& GetRect();

private:
	SpriteRenderer* mRendererPtr;
	shared_ptr<Texture> mTexturePtr;

	RECT mRect;
};

