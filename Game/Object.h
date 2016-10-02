#pragma once
class Object
{
public:
	Object();
	virtual ~Object();

public:
	virtual	HRESULT Load()	PURE;
	virtual	void	Update() {};
	virtual	void	Render()	 {};

protected:
	D3DXVECTOR3	mPosition;
	D3DXMATRIX		mWorldTM;

};

