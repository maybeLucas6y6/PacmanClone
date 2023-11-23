#include <iostream>
#include <raylib.h>
#include "Pacman.h"
#include "Screen.h"

int main() {
	const int rows = 36, cols = 28, cellSize = 16;

	InitWindow(cols * cellSize, rows * cellSize, "Pacman");
	ClearWindowState(FLAG_WINDOW_RESIZABLE);

	Pacman player("resources/pacman.png", MapToScreen({6, 1}));
	LoadMap("resources/tilemap.png");

	while (!WindowShouldClose()) {
		player.Move();
		player.Interact();

		BeginDrawing();
		ClearBackground(BLACK);

		RenderMap();

		player.Render(false);

		EndDrawing();
	}

	CloseWindow();
}