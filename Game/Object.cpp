#include "DXUT.h"
#include "Object.h"


Object::Object()
: mPosition(0,0,0)
{
	D3DXMatrixIdentity(&mWorldTM);
}


Object::~Object()
{
}
