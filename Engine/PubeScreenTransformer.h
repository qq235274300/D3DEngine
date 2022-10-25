  #pragma once
#include "Graphics.h"
#include "Vec3.h"

//���Pube�ռ�ֻ��ʾ�� ����ObjetSpace -> World -> View -> Projection -> Screen;

class PubeScreenTransformer
{
public:
	PubeScreenTransformer()
	:m_xFactor((float)Graphics::ScreenWidth / 2.f),m_yFactor((float)Graphics::ScreenHeight/2.f)
	{
		
	}
	template<class Vertex>
	Vertex& Transform(Vertex& v)
	{
		const float zInverse = 1.0f / v.pos.z;

		v *= zInverse;
		
		v.pos.x = (v.pos.x  + 1.f) * m_xFactor;
		v.pos.y = (-v.pos.y  + 1.f) *  m_yFactor;

		v.pos.z = zInverse;

		return v;
	}

	template<class Vertex>
	Vertex GetTransformed(const Vertex& v)
	{
		return Transform(Vertex(v));
	}

private:
	float m_xFactor;
	float m_yFactor;

};