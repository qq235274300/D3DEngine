#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"

class Scene
{
public:
	virtual void Update(const Keyboard& kbd, const Mouse& mouse,const float dt) = 0;
	virtual void Draw(Graphics& gfx) = 0;
	virtual ~Scene() = default;
};