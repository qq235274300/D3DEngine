#pragma once
#include "Graphics.h"
#include "Vec3.h"

//这个Pube空间只是示例 代表ObjetSpace -> World -> View -> Projection -> Screen;

class PubeScreenTransformer
{
public:
	PubeScreenTransformer()
	:m_xFactor((float)Graphics::ScreenWidth / 2.f),m_yFactor((float)Graphics::ScreenHeight/2.f)
	{
		
	}
	
	Vec3& Transform(Vec3& v)
	{
		v.x = (v.x + 1.f) * m_xFactor;
		v.y = (-v.y + 1.f) *  m_yFactor;	
		return v;
	}

	Vec3 GetTransformed(const Vec3& v)
	{
		return Transform(Vec3(v));
	}

private:
	float m_xFactor;
	float m_yFactor;

};