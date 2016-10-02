#include "DXUT.h"
#include "ResourceManager.h"

ResourceManager::ResourceManager()
: mSoundManager()
{
}


ResourceManager::~ResourceManager()
{
}

HRESULT ResourceManager::Init()
{
	HRESULT hr;
	V_RETURN(mSoundManager.Initialize(DXUTGetHWND(), DSSCL_EXCLUSIVE));
}

shared_ptr<AudioClip> ResourceManager::LoadAudioClip(const wstring& path)
{
	HRESULT hr;

	CSound* soundPtr = nullptr;
	V(mSoundManager.Create(&soundPtr, (LPWSTR)path.c_str()));

	auto AudioClipPtr = make_shared<AudioClip>();
	AudioClipPtr->Set(soundPtr);

	return AudioClipPtr;
}
