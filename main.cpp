#include <raylib.h>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "OOP project"
#define DEFAULT_TEXT "Hello, OOP project..."
#define DEFAULT_TEXT_SIZE 30

int main()
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(0);
	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		const Vector2 text_size = MeasureTextEx(GetFontDefault(), DEFAULT_TEXT, DEFAULT_TEXT_SIZE, DEFAULT_TEXT_SIZE / 10);
		DrawText("Hello, OOP project...", GetScreenWidth() / 2 - static_cast<int>(text_size.x / 2), GetScreenHeight() / 2 - static_cast<int>(text_size.y / 2), DEFAULT_TEXT_SIZE, BLACK);
		EndDrawing();
	}
	return 0;
}
