#pragma once
#include "Singleton.h"
#include "SpriteRenderer.h"

class Item;
class Player;
class Monster;
class AudioClip;
class GameManager
	: public Singleton<GameManager>
{
public:
	GameManager();
	virtual ~GameManager();

public:
	void Init();

	HRESULT OnReset();
	void OnLostDevice();
	void Destroy();

	void Update();
	void Render();

private:
	Player*		mPlayerPtr;
	Monster*	mMonsterPtr;
	Item*		mItemPtr;

	shared_ptr<AudioClip> clip;
};

