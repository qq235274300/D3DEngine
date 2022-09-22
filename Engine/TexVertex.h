#pragma once
#include "Vec3.h"
#include "Vec2.h"

class TexVertex
{
public:
	TexVertex(const Vec3& inPos, const Vec2& inTc)
		:pos(inPos), tc(inTc)
	{

	};
	TexVertex Interpolate(const TexVertex& target, float alpha)const
	{
		return {
			pos.InterpolateTo(target.pos,alpha),
			tc.InterpolateTo(target.tc,alpha)
		};
	}
	


private:
	Vec3 pos;
	Vec2 tc; // texture coordinate
};

