/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
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
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	frameTimer(),
	tileMap(gfx),
	player1({20, 20}, wnd.kbd, tileMap, 0, 'a', 'd', 'w', 's'),
	player2({40, 40}, wnd.kbd, tileMap, 1, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN)
{
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
	float dt = frameTimer.Mark();

	if (!isGameOver) //TODO: Make that you can reset and play again with the space bar if it is game over
	{
		isGameOver = player1.update(dt);
		isGameOver = player2.update(dt);
	}
}

void Game::ComposeFrame()
{
	if (!isGameOver)
		tileMap.draw();
	else
		SpriteCodex::DrawGameOver(gfx.ScreenWidth / 2, gfx.ScreenHeight / 2, gfx);
}
