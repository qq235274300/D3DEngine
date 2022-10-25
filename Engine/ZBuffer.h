#pragma once

#include <limits>
#include <cassert>

class ZBuffer
{
public:
	ZBuffer(int inWidth, int InHeight)
		:width(inWidth),height(InHeight),pBuffer(new float[inWidth * InHeight])
	{
		
	}

	~ZBuffer()
	{
		delete pBuffer;
		pBuffer = nullptr;
	}

	ZBuffer(const ZBuffer& buffer) = delete;
	ZBuffer& operator=(const ZBuffer& buffer) = delete;

	void Clear()
	{
		int depth = width * height;
		for (int i = 0; i < depth; ++i)
		{
			pBuffer[i] = std::numeric_limits<float>::infinity();
		}
	}

	float& At(int x, int y)
	{
		assert(x > 0);
		assert(x < width);
		assert(y > 0);
		assert(y < height);

		return pBuffer[y * width + x];
	}
	//const 在后面意味着 this 指针指向的对象不可修改 ， const 在前面 表面返回值不允许修改
	const float& At(int x, int y) const
	{
		
		return  const_cast<ZBuffer*>(this)->At(x, y);
	 }

	bool TestAndSet(int x, int y, float depth)
	{
		float& depthInBuffer = At(x, y);
		
		if (depthInBuffer > depth)
		{
			depthInBuffer = depth;
			return true;
		} 
		

		return false;
	}

private:
	int width;
	int height;
	float* pBuffer;
};