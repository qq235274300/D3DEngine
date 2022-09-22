#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"

class Scene
{
public:
	Scene(const std::string& name)
		:
		name(name)
	{}
	virtual void Update(const Keyboard& kbd, const Mouse& mouse,const float dt) = 0;
	virtual void Draw(Graphics& gfx) = 0;
	virtual ~Scene() = default;
	const std::string& GetName() const
	{
		return name;
	}
private:
	std::string name;
};