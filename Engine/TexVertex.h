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
	TexVertex InterpolateTo(const TexVertex& target, float alpha)const
	{
		return {
			pos.InterpolateTo(target.pos,alpha),
			tc.InterpolateTo(target.tc,alpha)
		};
	}
	
	TexVertex& operator+=(const TexVertex& rhs)
	{
		pos += rhs.pos;
		tc += rhs.tc;
		return *this;
	}
	TexVertex operator+(const TexVertex& rhs) const
	{
		return TexVertex(*this) += rhs;
	}
	TexVertex& operator-=(const TexVertex& rhs)
	{
		pos -= rhs.pos;
		tc -= rhs.tc;
		return *this;
	}
	TexVertex operator-(const TexVertex& rhs) const
	{
		return TexVertex(*this) -= rhs;
	}
	TexVertex& operator*=(float rhs)
	{
		pos *= rhs;
		tc *= rhs;
		return *this;
	}
	TexVertex operator*(float rhs) const
	{
		return TexVertex(*this) *= rhs;
	}
	TexVertex& operator/=(float rhs)
	{
		pos /= rhs;
		tc /= rhs;
		return *this;
	}
	TexVertex operator/(float rhs) const
	{
		return TexVertex(*this) /= rhs;
	}
public:
	Vec3 pos;
	Vec2 tc; // texture coordinate
};

