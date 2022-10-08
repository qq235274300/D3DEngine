#pragma once

#include <vector>
#include "Vec3.h"

template<class T>
class  IndexedTriangleList
{
public:
	IndexedTriangleList(std::vector<T> InVertices, std::vector<size_t> InIndices)
	{
		//assert(InVertices.size() > 2);
		assert(InIndices.size() % 3 == 0);
		vertices = std::move(InVertices);
		indices = std::move(InIndices);
		//cullFlag.resize(Triangle.size() /3 , false);
	}
	
	std::vector<T> vertices;
	std::vector<size_t> indices;
	
};