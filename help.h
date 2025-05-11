#pragma once
#include <windows.h>


void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void myLine(int x1, int y1, int x2, int y2, int R, int G = 255, int B = 255) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
void myLineBold(int x1, int y1, int x2, int y2, int R, int G = 255, int B = 255) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 5, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
void myLineVar(int thickness, int x1, int y1, int x2, int y2, int R, int G = 255, int B = 255) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, thickness, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}

// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool HorizontalMovementCheck(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 2;		// 2 if right key is pressed
		return true;
	}
	return false;
}
bool VerticalMovementCheck(int& whichKey)
{
	char key;
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 1;		// 2 if up key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 2;		// 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(13);
	if (key == 1)
	{
		whichKey = 3;		//3 if Enter Key is pressed
		return true;
	}
	return false;
}
bool SpaceKeyCheck()
{
	char key;
	key = GetAsyncKeyState(32);
	if (key == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool EnterKeyCheck()
{
	char key;
	key = GetAsyncKeyState(13);
	if (key == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool EscapeKeyCheck()
{
	char key;
	key = GetAsyncKeyState(27);
	if (key == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool ShiftKeyCheck()
{
	char key;
	key = GetAsyncKeyState(16);
	if (key == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void myRect(int x1, int y1, int x2, int y2, int R, int G, int B, int fillR = 0, int fillG = 0, int fillB = 0)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(fillR, fillG, fillB)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myRectThin(int x1, int y1, int x2, int y2, int R, int G, int B, int fillR = 0, int fillG = 0, int fillB = 0)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(fillR, fillG, fillB)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B, int fillR = 0, int fillG = 0, int fillB = 0)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(fillR, fillG, fillB));  //Fill color is black by default
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int R, int G, int B, int fillR = 0, int fillG = 0, int fillB = 0)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	// Change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(fillR, fillG, fillB));  // Fill color is black by default
	SelectObject(device_context, brush);

	// Define the vertices of the triangle
	POINT triangleVertices[3] = {
		{x1, y1},
		{x2, y2},
		{x3, y3}
	};

	// Draw the triangle
	Polygon(device_context, triangleVertices, 3);

	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void drawShip(int x1, int y1, int size, int R = 255, int G = 255, int B = 255, int fillR = 255, int fillG = 255, int fillB = 255)
{
	double unit = size / 15.0;

	// The Ship Base
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(R, G, B));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(fillR, fillG, fillB));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the ship base
		POINT WhiteVertices[64] = {
			{x1 - 0.5 * unit, y1 - 7.5 * unit},
			{x1 + 0.5 * unit, y1 - 7.5 * unit},
			{x1 + 0.5 * unit, y1 - 5.5 * unit},
			{x1 + 1.5 * unit, y1 - 5.5 * unit},
			{x1 + 1.5 * unit, y1 - 1.5 * unit},
			{x1 + 2.5 * unit, y1 - 1.5 * unit},
			{x1 + 2.5 * unit, y1 + 0.5 * unit},
			{x1 + 3.5 * unit, y1 + 0.5 * unit},
			{x1 + 3.5 * unit, y1 - 1.5 * unit},
			{x1 + 4.5 * unit, y1 - 1.5 * unit},
			{x1 + 4.5 * unit, y1 + 0.5 * unit},
			{x1 + 3.5 * unit, y1 + 0.5 * unit},
			{x1 + 3.5 * unit, y1 + 1.5 * unit},
			{x1 + 4.5 * unit, y1 + 1.5 * unit},
			{x1 + 4.5 * unit, y1 + 2.5 * unit},
			{x1 + 5.5 * unit, y1 + 2.5 * unit},
			{x1 + 5.5 * unit, y1 + 3.5 * unit},
			{x1 + 6.5 * unit, y1 + 3.5 * unit},
			{x1 + 6.5 * unit, y1 + 1.5 * unit},
			{x1 + 7.5 * unit, y1 + 1.5 * unit},
			{x1 + 7.5 * unit, y1 + 7.5 * unit},

			{x1 + 6.5 * unit, y1 + 7.5 * unit},
			{x1 + 6.5 * unit, y1 + 6.5 * unit},
			{x1 + 5.5 * unit, y1 + 6.5 * unit},
			{x1 + 5.5 * unit, y1 + 5.5 * unit},
			{x1 + 4.5 * unit, y1 + 5.5 * unit},
			{x1 + 4.5 * unit, y1 + 4.5 * unit},
			{x1 + 2.5 * unit, y1 + 4.5 * unit},
			{x1 + 2.5 * unit, y1 + 3.5 * unit},
			{x1 + 1.5 * unit, y1 + 3.5 * unit},
			{x1 + 1.5 * unit, y1 + 5.5 * unit},
			{x1 + 0.5 * unit, y1 + 5.5 * unit},

			{x1 + 0.5 * unit, y1 + 7.5 * unit},
			{x1 - 0.5 * unit, y1 + 7.5 * unit},

			{x1 - 0.5 * unit, y1 + 5.5 * unit},
			{x1 - 1.5 * unit, y1 + 5.5 * unit},
			{x1 - 1.5 * unit, y1 + 3.5 * unit},
			{x1 - 2.5 * unit, y1 + 3.5 * unit},
			{x1 - 2.5 * unit, y1 + 4.5 * unit},
			{x1 - 4.5 * unit, y1 + 4.5 * unit},
			{x1 - 4.5 * unit, y1 + 5.5 * unit},
			{x1 - 5.5 * unit, y1 + 5.5 * unit},
			{x1 - 5.5 * unit, y1 + 6.5 * unit},
			{x1 - 6.5 * unit, y1 + 6.5 * unit},
			{x1 - 6.5 * unit, y1 + 7.5 * unit},

			{x1 - 7.5 * unit, y1 + 7.5 * unit},
			{x1 - 7.5 * unit, y1 + 1.5 * unit},
			{x1 - 6.5 * unit, y1 + 1.5 * unit},
			{x1 - 6.5 * unit, y1 + 3.5 * unit},
			{x1 - 5.5 * unit, y1 + 3.5 * unit},
			{x1 - 5.5 * unit, y1 + 2.5 * unit},
			{x1 - 4.5 * unit, y1 + 2.5 * unit},
			{x1 - 4.5 * unit, y1 + 1.5 * unit},
			{x1 - 3.5 * unit, y1 + 1.5 * unit},
			{x1 - 3.5 * unit, y1 + 0.5 * unit},
			{x1 - 4.5 * unit, y1 + 0.5 * unit},
			{x1 - 4.5 * unit, y1 - 1.5 * unit},
			{x1 - 3.5 * unit, y1 - 1.5 * unit},
			{x1 - 3.5 * unit, y1 + 0.5 * unit},
			{x1 - 2.5 * unit, y1 + 0.5 * unit},
			{x1 - 2.5 * unit, y1 - 1.5 * unit},
			{x1 - 1.5 * unit, y1 - 1.5 * unit},
			{x1 - 1.5 * unit, y1 - 5.5 * unit},
			{x1 - 0.5 * unit, y1 - 5.5 * unit}
		};

		// Draw the ship base
		Polygon(device_context, WhiteVertices, 64);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// The Red Window
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(204, 65, 58));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(204, 65, 58));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the red window on top
		POINT RedWindow[12] = {
			{x1 - 0.5 * unit, y1 - 0.5 * unit},
			{x1 + 0.5 * unit, y1 - 0.5 * unit},
			{x1 + 0.5 * unit, y1 + 0.5 * unit},
			{x1 + 1.5 * unit, y1 + 0.5 * unit},
			{x1 + 1.5 * unit, y1 + 2.5 * unit},
			{x1 + 0.5 * unit, y1 + 2.5 * unit},
			{x1 + 0.5 * unit, y1 + 1.5 * unit},
			{x1 - 0.5 * unit, y1 + 1.5 * unit},
			{x1 - 0.5 * unit, y1 + 2.5 * unit},
			{x1 - 1.5 * unit, y1 + 2.5 * unit},
			{x1 - 1.5 * unit, y1 + 0.5 * unit},
			{x1 - 0.5 * unit, y1 + 0.5 * unit},
		};

		// Draw the ship bared window
		Polygon(device_context, RedWindow, 12);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// The Red Back Wings 1
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(204, 65, 58));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(204, 65, 58));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the back red wings
		POINT RedBackWings[6] = {
			{x1 - 2.5 * unit, y1 + 3.5 * unit},
			{x1 - 1.5 * unit, y1 + 3.5 * unit},
			{x1 - 1.5 * unit, y1 + 6.5 * unit},
			{x1 - 3.5 * unit, y1 + 6.5 * unit},
			{x1 - 3.5 * unit, y1 + 4.5 * unit},
			{x1 - 2.5 * unit, y1 + 4.5 * unit}
		};

		// Draw the back red wings
		Polygon(device_context, RedBackWings, 6);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// The Red Back Wings 2
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(204, 65, 58));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(204, 65, 58));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the back red wings
		POINT RedBackWings[6] = {
			{x1 + 2.5 * unit, y1 + 3.5 * unit},
			{x1 + 1.5 * unit, y1 + 3.5 * unit},
			{x1 + 1.5 * unit, y1 + 6.5 * unit},
			{x1 + 3.5 * unit, y1 + 6.5 * unit},
			{x1 + 3.5 * unit, y1 + 4.5 * unit},
			{x1 + 2.5 * unit, y1 + 4.5 * unit}
		};

		// Draw the back red wings
		Polygon(device_context, RedBackWings, 6);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// Blue Part 1
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(80, 113, 164));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(80, 113, 164));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the BluePart
		POINT BluePart[8] = {
			{x1 - 3.5 * unit, y1 - 0.5 * unit},
			{x1 - 2.5 * unit, y1 - 0.5 * unit},
			{x1 - 2.5 * unit, y1 + 0.5 * unit},
			{x1 - 3.5 * unit, y1 + 0.5 * unit},
			{x1 - 3.5 * unit, y1 + 1.5 * unit},
			{x1 - 4.5 * unit, y1 + 1.5 * unit},
			{x1 - 4.5 * unit, y1 + 0.5 * unit},
			{x1 - 3.5 * unit, y1 + 0.5 * unit}
		};

		// Draw the BluePart
		Polygon(device_context, BluePart, 8);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// Blue Part 2
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(80, 113, 164));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(80, 113, 164));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the BluePart
		POINT BluePart[8] = {
			{x1 + 3.5 * unit, y1 - 0.5 * unit},
			{x1 + 2.5 * unit, y1 - 0.5 * unit},
			{x1 + 2.5 * unit, y1 + 0.5 * unit},
			{x1 + 3.5 * unit, y1 + 0.5 * unit},
			{x1 + 3.5 * unit, y1 + 1.5 * unit},
			{x1 + 4.5 * unit, y1 + 1.5 * unit},
			{x1 + 4.5 * unit, y1 + 0.5 * unit},
			{x1 + 3.5 * unit, y1 + 0.5 * unit}
		};

		// Draw the BluePart
		Polygon(device_context, BluePart, 8);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// Turrets Mean 1
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(204, 65, 58));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(204, 65, 58));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the TurretsMean
		POINT TurretsMean[4] = {
			{x1 - 4.5 * unit, y1 - 3.5 * unit},
			{x1 - 3.5 * unit, y1 - 3.5 * unit},
			{x1 - 3.5 * unit, y1 - 1.5 * unit},
			{x1 - 4.5 * unit, y1 - 1.5 * unit}
		};

		// Draw the TurretsMean
		Polygon(device_context, TurretsMean, 4);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// Turrets Mean 2
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(204, 65, 58));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(204, 65, 58));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the TurretsMean
		POINT TurretsMean[4] = {
			{x1 + 4.5 * unit, y1 - 3.5 * unit},
			{x1 + 3.5 * unit, y1 - 3.5 * unit},
			{x1 + 3.5 * unit, y1 - 1.5 * unit},
			{x1 + 4.5 * unit, y1 - 1.5 * unit}
		};

		// Draw the TurretsMean
		Polygon(device_context, TurretsMean, 4);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// Turrets Extreme 1
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(204, 65, 58));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(204, 65, 58));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the TurretsExtreme
		POINT TurretsExtreme[4] = {
			{x1 - 7.5 * unit, y1 - 0.5 * unit},
			{x1 - 6.5 * unit, y1 - 0.5 * unit},
			{x1 - 6.5 * unit, y1 + 1.5 * unit},
			{x1 - 7.5 * unit, y1 + 1.5 * unit}
		};

		// Draw the TurretsExtreme
		Polygon(device_context, TurretsExtreme, 4);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// Turrets Extreme 2
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(204, 65, 58));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(204, 65, 58));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the TurretsExtreme
		POINT TurretsExtreme[4] = {
			{x1 + 7.5 * unit, y1 - 0.5 * unit},
			{x1 + 6.5 * unit, y1 - 0.5 * unit},
			{x1 + 6.5 * unit, y1 + 1.5 * unit},
			{x1 + 7.5 * unit, y1 + 1.5 * unit}
		};

		// Draw the TurretsExtreme
		Polygon(device_context, TurretsExtreme, 4);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
}
void removeShip(int x1, int y1, int size, int color = 0)
{
	double unit = size / 15.0;

	myRect(x1 - 8 * unit, y1 - 8 * unit, x1 + 8 * unit, y1 + 8 * unit, color, color, color, color, color, color);
}

void drawAlienType1(int x1, int y1, int size)
{
	double unit = size / 20.0;

	// The Alien Body
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(45, 68, 255));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(45, 68, 255));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the AlienBody
		POINT AlienBody[12] = {
			{x1 - 3 * unit, y1 - 7 * unit},
			{x1 + 3 * unit, y1 - 7 * unit},
			{x1 + 3 * unit, y1 - 5 * unit},
			{x1 + 5 * unit, y1 - 5 * unit},
			{x1 + 5 * unit, y1 - 3 * unit},
			{x1 + 7 * unit, y1 - 3 * unit},
			{x1 + 7 * unit, y1 + 5 * unit},
			{x1 - 7 * unit, y1 + 5 * unit},
			{x1 - 7 * unit, y1 - 3 * unit},
			{x1 - 5 * unit, y1 - 3 * unit},
			{x1 - 5 * unit, y1 - 5 * unit},
			{x1 - 3 * unit, y1 - 5 * unit},
		};

		// Draw the ship bared window
		Polygon(device_context, AlienBody, 12);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	myRect(x1 - 9 * unit, y1 - 5 * unit, x1 - 7 * unit, y1 - 1 * unit, 38, 63, 205, 38, 63, 205); // Ears
	myRect(x1 + 9 * unit, y1 - 5 * unit, x1 + 7 * unit, y1 - 1 * unit, 38, 63, 205, 38, 63, 205);

	myRect(x1 - 7 * unit, y1 + 5 * unit, x1 - 5 * unit, y1 + 7 * unit, 38, 63, 205, 38, 63, 205); // Tentacles
	myRect(x1 - 3 * unit, y1 + 5 * unit, x1 - 1 * unit, y1 + 7 * unit, 38, 63, 205, 38, 63, 205);
	myRect(x1 + 1 * unit, y1 + 5 * unit, x1 + 3 * unit, y1 + 7 * unit, 38, 63, 205, 38, 63, 205);
	myRect(x1 + 5 * unit, y1 + 5 * unit, x1 + 7 * unit, y1 + 7 * unit, 38, 63, 205, 38, 63, 205);

	myRect(x1 - 5 * unit, y1 - 3 * unit, x1 - 1 * unit, y1 + 3 * unit, 255, 255, 255, 255, 255, 255); // Ey1es
	myRect(x1 + 1 * unit, y1 - 3 * unit, x1 + 5 * unit, y1 + 3 * unit, 255, 255, 255, 255, 255, 255);

	myRect(x1 - 3 * unit, y1 - 1 * unit, x1 - 5 * unit, y1 + 1 * unit, 253, 53, 55, 253, 53, 55); // Pupils
	myRect(x1 + 1 * unit, y1 - 1 * unit, x1 + 3 * unit, y1 + 1 * unit, 253, 53, 55, 253, 53, 55);
}
void removeAlienType1(int x1, int y1, int size, int color = 0)
{
	double unit = size / 20.0;

	myRect(x1 - 10 * unit, y1 - 10 * unit, x1 + 10 * unit, y1 + 10 * unit, color, color, color, color, color, color);
}

void drawAlienType2(int x1, int y1, int size)
{
	double unit = size / 20.0;

	// Fire Head
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(234, 255, 66));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(234, 255, 66));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the AlienBody
		POINT AlienBody[12] = {
			{x1 - 1 * unit, y1 - 8 * unit},
			{x1 + 1 * unit, y1 - 8 * unit},

			{x1 + 1 * unit, y1 - 6 * unit},
			{x1 + 3 * unit, y1 - 6 * unit},
			{x1 + 3 * unit, y1 - 4 * unit},
			{x1 + 5 * unit, y1 - 4 * unit},

			{x1 + 5 * unit, y1 - 2 * unit},
			{x1 - 5 * unit, y1 - 2 * unit},

			{x1 - 5 * unit, y1 - 4 * unit},
			{x1 - 3 * unit, y1 - 4 * unit},
			{x1 - 3 * unit, y1 - 6 * unit},
			{x1 - 1 * unit, y1 - 6 * unit},
		};

		// Draw the ship bared window
		Polygon(device_context, AlienBody, 12);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// The Alien Body
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 49, 49));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(255, 49, 49));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the AlienBody
		POINT AlienBody[12] = {
			{x1 - 1 * unit, y1 - 6 * unit},
			{x1 + 1 * unit, y1 - 6 * unit},

			{x1 + 1 * unit, y1 - 4 * unit},
			{x1 + 3 * unit, y1 - 4 * unit},
			{x1 + 3 * unit, y1 - 2 * unit},
			{x1 + 7 * unit, y1 - 2 * unit},

			{x1 + 7 * unit, y1 + 4 * unit},
			{x1 - 7 * unit, y1 + 4 * unit},

			{x1 - 7 * unit, y1 - 2 * unit},
			{x1 - 3 * unit, y1 - 2 * unit},
			{x1 - 3 * unit, y1 - 4 * unit},
			{x1 - 1 * unit, y1 - 4 * unit},
		};

		// Draw the ship bared window
		Polygon(device_context, AlienBody, 12);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// Ears and Tentacles
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(184, 46, 46));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(184, 46, 46));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the AlienBody
		POINT AlienBody[24] = {
			{x1 - 7 * unit, y1 + 4 * unit},
			{x1 + 7 * unit, y1 + 4 * unit},

			{x1 + 7 * unit, y1 + 0 * unit},
			{x1 + 9 * unit, y1 + 0 * unit},
			{x1 + 9 * unit, y1 + 4 * unit},
			{x1 + 7 * unit, y1 + 4 * unit},

			{x1 + 7 * unit, y1 + 6 * unit},
			{x1 + 5 * unit, y1 + 6 * unit},
			{x1 + 5 * unit, y1 + 8 * unit},
			{x1 + 3 * unit, y1 + 8 * unit},
			{x1 + 3 * unit, y1 + 6 * unit},

			{x1 + 1 * unit, y1 + 6 * unit},
			{x1 + 1 * unit, y1 + 8 * unit},
			{x1 - 1 * unit, y1 + 8 * unit},
			{x1 - 1 * unit, y1 + 6 * unit},

			{x1 - 3 * unit, y1 + 6 * unit},
			{x1 - 3 * unit, y1 + 8 * unit},
			{x1 - 5 * unit, y1 + 8 * unit},
			{x1 - 5 * unit, y1 + 6 * unit},
			{x1 - 7 * unit, y1 + 6 * unit},

			{x1 - 7 * unit, y1 + 4 * unit},
			{x1 - 9 * unit, y1 + 4 * unit},
			{x1 - 9 * unit, y1 + 0 * unit},
			{x1 - 7 * unit, y1 + 0 * unit}
		};

		// Draw the ship bared window
		Polygon(device_context, AlienBody, 24);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// The rest
	myRect(x1 - 7 * unit, y1 + 0 * unit, x1 - 5 * unit, y1 + 4 * unit, 35, 44, 43, 35, 44, 43); // Eyes
	myRect(x1 + 7 * unit, y1 + 0 * unit, x1 + 5 * unit, y1 + 4 * unit, 35, 44, 43, 35, 44, 43);

	myRect(x1 - 1 * unit, y1 + 2 * unit, x1 + 1 * unit, y1 + 4 * unit, 35, 44, 43, 35, 44, 43); //Nose
}
void removeAlienType2(int x1, int y1, int size, int color = 0)
{
	double unit = size / 20.0;

	myRect(x1 - 10 * unit, y1 - 10 * unit, x1 + 10 * unit, y1 + 10 * unit, color, color, color, color, color, color);
}

void drawAlienType3(int x1, int y1, int size)
{
	double unit = size / 20.0;

	// Tips
	myRectThin(x1 - 9.9 * unit, y1 + 6 * unit, x1 - 8 * unit, y1 + 8 * unit, 255, 46, 53, 255, 46, 53);
	myRectThin(x1 - 4 * unit, y1 + 6 * unit, x1 - 2 * unit, y1 + 8 * unit, 255, 46, 53, 255, 46, 53);
	myRectThin(x1 - 1 * unit, y1 + 6 * unit, x1 + 1 * unit, y1 + 8 * unit, 255, 46, 53, 255, 46, 53);
	myRectThin(x1 + 4 * unit, y1 + 6 * unit, x1 + 2 * unit, y1 + 8 * unit, 255, 46, 53, 255, 46, 53);
	myRectThin(x1 + 9.9 * unit, y1 + 6 * unit, x1 + 8 * unit, y1 + 8 * unit, 255, 46, 53, 255, 46, 53);
	// Head and Ears
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 46, 53));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(255, 46, 53));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the AlienBody
		POINT AlienBody[12] = {
			{x1 - 3 * unit, y1 - 6 * unit},
			{x1 + 3 * unit, y1 - 6 * unit},

			{x1 + 3 * unit, y1 - 8 * unit},
			{x1 + 5 * unit, y1 - 8 * unit},
			{x1 + 5 * unit, y1 - 2 * unit},
			{x1 + 9.9 * unit, y1 - 2 * unit},

			{x1 + 9.9 * unit, y1 - 0 * unit},
			{x1 - 9.9 * unit, y1 - 0 * unit},

			{x1 - 9.9 * unit, y1 - 2 * unit},
			{x1 - 5 * unit, y1 - 2 * unit},
			{x1 - 5 * unit, y1 - 8 * unit},
			{x1 - 3 * unit, y1 - 8 * unit}
		};

		// Draw the ship bared window
		Polygon(device_context, AlienBody, 12);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// Main Body
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(43, 243, 241));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(43, 243, 241));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the AlienBody
		POINT AlienBody[12] = {
			{x1 - 3 * unit, y1 - 4 * unit},
			{x1 + 3 * unit, y1 - 4 * unit},

			{x1 + 3 * unit, y1 - 6 * unit},
			{x1 + 7 * unit, y1 - 6 * unit},
			{x1 + 7 * unit, y1 - 4 * unit},
			{x1 + 8 * unit, y1 - 4 * unit},

			{x1 + 8 * unit, y1 + 2 * unit},
			{x1 - 8 * unit, y1 + 2 * unit},

			{x1 - 8 * unit, y1 - 4 * unit},
			{x1 - 7 * unit, y1 - 4 * unit},
			{x1 - 7 * unit, y1 - 6 * unit},
			{x1 - 3 * unit, y1 - 6 * unit}
		};

		// Draw the ship bared window
		Polygon(device_context, AlienBody, 12);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// MBottom and Tentacles
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(49, 210, 218));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(49, 210, 218));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the AlienBody
		POINT AlienBody[24] = {
			{x1 - 6 * unit, y1 + 2 * unit},
			{x1 + 6 * unit, y1 + 2 * unit},

			{x1 + 6 * unit, y1 + 4 * unit},

			{x1 + 8 * unit, y1 + 4 * unit},
			{x1 + 8 * unit, y1 + 8 * unit},
			{x1 + 6 * unit, y1 + 8 * unit},
			{x1 + 6 * unit, y1 + 4 * unit},

			{x1 + 4 * unit, y1 + 4 * unit},

			{x1 + 4 * unit, y1 + 6 * unit},
			{x1 + 2 * unit, y1 + 6 * unit},
			{x1 + 2 * unit, y1 + 4 * unit},

			{x1 + 1 * unit, y1 + 4 * unit},

			{x1 + 1 * unit, y1 + 6 * unit},
			{x1 - 1 * unit, y1 + 6 * unit},
			{x1 - 1 * unit, y1 + 4 * unit},

			{x1 - 2 * unit, y1 + 4 * unit},

			{x1 - 2 * unit, y1 + 6 * unit},
			{x1 - 4 * unit, y1 + 6 * unit},
			{x1 - 4 * unit, y1 + 4 * unit},

			{x1 - 6 * unit, y1 + 4 * unit},
			{x1 - 6 * unit, y1 + 8 * unit},
			{x1 - 8 * unit, y1 + 8 * unit},
			{x1 - 8 * unit, y1 + 4 * unit},

			{x1 - 6 * unit, y1 + 4 * unit}
		};

		// Draw the ship bared window
		Polygon(device_context, AlienBody, 24);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// Eye Patch 1
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(255, 255, 255));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the AlienBody
		POINT AlienBody[8] = {
			{x1 - 6 * unit, y1 - 2 * unit},
			{x1 - 1 * unit, y1 - 2 * unit},

			{x1 - 1 * unit, y1 + 0 * unit},
			{x1 - 2 * unit, y1 + 0 * unit},
			{x1 - 2 * unit, y1 + 2 * unit},
			{x1 - 4 * unit, y1 + 2 * unit},

			{x1 - 4 * unit, y1 + 0 * unit},
			{x1 - 6 * unit, y1 + 0 * unit}
		};

		// Draw the ship bared window
		Polygon(device_context, AlienBody, 8);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// Eye Patch 1
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);

		// Change the color by changing the values in RGB (from 0-255)
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
		SelectObject(device_context, pen);
		HBRUSH brush = ::CreateSolidBrush(RGB(255, 255, 255));  // Fill color is black by default
		SelectObject(device_context, brush);

		// Define the vertices of the AlienBody
		POINT AlienBody[8] = {
			{x1 + 6 * unit, y1 - 2 * unit},
			{x1 + 1 * unit, y1 - 2 * unit},

			{x1 + 1 * unit, y1 + 0 * unit},
			{x1 + 2 * unit, y1 + 0 * unit},
			{x1 + 2 * unit, y1 + 2 * unit},
			{x1 + 4 * unit, y1 + 2 * unit},

			{x1 + 4 * unit, y1 + 0 * unit},
			{x1 + 6 * unit, y1 + 0 * unit}
		};

		// Draw the ship bared window
		Polygon(device_context, AlienBody, 8);

		ReleaseDC(console_handle, device_context);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	// Pupils
	myRectThin(x1 - 4 * unit, y1 - 2 * unit, x1 - 2 * unit, y1 + 0 * unit, 255, 46, 53, 255, 46, 53);
	myRectThin(x1 + 4 * unit, y1 - 2 * unit, x1 + 2 * unit, y1 + 0 * unit, 255, 46, 53, 255, 46, 53);
}
void removeAlienType3(int x1, int y1, int size, int color = 0)
{
	double unit = size / 20.0;

	myRect(x1 - 10 * unit, y1 - 10 * unit, x1 + 10 * unit, y1 + 10 * unit, color, color, color, color, color, color);
}

void lettersnNumbers(char chr, int x1, int x2, int y1, int y2, int size, int R = 0, int G = 0, int B = 0) {
	x1 += 5;
	x2 -= 5;
	y1 += 5;
	y2 -= 5;
	int mid_x = (x1 + x2) / 2;
	int mid_y = (y1 + y2) / 2;

	if (chr == 'A') {
		myLine(mid_x, y1, x1, y2, R, G, B);
		myLine(mid_x, y1, x2, y2, R, G, B);
		myLine(x1 + 2, mid_y + size / 2, x2 - 3, mid_y + size / 2, R, G, B);
	}
	else if (chr == 'B') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
		myLine(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
		myLine(x1, mid_y, mid_x, mid_y, R, G, B);
		myLine(mid_x, mid_y, x2, mid_y + size / 4, R, G, B);
		myLine(x2, mid_y + size / 4, mid_x + size / 8, y2, R, G, B);
		myLine(mid_x + size / 8, y2, x1, y2, R, G, B);
	}
	else if (chr == 'C') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y1, x2, y1 + size / 4, R, G, B);
		myLine(x2, y2, x2, y2 - size / 4, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'D') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, mid_x + size / 4, y1 + size / 4, R, G, B);
		myLine(mid_x + size / 4, y1 + size / 4, mid_x + size / 4, y2 - size / 4, R, G, B);
		myLine(mid_x + size / 4, y2 - size / 4, x1, y2, R, G, B);
	}
	else if (chr == 'E') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'F') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
	}
	else if (chr == 'G') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y1, x2, y1 + size / 4, R, G, B);
		myLine(x2, y2, x2, y2 - size / 2, R, G, B);
		myLine(x2, y2 - size / 2, mid_x, y2 - size / 2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'H') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
	}
	else if (chr == 'I') {
		myLine(mid_x, y1, mid_x, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'J') {
		myLine(x2, y1, x2, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y2, x1, y2, R, G, B);
		myLine(x1, y2, x1, y2 - size / 2, R, G, B);
	}
	else if (chr == 'K') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, mid_y, x2, y1, R, G, B);
		myLine(x1, mid_y, x2, y2, R, G, B);
	}
	else if (chr == 'L') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'M') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, mid_x, mid_y, R, G, B);
		myLine(mid_x, mid_y, x2, y1, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
	}
	else if (chr == 'N') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, x2, y2, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
	}
	else if (chr == 'O') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
	}
	else if (chr == 'P') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
		myLine(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
		myLine(x1, mid_y, mid_x, mid_y, R, G, B);

	}
	else if (chr == 'Q') {
		myLine(x1, y1, x1, y2 - 5, R, G, B);
		myLine(x1, y1, mid_x + 3, y1, R, G, B);
		myLine(mid_x + 3, y1, mid_x + 3, y2 - 5, R, G, B);
		myLine(x1, y2 - 5, mid_x + 3, y2 - 5, R, G, B);
		myLine(mid_x - 2, mid_y, mid_x + 3, y2 - 5, R, G, B);
		myLine(mid_x + 3, y2 - 5, x2, y2, R, G, B);
	}
	else if (chr == 'R') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
		myLine(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
		myLine(x1, mid_y, mid_x, mid_y, R, G, B);
		myLine(mid_x, mid_y, x2, y2, R, G, B);
	}
	else if (chr == 'S') {
		myLine(mid_x, y1, x2, y1 + size / 2, R, G, B);
		myLine(mid_x, y1, x1, y1 + size / 2, R, G, B);
		myLine(x1, y1 + size / 2, x2, y2 - size / 2, R, G, B);
		myLine(x2, y2 - size / 2, mid_x, y2, R, G, B);
		myLine(mid_x, y2, x1, y2 - size / 2, R, G, B);
	}
	else if (chr == 'T') {
		myLine(mid_x, y1, mid_x, y2, R, G, B);
		myLine(x1, y1, x2, y1, R, G, B);
	}
	else if (chr == 'U') {
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);

	}
	else if (chr == 'V') {
		myLine(x1, y1, mid_x, y2, R, G, B);
		myLine(mid_x, y2, x2, y1, R, G, B);
	}
	else if (chr == 'W') {
		myLine(x1, y1, mid_x - size / 8, y2, R, G, B);
		myLine(mid_x - size / 8, y2, mid_x, mid_y, R, G, B);
		myLine(mid_x, mid_y, mid_x + size / 8, y2, R, G, B);
		myLine(mid_x + size / 8, y2, x2, y1, R, G, B);
	}
	else if (chr == 'X') {
		myLine(x1, y1, x2, y2, R, G, B);
		myLine(x2, y1, x1, y2, R, G, B);

	}
	else if (chr == 'Y') {
		myLine(x1, y1, mid_x, mid_y, R, G, B);
		myLine(x2, y1, x1, y2, R, G, B);
	}
	else if (chr == 'Z') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y1, x1, y2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == '.') {
		myRect(x2, y2 - size / 8, mid_x + size / 4, y2, R, G, B);
	}
	else if (chr == ',') {
		myRect(x2, y2 - size / 3, mid_x + size / 4, y2 - size / 6, R, G, B);
		myLine(x2, y2 - size / 3, x2, y2, R);
		myLine(x2, y2, mid_x + size / 4, y2, R);
	}
	else if (chr == '!') {
		myRect(mid_x - size / 8, y1, mid_x - 1, y2 - size / 3, R, G, B);
		myRect(mid_x - size / 8, y2 - size / 8, mid_x, y2, R, G, B);
	}
	else if (chr == ':') {
		myRect(x2, y2 - 20, mid_x + size / 4, y2 - 16, R, G, B);
		myRect(x2, y2 - 4, mid_x + size / 4, y2, R, G, B);
	}
	else if (chr == '0') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
		myLine(x2, y1, x1, y2, R, G, B);
	}
	else if (chr == '1') {
		myLine(x1, mid_y - size / 2, mid_x, y1, R, G, B);
		myLine(mid_x, y1, mid_x, y2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == '2') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y1, x2, mid_y, R, G, B);
		myLine(x2, mid_y, x1, mid_y, R, G, B);
		myLine(x1, mid_y, x1, y2, R, G, B);
		myLine(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == '3') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y1, x2, mid_y, R, G, B);
		myLine(x2, mid_y, x1, mid_y, R, G, B);
		myLine(x2, mid_y, x2, y2, R, G, B);
		myLine(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '4') {
		myLine(x1, y1, x1, mid_y, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
		myLine(mid_x + size / 6, y1, mid_x + size / 6, y2, R, G, B);
	}
	else if (chr == '5') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y1, x1, mid_y, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
		myLine(x2, mid_y, x2, y2, R, G, B);
		myLine(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '6') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
		myLine(x2, mid_y, x2, y2, R, G, B);
		myLine(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '7') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
	}
	else if (chr == '8') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y1, x1, y2, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
		myLine(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '9') {
		myLine(x1, y1, x2, y1, R, G, B);
		myLine(x1, y1, x1, mid_y, R, G, B);
		myLine(x1, mid_y, x2, mid_y, R, G, B);
		myLine(x2, y1, x2, y2, R, G, B);
		myLine(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '-')
		myRect(x1 - 5, y1 - 5, x2 + 5, y2 + 5, 0, 0, 0);
}
void lettersnNumbersBold(char chr, int x1, int x2, int y1, int y2, int size, int R = 0, int G = 0, int B = 0) {
	x1 += 5;
	x2 -= 5;
	y1 += 5;
	y2 -= 5;
	int mid_x = (x1 + x2) / 2;
	int mid_y = (y1 + y2) / 2;

	if (chr == 'A') {
		myLineBold(mid_x, y1, x1, y2, R, G, B);
		myLineBold(mid_x, y1, x2, y2, R, G, B);
		myLineBold(x1 + 2, mid_y + size / 2, x2 - 3, mid_y + size / 2, R, G, B);
	}
	else if (chr == 'B') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
		myLineBold(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
		myLineBold(x1, mid_y, mid_x, mid_y, R, G, B);
		myLineBold(mid_x, mid_y, x2, mid_y + size / 4, R, G, B);
		myLineBold(x2, mid_y + size / 4, mid_x + size / 8, y2, R, G, B);
		myLineBold(mid_x + size / 8, y2, x1, y2, R, G, B);
	}
	else if (chr == 'C') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x2, y1, x2, y1 + size / 4, R, G, B);
		myLineBold(x2, y2, x2, y2 - size / 4, R, G, B);
		myLineBold(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'D') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y1, mid_x + size / 4, y1 + size / 4, R, G, B);
		myLineBold(mid_x + size / 4, y1 + size / 4, mid_x + size / 4, y2 - size / 4, R, G, B);
		myLineBold(mid_x + size / 4, y2 - size / 4, x1, y2, R, G, B);
	}
	else if (chr == 'E') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x1, mid_y, x2, mid_y, R, G, B);
		myLineBold(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'F') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x1, mid_y, x2, mid_y, R, G, B);
	}
	else if (chr == 'G') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x2, y1, x2, y1 + size / 4, R, G, B);
		myLineBold(x2, y2, x2, y2 - size / 2, R, G, B);
		myLineBold(x2, y2 - size / 2, mid_x, y2 - size / 2, R, G, B);
		myLineBold(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'H') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x2, y1, x2, y2, R, G, B);
		myLineBold(x1, mid_y, x2, mid_y, R, G, B);
	}
	else if (chr == 'I') {
		myLineBold(mid_x, y1, mid_x, y2, R, G, B);
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'J') {
		myLineBold(x2, y1, x2, y2, R, G, B);
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x2, y2, x1, y2, R, G, B);
		myLineBold(x1, y2, x1, y2 - size / 2, R, G, B);
	}
	else if (chr == 'K') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, mid_y, x2, y1, R, G, B);
		myLineBold(x1, mid_y, x2, y2, R, G, B);
	}
	else if (chr == 'L') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'M') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y1, mid_x, mid_y, R, G, B);
		myLineBold(mid_x, mid_y, x2, y1, R, G, B);
		myLineBold(x2, y1, x2, y2, R, G, B);
	}
	else if (chr == 'N') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y1, x2, y2, R, G, B);
		myLineBold(x2, y1, x2, y2, R, G, B);
	}
	else if (chr == 'O') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x1, y2, x2, y2, R, G, B);
		myLineBold(x2, y1, x2, y2, R, G, B);
	}
	else if (chr == 'P') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
		myLineBold(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
		myLineBold(x1, mid_y, mid_x, mid_y, R, G, B);

	}
	else if (chr == 'Q') {
		myLineBold(x1, y1, x1, y2 - 5, R, G, B);
		myLineBold(x1, y1, mid_x + 3, y1, R, G, B);
		myLineBold(mid_x + 3, y1, mid_x + 3, y2 - 5, R, G, B);
		myLineBold(x1, y2 - 5, mid_x + 3, y2 - 5, R, G, B);
		myLineBold(mid_x - 2, mid_y, mid_x + 3, y2 - 5, R, G, B);
		myLineBold(mid_x + 3, y2 - 5, x2, y2, R, G, B);
	}
	else if (chr == 'R') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
		myLineBold(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
		myLineBold(x1, mid_y, mid_x, mid_y, R, G, B);
		myLineBold(mid_x, mid_y, x2, y2, R, G, B);
	}
	else if (chr == 'S') {
		myLineBold(mid_x, y1, x2, y1 + size / 2, R, G, B);
		myLineBold(mid_x, y1, x1, y1 + size / 2, R, G, B);
		myLineBold(x1, y1 + size / 2, x2, y2 - size / 2, R, G, B);
		myLineBold(x2, y2 - size / 2, mid_x, y2, R, G, B);
		myLineBold(mid_x, y2, x1, y2 - size / 2, R, G, B);
	}
	else if (chr == 'T') {
		myLineBold(mid_x, y1, mid_x, y2, R, G, B);
		myLineBold(x1, y1, x2, y1, R, G, B);
	}
	else if (chr == 'U') {
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, y2, x2, y2, R, G, B);
		myLineBold(x2, y1, x2, y2, R, G, B);

	}
	else if (chr == 'V') {
		myLineBold(x1, y1, mid_x, y2, R, G, B);
		myLineBold(mid_x, y2, x2, y1, R, G, B);
	}
	else if (chr == 'W') {
		myLineBold(x1, y1, mid_x - size / 8, y2, R, G, B);
		myLineBold(mid_x - size / 8, y2, mid_x, mid_y, R, G, B);
		myLineBold(mid_x, mid_y, mid_x + size / 8, y2, R, G, B);
		myLineBold(mid_x + size / 8, y2, x2, y1, R, G, B);
	}
	else if (chr == 'X') {
		myLineBold(x1, y1, x2, y2, R, G, B);
		myLineBold(x2, y1, x1, y2, R, G, B);

	}
	else if (chr == 'Y') {
		myLineBold(x1, y1, mid_x, mid_y, R, G, B);
		myLineBold(x2, y1, x1, y2, R, G, B);
	}
	else if (chr == 'Z') {
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x2, y1, x1, y2, R, G, B);
		myLineBold(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == '.') {
		myRect(x2, y2 - size / 8, mid_x + size / 4, y2, R, G, B);
	}
	else if (chr == ',') {
		myRect(x2, y2 - size / 3, mid_x + size / 4, y2 - size / 6, R, G, B);
		myLineBold(x2, y2 - size / 3, x2, y2, R);
		myLineBold(x2, y2, mid_x + size / 4, y2, R);
	}
	else if (chr == '!') {
		myRect(mid_x - size / 8, y1, mid_x - 1, y2 - size / 3, R, G, B);
		myRect(mid_x - size / 8, y2 - size / 8, mid_x, y2, R, G, B);
	}
	else if (chr == ':') {
		myRect(x2, y2 - 20, mid_x + size / 4, y2 - 16, R, G, B);
		myRect(x2, y2 - 4, mid_x + size / 4, y2, R, G, B);
	}
	else if (chr == '0') {
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x2, y1, x2, y2, R, G, B);
		myLineBold(x1, y2, x2, y2, R, G, B);
		myLineBold(x2, y1, x1, y2, R, G, B);
	}
	else if (chr == '1') {
		myLineBold(x1, mid_y - size / 2, mid_x, y1, R, G, B);
		myLineBold(mid_x, y1, mid_x, y2, R, G, B);
		myLineBold(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == '2') {
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x2, y1, x2, mid_y, R, G, B);
		myLineBold(x2, mid_y, x1, mid_y, R, G, B);
		myLineBold(x1, mid_y, x1, y2, R, G, B);
		myLineBold(x1, y2, x2, y2, R, G, B);
	}
	else if (chr == '3') {
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x2, y1, x2, mid_y, R, G, B);
		myLineBold(x2, mid_y, x1, mid_y, R, G, B);
		myLineBold(x2, mid_y, x2, y2, R, G, B);
		myLineBold(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '4') {
		myLineBold(x1, y1, x1, mid_y, R, G, B);
		myLineBold(x1, mid_y, x2, mid_y, R, G, B);
		myLineBold(mid_x + size / 6, y1, mid_x + size / 6, y2, R, G, B);
	}
	else if (chr == '5') {
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x1, y1, x1, mid_y, R, G, B);
		myLineBold(x1, mid_y, x2, mid_y, R, G, B);
		myLineBold(x2, mid_y, x2, y2, R, G, B);
		myLineBold(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '6') {
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, mid_y, x2, mid_y, R, G, B);
		myLineBold(x2, mid_y, x2, y2, R, G, B);
		myLineBold(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '7') {
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x2, y1, x2, y2, R, G, B);
	}
	else if (chr == '8') {
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x1, y1, x1, y2, R, G, B);
		myLineBold(x1, mid_y, x2, mid_y, R, G, B);
		myLineBold(x2, y1, x2, y2, R, G, B);
		myLineBold(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '9') {
		myLineBold(x1, y1, x2, y1, R, G, B);
		myLineBold(x1, y1, x1, mid_y, R, G, B);
		myLineBold(x1, mid_y, x2, mid_y, R, G, B);
		myLineBold(x2, y1, x2, y2, R, G, B);
		myLineBold(x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '-')
		myRect(x1 - 5, y1 - 5, x2 + 5, y2 + 5, 0, 0, 0);
}
void lettersnNumbersVar(int thickness, char chr, int x1, int x2, int y1, int y2, int size, int R = 0, int G = 0, int B = 0) {
	x1 += 5;
	x2 -= 5;
	y1 += 5;
	y2 -= 5;
	int mid_x = (x1 + x2) / 2;
	int mid_y = (y1 + y2) / 2;

	if (chr == 'A') {
		myLineVar(thickness, mid_x, y1, x1, y2, R, G, B);
		myLineVar(thickness, mid_x, y1, x2, y2, R, G, B);
		myLineVar(thickness, x1 + 2, mid_y + size / 2, x2 - 3, mid_y + size / 2, R, G, B);
	}
	else if (chr == 'B') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
		myLineVar(thickness, mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
		myLineVar(thickness, x1, mid_y, mid_x, mid_y, R, G, B);
		myLineVar(thickness, mid_x, mid_y, x2, mid_y + size / 4, R, G, B);
		myLineVar(thickness, x2, mid_y + size / 4, mid_x + size / 8, y2, R, G, B);
		myLineVar(thickness, mid_x + size / 8, y2, x1, y2, R, G, B);
	}
	else if (chr == 'C') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x2, y1, x2, y1 + size / 4, R, G, B);
		myLineVar(thickness, x2, y2, x2, y2 - size / 4, R, G, B);
		myLineVar(thickness, x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'D') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y1, mid_x + size / 4, y1 + size / 4, R, G, B);
		myLineVar(thickness, mid_x + size / 4, y1 + size / 4, mid_x + size / 4, y2 - size / 4, R, G, B);
		myLineVar(thickness, mid_x + size / 4, y2 - size / 4, x1, y2, R, G, B);
	}
	else if (chr == 'E') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x1, mid_y, x2, mid_y, R, G, B);
		myLineVar(thickness, x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'F') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x1, mid_y, x2, mid_y, R, G, B);
	}
	else if (chr == 'G') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x2, y1, x2, y1 + size / 4, R, G, B);
		myLineVar(thickness, x2, y2, x2, y2 - size / 2, R, G, B);
		myLineVar(thickness, x2, y2 - size / 2, mid_x, y2 - size / 2, R, G, B);
		myLineVar(thickness, x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'H') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x2, y1, x2, y2, R, G, B);
		myLineVar(thickness, x1, mid_y, x2, mid_y, R, G, B);
	}
	else if (chr == 'I') {
		myLineVar(thickness, mid_x, y1, mid_x, y2, R, G, B);
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'J') {
		myLineVar(thickness, x2, y1, x2, y2, R, G, B);
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x2, y2, x1, y2, R, G, B);
		myLineVar(thickness, x1, y2, x1, y2 - size / 2, R, G, B);
	}
	else if (chr == 'K') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, mid_y, x2, y1, R, G, B);
		myLineVar(thickness, x1, mid_y, x2, y2, R, G, B);
	}
	else if (chr == 'L') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y2, x2, y2, R, G, B);
	}
	else if (chr == 'M') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y1, mid_x, mid_y, R, G, B);
		myLineVar(thickness, mid_x, mid_y, x2, y1, R, G, B);
		myLineVar(thickness, x2, y1, x2, y2, R, G, B);
	}
	else if (chr == 'N') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y1, x2, y2, R, G, B);
		myLineVar(thickness, x2, y1, x2, y2, R, G, B);
	}
	else if (chr == 'O') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x1, y2, x2, y2, R, G, B);
		myLineVar(thickness, x2, y1, x2, y2, R, G, B);
	}
	else if (chr == 'P') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
		myLineVar(thickness, mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
		myLineVar(thickness, x1, mid_y, mid_x, mid_y, R, G, B);

	}
	else if (chr == 'Q') {
		myLineVar(thickness, x1, y1, x1, y2 - 5, R, G, B);
		myLineVar(thickness, x1, y1, mid_x + 3, y1, R, G, B);
		myLineVar(thickness, mid_x + 3, y1, mid_x + 3, y2 - 5, R, G, B);
		myLineVar(thickness, x1, y2 - 5, mid_x + 3, y2 - 5, R, G, B);
		myLineVar(thickness, mid_x - 2, mid_y, mid_x + 3, y2 - 5, R, G, B);
		myLineVar(thickness, mid_x + 3, y2 - 5, x2, y2, R, G, B);
	}
	else if (chr == 'R') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
		myLineVar(thickness, mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
		myLineVar(thickness, x1, mid_y, mid_x, mid_y, R, G, B);
		myLineVar(thickness, mid_x, mid_y, x2, y2, R, G, B);
	}
	else if (chr == 'S') {
		myLineVar(thickness, mid_x, y1, x2, y1 + size / 2, R, G, B);
		myLineVar(thickness, mid_x, y1, x1, y1 + size / 2, R, G, B);
		myLineVar(thickness, x1, y1 + size / 2, x2, y2 - size / 2, R, G, B);
		myLineVar(thickness, x2, y2 - size / 2, mid_x, y2, R, G, B);
		myLineVar(thickness, mid_x, y2, x1, y2 - size / 2, R, G, B);
	}
	else if (chr == 'T') {
		myLineVar(thickness, mid_x, y1, mid_x, y2, R, G, B);
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
	}
	else if (chr == 'U') {
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y2, x2, y2, R, G, B);
		myLineVar(thickness, x2, y1, x2, y2, R, G, B);

	}
	else if (chr == 'V') {
		myLineVar(thickness, x1, y1, mid_x, y2, R, G, B);
		myLineVar(thickness, mid_x, y2, x2, y1, R, G, B);
	}
	else if (chr == 'W') {
		myLineVar(thickness, x1, y1, mid_x - size / 8, y2, R, G, B);
		myLineVar(thickness, mid_x - size / 8, y2, mid_x, mid_y, R, G, B);
		myLineVar(thickness, mid_x, mid_y, mid_x + size / 8, y2, R, G, B);
		myLineVar(thickness, mid_x + size / 8, y2, x2, y1, R, G, B);
	}
	else if (chr == 'X') {
		myLineVar(thickness, x1, y1, x2, y2, R, G, B);
		myLineVar(thickness, x2, y1, x1, y2, R, G, B);

	}
	else if (chr == 'Y') {
		myLineVar(thickness, x1, y1, mid_x, mid_y, R, G, B);
		myLineVar(thickness, x2, y1, x1, y2, R, G, B);
	}
	else if (chr == 'Z') {
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x2, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, y2, x2, y2, R, G, B);
	}
	else if (chr == '.') {
		myRect(x2, y2 - size / 8, mid_x + size / 4, y2, R, G, B);
	}
	else if (chr == ',') {
		myRect(x2, y2 - size / 3, mid_x + size / 4, y2 - size / 6, R, G, B);
		myLineVar(thickness, x2, y2 - size / 3, x2, y2, R);
		myLineVar(thickness, x2, y2, mid_x + size / 4, y2, R);
	}
	else if (chr == '!') {
		myRect(mid_x - size / 8, y1, mid_x - 1, y2 - size / 3, R, G, B);
		myRect(mid_x - size / 8, y2 - size / 8, mid_x, y2, R, G, B);
	}
	else if (chr == ':') {
		myRect(x2, y2 - 20, mid_x + size / 4, y2 - 16, R, G, B);
		myRect(x2, y2 - 4, mid_x + size / 4, y2, R, G, B);
	}
	else if (chr == '0') {
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x2, y1, x2, y2, R, G, B);
		myLineVar(thickness, x1, y2, x2, y2, R, G, B);
		myLineVar(thickness, x2, y1, x1, y2, R, G, B);
	}
	else if (chr == '1') {
		myLineVar(thickness, x1, mid_y - size / 2, mid_x, y1, R, G, B);
		myLineVar(thickness, mid_x, y1, mid_x, y2, R, G, B);
		myLineVar(thickness, x1, y2, x2, y2, R, G, B);
	}
	else if (chr == '2') {
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x2, y1, x2, mid_y, R, G, B);
		myLineVar(thickness, x2, mid_y, x1, mid_y, R, G, B);
		myLineVar(thickness, x1, mid_y, x1, y2, R, G, B);
		myLineVar(thickness, x1, y2, x2, y2, R, G, B);
	}
	else if (chr == '3') {
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x2, y1, x2, mid_y, R, G, B);
		myLineVar(thickness, x2, mid_y, x1, mid_y, R, G, B);
		myLineVar(thickness, x2, mid_y, x2, y2, R, G, B);
		myLineVar(thickness, x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '4') {
		myLineVar(thickness, x1, y1, x1, mid_y, R, G, B);
		myLineVar(thickness, x1, mid_y, x2, mid_y, R, G, B);
		myLineVar(thickness, mid_x + size / 6, y1, mid_x + size / 6, y2, R, G, B);
	}
	else if (chr == '5') {
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x1, y1, x1, mid_y, R, G, B);
		myLineVar(thickness, x1, mid_y, x2, mid_y, R, G, B);
		myLineVar(thickness, x2, mid_y, x2, y2, R, G, B);
		myLineVar(thickness, x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '6') {
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, mid_y, x2, mid_y, R, G, B);
		myLineVar(thickness, x2, mid_y, x2, y2, R, G, B);
		myLineVar(thickness, x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '7') {
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x2, y1, x2, y2, R, G, B);
	}
	else if (chr == '8') {
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x1, y1, x1, y2, R, G, B);
		myLineVar(thickness, x1, mid_y, x2, mid_y, R, G, B);
		myLineVar(thickness, x2, y1, x2, y2, R, G, B);
		myLineVar(thickness, x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '9') {
		myLineVar(thickness, x1, y1, x2, y1, R, G, B);
		myLineVar(thickness, x1, y1, x1, mid_y, R, G, B);
		myLineVar(thickness, x1, mid_y, x2, mid_y, R, G, B);
		myLineVar(thickness, x2, y1, x2, y2, R, G, B);
		myLineVar(thickness, x2, y2, x1, y2, R, G, B);
	}
	else if (chr == '-')
		myRect(x1 - 5, y1 - 5, x2 + 5, y2 + 5, 0, 0, 0);
}
//This Function Converts a Cstring to uppercase
void Capitalizer(char text[]) {
	for (int i = 0; i < strlen(text); i++)
		if (text[i] >= 'a' && text[i] <= 'z')
			text[i] -= 32;
}
//This Function to print Text on Screen
void drawText(int size, int start_x, int start_y, int R, int G, int B, const char text[], bool isNum = false, int num = 0) {
	int idx = 0;
	int idx_x = 0;
	int idx_y = 0;
	int x1, x2, y1, y2;
	int digit_count = 0;
	int len = strlen(text);
	char temp[100];

	strcpy_s(temp, text);
	//If this function takes a number to print then he converts the number into a string using following loop
	if (isNum == true) {
		int reverse_num = 0;
		int i;

		for (; num > 0; num /= 10, digit_count++)
			reverse_num = (reverse_num * 10) + num % 10;

		for (i = len; i - len < digit_count; i++, reverse_num /= 10)
			temp[i] = (reverse_num % 10) + 48;

		temp[i] = '\0';
	}
	//Now the cstring is converted into upper case letters
	Capitalizer(temp);
	//This loop prints each individual letter on the screen
	for (idx = 0; idx < strlen(temp); idx++)
	{
		x1 = start_x + size * idx_x;
		x2 = start_x + size * (idx_x + 1);

		if (x2 > 1585 - size) {
			idx_y++;
			idx_x = 0;
			x1 = start_x + size * idx_x;
			x2 = start_x + size * (idx_x + 1);

		}

		y1 = start_y + 2 * size * idx_y;
		y2 = start_y + 2 * size * (idx_y + 1);
		lettersnNumbers(temp[idx], x1, x2, y1, y2, size, R, G, B);
		idx_x++;
	}

}
void drawTextBold(int size, int start_x, int start_y, int R, int G, int B, const char text[], bool isNum = false, int num = 0) {
	int idx = 0;
	int idx_x = 0;
	int idx_y = 0;
	int x1, x2, y1, y2;
	int digit_count = 0;
	int len = strlen(text);
	char temp[100];

	strcpy_s(temp, text);
	//If this function takes a number to print then he converts the number into a string using following loop
	if (isNum == true) {
		int reverse_num = 0;
		int i;

		for (; num > 0; num /= 10, digit_count++)
			reverse_num = (reverse_num * 10) + num % 10;

		for (i = len; i - len < digit_count; i++, reverse_num /= 10)
			temp[i] = (reverse_num % 10) + 48;

		temp[i] = '\0';
	}
	//Now the cstring is converted into upper case letters
	Capitalizer(temp);
	//This loop prints each individual letter on the screen
	for (idx = 0; idx < strlen(temp); idx++)
	{
		x1 = start_x + size * idx_x;
		x2 = start_x + size * (idx_x + 1);

		if (x2 > 1585 - size) {
			idx_y++;
			idx_x = 0;
			x1 = start_x + size * idx_x;
			x2 = start_x + size * (idx_x + 1);

		}

		y1 = start_y + 2 * size * idx_y;
		y2 = start_y + 2 * size * (idx_y + 1);
		lettersnNumbersBold(temp[idx], x1, x2, y1, y2, size, R, G, B);
		idx_x++;
	}

}
void drawTextVar(int thickness, int size, int start_x, int start_y, int R, int G, int B, const char text[], bool isNum = false, int num = 0) {
	int idx = 0;
	int idx_x = 0;
	int idx_y = 0;
	int x1, x2, y1, y2;
	int digit_count = 0;
	int len = strlen(text);
	char temp[100];

	strcpy_s(temp, text);
	//If this function takes a number to print then he converts the number into a string using following loop
	if (isNum == true) {
		int reverse_num = 0;
		int i;

		for (; num > 0; num /= 10, digit_count++)
			reverse_num = (reverse_num * 10) + num % 10;

		for (i = len; i - len < digit_count; i++, reverse_num /= 10)
			temp[i] = (reverse_num % 10) + 48;

		temp[i] = '\0';
	}
	//Now the cstring is converted into upper case letters
	Capitalizer(temp);
	//This loop prints each individual letter on the screen
	for (idx = 0; idx < strlen(temp); idx++)
	{
		x1 = start_x + size * idx_x;
		x2 = start_x + size * (idx_x + 1);

		if (x2 > 1585 - size) {
			idx_y++;
			idx_x = 0;
			x1 = start_x + size * idx_x;
			x2 = start_x + size * (idx_x + 1);

		}

		y1 = start_y + 2 * size * idx_y;
		y2 = start_y + 2 * size * (idx_y + 1);
		lettersnNumbersVar(thickness, temp[idx], x1, x2, y1, y2, size, R, G, B);
		idx_x++;
	}

}
