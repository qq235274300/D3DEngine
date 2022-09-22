#pragma once

#include "Scene.h"
#include "Cube.h"
#include "PubeScreenTransformer.h"
#include "IndexedTriangleList.h"

class SolidCubeScene : public Scene
{
public:
	SolidCubeScene()
		:
		Scene("Solid Cube Different Colored Triangles")
	{}
	virtual void Update(const Keyboard& kbd, const Mouse& mouse, const float dt)override;
	virtual void Draw(Graphics& gfx)override;

private:
	// Render Cube
	Cube m_Cube= Cube(1.0f);
	PubeScreenTransformer m_pst;

	static constexpr float m_RotatorSpeed = PI;
	float m_zOffset = 2.f;
	float m_xRot = 0.f;
	float m_yRot = 0.f;
	float m_zRot = 0.f;

	static constexpr Color CubeColor[12] = {
		Colors::White,
		Colors::Blue,
		Colors::Cyan,
		Colors::Gray,
		Colors::Green,
		Colors::Magenta,
		Colors::LightGray,
		Colors::Red,
		Colors::Yellow,
		Colors::White,
		Colors::Blue,
		Colors::Cyan
	};
};