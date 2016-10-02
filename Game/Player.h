#pragma once
#include "Object.h"
class Bullet;
class Texture;
class AudioClip;
class SpriteRenderer;
class Player :
	public Object
{
public:
	Player();
	virtual ~Player();

public:
	virtual	HRESULT Load() override;
	virtual	void	Update() override;
	virtual	void	Render() override;

	void	Move();
	bool	CollisionBullet(const RECT& rc);
	void	Attack();

	const RECT& GetRect();

private:
	SpriteRenderer* mRendererPtr;

	shared_ptr<Texture> mTexturePtr;

	RECT		mRect;

	list<Bullet*> mBulletlst;

	float	mfDelay;

	shared_ptr<AudioClip> BulletAudio;
};

