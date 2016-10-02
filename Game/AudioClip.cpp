#include "DXUT.h"
#include "AudioClip.h"

AudioClip::AudioClip()
: mClip(nullptr)
{
}

AudioClip::AudioClip(CSound* sound)
: mClip(sound)
{
}


AudioClip::~AudioClip()
{
	SAFE_DELETE(mClip);
}


void AudioClip::Set(CSound* soundPtr)
{
	mClip = soundPtr;
}

void AudioClip::Play(bool loop)
{
	mClip->Play(0, loop);
}
