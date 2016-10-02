#pragma once
#include "Object.h"
class SpriteRenderer;
class Texture;
class Monster :
	public Object
{
public:
	Monster();
	virtual ~Monster();

public:
	virtual	HRESULT Load() override;
	virtual	void	Update() override;
	virtual	void	Render() override;

	void	Respawn();

	const RECT& GetRect();

	void	SetHP(int hp);
	int		GetHP();

private:
	SpriteRenderer* mRendererPtr;

	shared_ptr<Texture> mTexturePtr;

	RECT		mRect;

	int		mHP;
};

