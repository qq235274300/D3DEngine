/******************************************************************************************
*	Chili DirectX Framework Version 16.10.01											  *
*	Game.cpp																			  *
*	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
*																						  *
*	This file is part of The Chili DirectX Framework.									  *
*																						  *
*	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Mat2.h"
#include "Mat3.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	m_Cube(1.f)
{
	const float dTheta = 2.0f * PI / float( nflares * 2 );
	for( int i = 0; i < nflares * 2; i++ )
	{
		const float rad = (i % 2 == 0) ? radOuter : radInner;
		star.emplace_back(
			rad * cos( float( i ) * dTheta ),
			rad * sin( float( i ) * dTheta )
		);
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = 1.0 / 60.f;
	if (wnd.kbd.KeyIsPressed('Q'))
	{
		m_xRot = wrap_angle(m_xRot + dt * m_RotatorSpeed);
	}
	if (wnd.kbd.KeyIsPressed('W'))
	{
		m_yRot = wrap_angle(m_yRot + dt * m_RotatorSpeed);
	}
	if (wnd.kbd.KeyIsPressed('E'))
	{
		m_zRot = wrap_angle(m_zRot + dt * m_RotatorSpeed);
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		m_xRot = wrap_angle(m_xRot - dt * m_RotatorSpeed);
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		m_yRot = wrap_angle(m_yRot - dt * m_RotatorSpeed);
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		m_zRot = wrap_angle(m_zRot - dt * m_RotatorSpeed);
	}
	//ÎïÌåÔ¶½ü
	if (wnd.kbd.KeyIsPressed('R'))
	{
		m_zOffset = m_zOffset - dt * 1.f;
	}
	if (wnd.kbd.KeyIsPressed('F'))
	{
		m_zOffset = m_zOffset + dt * 1.f;
	}


	/*if( !wnd.kbd.KeyIsPressed( VK_SPACE ) )
	{
		theta += vRot;
	}*/
}

void Game::ComposeFrame()
{
	/*const Vec2 trl = { float( gfx.ScreenWidth ) / 2.0f,float( gfx.ScreenHeight ) / 2.0f };
	const Mat2 trf = Mat2::Rotation( theta ) * Mat2::Scaling( size );
	auto vtx( star );
	for( auto& v : vtx ) 
	{
		v *= trf;
		v += trl;
	}
	for( auto i = vtx.cbegin(),end = std::prev( vtx.cend() ); i != end; i++ )
	{
		gfx.DrawLine( *i,*std::next( i ),Colors::White );
	}
	gfx.DrawLine( vtx.front(),vtx.back(),Colors::White );*/

	IndexedLineList& lines = m_Cube.GetLines();
	const Mat3 Mat3Rot = !wnd.kbd.KeyIsPressed(VK_CONTROL) ?
		Mat3::RotationX(m_xRot) * Mat3::RotationY(m_yRot) * Mat3::RotationZ(m_zRot) : Mat3::RotationX(m_yRot) * Mat3::RotationY(m_zRot) * Mat3::RotationZ(m_xRot);
	for (auto& v : lines.vertices)
	{
		//TRS?
		v *= Mat3Rot;
		v+= {0.f,0.f, m_zOffset};

		m_pst.Transform(v);
	}
	
	for (auto i = lines.indices.cbegin(), j = lines.indices.cend(); i != j; std::advance(i, 2))
	{
		gfx.DrawLine(lines.vertices[*i],lines.vertices[*std::next(i)],Colors::White);
	}


}