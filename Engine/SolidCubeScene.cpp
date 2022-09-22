#include "SolidCubeScene.h"
#include "Mat3.h"

void SolidCubeScene::Update(const Keyboard& kbd, const Mouse& mouse, const float dt)
{
	if (kbd.KeyIsPressed('Q'))
	{
		m_xRot = wrap_angle(m_xRot + dt * m_RotatorSpeed);
	}
	if (kbd.KeyIsPressed('W'))
	{
		m_yRot = wrap_angle(m_yRot + dt * m_RotatorSpeed);
	}
	if (kbd.KeyIsPressed('E'))
	{
		m_zRot = wrap_angle(m_zRot + dt * m_RotatorSpeed);
	}
	if (kbd.KeyIsPressed('A'))
	{
		m_xRot = wrap_angle(m_xRot - dt * m_RotatorSpeed);
	}
	if (kbd.KeyIsPressed('S'))
	{
		m_yRot = wrap_angle(m_yRot - dt * m_RotatorSpeed);
	}
	if (kbd.KeyIsPressed('D'))
	{
		m_zRot = wrap_angle(m_zRot - dt * m_RotatorSpeed);
	}
	//ÎïÌåÔ¶½ü
	if (kbd.KeyIsPressed('R'))
	{
		m_zOffset = m_zOffset - dt * 1.f;
	}
	if (kbd.KeyIsPressed('F'))
	{
		m_zOffset = m_zOffset + dt * 1.f;
	}
}

void SolidCubeScene::Draw(Graphics& gfx)
{
	IndexedTriangleList& Triangles = m_Cube.GetTriangles();
	const Mat3 Mat3Rot = 
		Mat3::RotationX(m_xRot) * Mat3::RotationY(m_yRot) * Mat3::RotationZ(m_zRot);
	for (auto& v : Triangles.vertices)
	{
		//TRS?
		v *= Mat3Rot;
		v += {0.f, 0.f, m_zOffset};

	}

	for (int i = 0, end = Triangles.Triangle.size() / 3; i < end; ++i)
	{

		const Vec3& v0 = Triangles.vertices[Triangles.Triangle[i * 3]];
		const Vec3& v1 = Triangles.vertices[Triangles.Triangle[i * 3 + 1]];
		const Vec3& v2 = Triangles.vertices[Triangles.Triangle[i * 3 + 2]];

		Triangles.cullFlag[i] = (v1 - v0) % (v2 - v0) * v0 >= 0;
	}

	for (auto& v : Triangles.vertices)
	{
		m_pst.Transform(v);
	}

	for (int i = 0, end = Triangles.Triangle.size() / 3; i < end; ++i)
	{
		if (!Triangles.cullFlag[i])
		{
			gfx.DrawTriangle(Triangles.vertices[Triangles.Triangle[i * 3]], Triangles.vertices[Triangles.Triangle[i * 3 + 1]], Triangles.vertices[Triangles.Triangle[i * 3 + 2]], CubeColor[i]);
		}
	}

}
