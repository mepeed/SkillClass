#pragma once
#include "Singleton.h"
#include "AudioClip.h"

class CSoundManager;
class ResourceManager :
	public Singleton<ResourceManager>
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	HRESULT Init();

	shared_ptr<AudioClip> LoadAudioClip(const wstring& path);

private:
	CSoundManager mSoundManager;
};

