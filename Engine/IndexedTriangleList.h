#pragma once

#include <vector>
#include "Vec3.h"

template<class T>
class  IndexedTriangleList
{
	IndexedTriangleList(std::vector<T> InVertices, std::vector<size_t> InTriangle)
	{
		//assert(InVertices.size() > 2);
		assert(InTriangle.size() % 3 == 0);
		vertices = std::move(InVertices);
		Triangle = std::move(InTriangle);
		cullFlag.resize(Triangle.size() /3 , false);
	}
	
	std::vector<T> vertices;
	std::vector<size_t> Triangle;
	std::vector<bool> cullFlag;
};