#pragma once
#include "Vec3.h"
#include <vector>
#include "IndexedLineList.h"
//一个正方体 8个点 十二条线 普通绘制需要 12x2  24个记录点

class Cube
{
	
public:
	Cube(float size)
	{
		const float side = size / 2.0f;
		vertices.emplace_back(-side, -side, -side);
		vertices.emplace_back(side, -side, -side);
		vertices.emplace_back(-side, side, -side);
		vertices.emplace_back(side, side, -side);
		vertices.emplace_back(-side, -side, side);
		vertices.emplace_back(side, -side, side);
		vertices.emplace_back(-side, side, side);
		vertices.emplace_back(side, side, side);
	}
	IndexedLineList GetLines() const
	{
		return{
			vertices,{
			0,1,  1,3,  3,2,  2,0,
			0,4,  1,5,	3,7,  2,6,
			4,5,  5,7,	7,6,  6,4 }
		};
	}

private:
	std::vector<Vec3> vertices;
};