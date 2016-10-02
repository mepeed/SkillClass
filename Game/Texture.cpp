#include "DXUT.h"
#include "Texture.h"


Texture::Texture()
: mTexture9Ptr(nullptr)
{
}

Texture::Texture(const wstring& path)
{
	Load(path);
}

Texture::~Texture()
{
	SAFE_RELEASE(mTexture9Ptr);
}

HRESULT		Texture::Load(const wstring& path, UINT mipmap)
{
	//HRESULT hr;
	(D3DXCreateTextureFromFileEx(DXUTGetD3D9Device()
		, path.c_str()
		, D3DX_DEFAULT_NONPOW2					//D3DX_DEFAULT ������ ���Ϸ� ���� texture width�� �ҷ���		 
		, D3DX_DEFAULT_NONPOW2					//D3DX_DEFAULT ������ ���Ϸ� ���� texture height�� �ҷ���	         
		, mipmap							//D3DX_DEFAULT ������ �Ӹ� ����
		, 0
		, D3DFMT_UNKNOWN
		, D3DPOOL_MANAGED
		, D3DX_DEFAULT
		, D3DX_DEFAULT
		, 0
		, &info
		, NULL
		, &mTexture9Ptr));
	return S_OK;
}

const LPDIRECT3DTEXTURE9& Texture::Get()
{
	return mTexture9Ptr;
}

const	D3DXIMAGE_INFO& Texture::GetInfo()
{
	return info;
}
