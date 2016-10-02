#pragma once
#include "Object.h"

class SpriteRenderer;
class Texture;
class Bullet :
	public Object
{
public:
	Bullet(D3DXVECTOR3 pos, D3DXVECTOR3 mouse);
	Bullet(D3DXVECTOR3 pos, D3DXVECTOR3 mouse, float degree);
	virtual ~Bullet();

public:
	virtual	HRESULT Load() override;
	virtual	void	Update() override;
	virtual	void	Render() override;

	const RECT& GetRect();

	void	CheckDisplay();

	bool	GetErase();

private:
	SpriteRenderer* mRendererPtr;

	shared_ptr<Texture> mTexturePtr;

	RECT		mRect;

	D3DXVECTOR3	mDirect;

	D3DXMATRIX mRotationMatrix;

	bool		mIsErase;
};

