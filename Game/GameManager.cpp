#include "DXUT.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Player.h"
#include "Item.h"
#include "Monster.h"

GameManager::GameManager()
: clip(nullptr)
{
}


GameManager::~GameManager()
{
}

void	GameManager::Init()
{
	HRESULT hr;
	V(ResourceManager::Get().Init());
	clip = ResourceManager::Get().LoadAudioClip(L"Resources/Alarm01.wav");
	clip->Play(true);

	mPlayerPtr = new Player;
	mPlayerPtr->Load();

	mItemPtr = new Item;
	mItemPtr->Load();

	mMonsterPtr = new Monster;
	mMonsterPtr->Load();
}

HRESULT	GameManager::OnReset()
{
	HRESULT hr;

	V_RETURN(Renderer::CreateSprite());

	return S_OK;
}

void	GameManager::OnLostDevice()
{
	Renderer::Release();
}

void	GameManager::Destroy()
{
	SAFE_DELETE(mPlayerPtr);
	SAFE_DELETE(mItemPtr);
	SAFE_DELETE(mMonsterPtr);
	clip = nullptr;
	Renderer::Release();
}

void	GameManager::Update()
{
	mPlayerPtr->Update();
	mItemPtr->Update();
	mMonsterPtr->Update();

	if (InCollision(mPlayerPtr->GetRect(), mItemPtr->GetRect()))
	{
		mItemPtr->Respawn();
	}
	if (mPlayerPtr->CollisionBullet(mMonsterPtr->GetRect()))
	{
		mMonsterPtr->SetHP(mMonsterPtr->GetHP() - 1);
		if (mMonsterPtr->GetHP() <= 0)
			mMonsterPtr->Respawn();
	}
}

void	GameManager::Render()
{
	mPlayerPtr->Render();
	mItemPtr->Render();
	mMonsterPtr->Render();
}
