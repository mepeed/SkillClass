#pragma once
#include "Asset.h"
#include "SDKsound.h"

class CSound;
class AudioClip :
	public Asset
{
public:
	AudioClip();
	AudioClip(CSound* sound);
	virtual ~AudioClip();
	
	void Set(CSound* sound);
	void	Play(bool loop);

private:
	CSound* mClip;
};

