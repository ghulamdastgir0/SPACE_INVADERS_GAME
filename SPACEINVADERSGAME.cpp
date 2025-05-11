#include <iostream>RR
#include "help.h"
#include <cstdlib>
#include <chrono>
#include<fstream>
#include <cstring>

using namespace std;
using namespace chrono;
int score = 0, deduction = 0;
bool firstTime = 1;
bool Continue = 1;
bool Dead = 0;
// A Counter to count the number of game loops or frames
int game_loop_counter = 0;
int loop_counter = 0;

// A integer just to store the extra space our ship takes
int box_offset = 50;
// A bool to set the difficulty of the game
bool isHard = 0;

// Highscores
struct highscores
{
	char position[20];
	int score;
};
highscores leaderBoard[6];

// Arbitrary limits of the console screen
int screen_left = 0, screen_right = 1400, screen_top = 0, screen_bottom = 750;

// Screen dimensions
int screen_width = screen_right - screen_left, screen_height = screen_bottom - screen_top;

// Limits of game screen (the + and -  are for adjustments)
int left_limit = screen_left + screen_width / 320,
right_limit = screen_right - ((screen_width / 8) - 4) + screen_width / 320,
top_limit = screen_top + screen_height / 18,
bottom_limit = screen_bottom - ((screen_height / 4.5) - 4) + screen_height / 18;

// Limits for Ship Movement (the + and - are prevent overlapping with the outline)
int box_left_limit = left_limit + (box_offset / 2) + 25, box_right_limit = right_limit - (box_offset / 2) - 25, box_top_limit = top_limit + (box_offset / 2) + 25, box_bottom_limit = bottom_limit - (box_offset / 2) - 25;

//Generates Random Values from x to y
int randomValues(int startPoint, int endPoint)
{
	int randomValue;
	// Seed the random number generator with the current time
	srand(static_cast<unsigned int>(time(0)));

	// If endpoint - startPoint = 0 then it is impossible to get a chance
	if (endPoint - startPoint != 0)
	{
		randomValue = (rand() % (endPoint - startPoint)) + startPoint;
	}
	else
	{
		return -1; // -1 for no random
	}
	return randomValue;
}

//Scale the Ship
void scaleShip(int xSize, int ySize, int x, int y)
{
	double sizeRate = (ySize - xSize) / 24.0; // The rate at which the ship will scale

	for (int i = 0; xSize < ySize; i++) // A condition that brings xSize to ySize
	{
		removeShip(x, y, xSize, 12);
		xSize += sizeRate;
		drawShip(x, y, xSize);
		Sleep(10);
	}
}

//Generates a Main Menu at the start of the game
char menu(bool isPaused = 0, int size = screen_height / 36, int x = screen_left + screen_width / 10.66, int y = screen_top + screen_height / 9, int R = 0, int G = 150, int B = 250)
{
	//Initial Colors
	int R1 = R, G1 = G + 60, B1 = B;
	int R2 = R, G2 = G, B2 = B;
	int R3 = R, G3 = G, B3 = B;
	int R4 = R, G4 = G, B4 = B;
	//Select Line colors and dimensions
	int R1B = 0, G1B = 132, B1B = 255;
	int Lx1 = screen_left + screen_width / 16, Lx2 = screen_left + screen_width / 4.63, Ly = screen_top + screen_height / 9.47;

	int whichKey = 0;
	int count = 0;
	if (firstTime)
	{
		R1 = 127, G1 = 127, B1 = 127;
		G2 += 60;
		count = 1;
		Lx1 = screen_left + screen_width / 8.42;
		Lx2 = screen_left + screen_width / 3.67;
		Ly = screen_top + screen_height / 3.52;
	}
	system("cls");
	Sleep(20);
	//Left Round Panel
	myEllipse(screen_left - screen_width / 3, screen_top - screen_height / 10, screen_left + screen_width / 3, screen_bottom + screen_height / 90, 139, 139, 139, 12, 12, 12);
	myEllipse(screen_left - screen_width / 2.5, screen_top + screen_height / 90, screen_left + screen_width / 10.6, screen_bottom - screen_height / 10, 139, 139, 139, 12, 12, 12);
	//Game Title
	drawTextBold(size + screen_height / 36, screen_left + screen_width / 2.46, screen_top + screen_height / 4.5, 0, 172, 247, "SPACE INVADERS\n");
	drawTextBold(size + screen_height / 60, screen_left + screen_width / 1.88, screen_top + screen_height / 2.57, 0, 172, 247, "THE GAME\n");
	scaleShip(screen_height / 45, screen_height / 7.5, screen_left + screen_width / 1.6, screen_top + screen_height / 1.28);
	while (whichKey != 3) // 3 is the code for Enter key
	{
		//Initial Select line formation
		myLine(Lx1, Ly, Lx2 - screen_width / 59.2, Ly, R1B, G1B, B1B);
		myLine(Lx1, Ly + screen_height / 14.5, Lx2 - screen_width / 59.2, Ly + screen_height / 14.5, R1B, G1B, B1B);
		//Menu Selections
		drawTextBold(size, x - screen_width / 40, y, R1, G1, B1, "CONTINUE\n");
		if (!isPaused)
		{
			drawTextBold(size, x + screen_width / 32, y + screen_height / 5.6, R2, G2, B2, "NEW GAME\n");
		}
		else
		{
			drawTextBold(size, x + screen_width / 32, y + screen_height / 5.6, R2, G2, B2, "SAVE GAME\n");
		}
		drawTextBold(size, x + screen_width / 80, y + screen_height / 2.5, R3, G3, B3, "HIGHEST SCORE\n");
		drawTextBold(size, x - screen_width / 40, y + screen_height / 1.6, R4, G4, B4, "EXIT GAME");

		if (VerticalMovementCheck(whichKey)) // VerticalMovementCheck function returns true if the up or down or Enter key is pressed and whichKey tells that which key was pressed
		{
			switch (whichKey)
			{
				//return cases
				//count 0-3 for menu selections
			case 3:
				if (count == 0)
					return 'c';
				else if (count == 1)
					return 'n';
				else if (count == 2)
					return 'h';
				else if (count == 3)
					return'e';

				break;
			case 2:
				//down key case
				myLine(Lx1, Ly, Lx2 - screen_width / 59.2, Ly, 12, 12, 12);
				myLine(Lx1, Ly + screen_height / 14.5, Lx2 - screen_width / 59.2, Ly + screen_height / 14.5, 12, 12, 12);
				if (count == 0)
				{
					G1 -= 60;
					G2 += 60;
					count = 1;
					Lx1 = screen_left + screen_width / 8.42;
					if (!isPaused)
					{
						Lx2 = screen_left + screen_width / 3.67;
					}
					else
					{
						Lx2 = screen_left + screen_width / 3.47;
					}
					Ly = screen_top + screen_height / 3.52;
				}
				else if (count == 1)
				{
					G2 -= 60;
					G3 += 60;
					count = 2;
					Lx1 = screen_left + screen_width / 10.0;
					Lx2 = screen_left + screen_width / 3.0;
					Ly = screen_top + screen_height / 1.97;
				}
				else if (count == 2)
				{
					G3 -= 60;
					G4 += 60;
					count = 3;
					Lx1 = screen_left + screen_width / 16.0;
					Lx2 = screen_left + screen_width / 4.3;
					Ly = screen_top + screen_height / 1.37;
				}
				break;

			case 1:
				//up key case
				myLine(Lx1, Ly, Lx2 - screen_width / 59.2, Ly, 12, 12, 12);
				myLine(Lx1, Ly + screen_height / 14.5, Lx2 - screen_width / 59.2, Ly + screen_height / 14.5, 12, 12, 12);
				if (count == 2)
				{
					G2 += 60;
					G3 -= 60;
					count = 1;
					Lx1 = screen_left + screen_width / 8.42;
					if (!isPaused)
					{
						Lx2 = screen_left + screen_width / 3.67;
					}
					else
					{
						Lx2 = screen_left + screen_width / 3.47;
					}
					Ly = screen_top + screen_height / 3.52;
				}
				else if (count == 1)
				{
					if (!firstTime)
					{
						G1 += 60;
						G2 -= 60;
						count = 0;
						Lx1 = screen_left + screen_width / 16.0;
						Lx2 = screen_left + screen_width / 4.63;
						Ly = screen_top + screen_height / 9.47;
					}
				}
				else if (count == 3)
				{
					G3 += 60;
					G4 -= 60;
					count = 2;
					Lx1 = screen_left + screen_width / 10.0;
					Lx2 = screen_left + screen_width / 3.0;
					Ly = screen_top + screen_height / 1.97;
				}
				break;
			}
		}
	}
}

//Generates a difficulty Menu for medium or hard difficulty
char difficultyMenu(bool isPaused = 0, int size = screen_height / 36, int x = screen_left + screen_width / 10.66, int y = screen_top + screen_height / 9, int R = 0, int G = 150, int B = 250)
{
	//Initial Colors
	int R1 = R, G1 = G + 60, B1 = B;
	int R2 = R, G2 = G, B2 = B;
	int R3 = R, G3 = G, B3 = B;
	//Select Line colors and dimensions
	int R1B = 0, G1B = 132, B1B = 255;
	int Lx1 = screen_left + screen_width / 16, Lx2 = screen_left + screen_width / 4.63, Ly = screen_top + screen_height / 9.47;

	int whichKey = 0;
	int count = 0;
	//Left Round Panel
	myEllipse(screen_left - screen_width / 3, screen_top - screen_height / 10, screen_left + screen_width / 3, screen_bottom + screen_height / 90, 139, 139, 139, 12, 12, 12);
	myEllipse(screen_left - screen_width / 2.5, screen_top + screen_height / 90, screen_left + screen_width / 10.6, screen_bottom - screen_height / 10, 139, 139, 139, 12, 12, 12);
	//Game Title
	drawTextBold(size + screen_height / 36, screen_left + screen_width / 2.06, screen_top + screen_height / 4.5, 0, 172, 247, "DIFFICULTY\n");
	drawTextBold(size + screen_height / 60, screen_left + screen_width / 1.88, screen_top + screen_height / 2.57, 0, 172, 247, "SELECTION\n");
	drawShip(screen_left + screen_width / 1.6, screen_top + screen_height / 1.28, screen_height / 7.5);

	drawTextBold(size + screen_height / 160, x - screen_width / 11, y - screen_height / 25, 0, 172, 247, "DIFFICULTY SELECTION\n");
	while (whichKey != 3) // 3 is the code for Enter key
	{
		//Initial Select line formation
		myLine(Lx1 + screen_width / 18, Ly + screen_height / 5.6, Lx2 + screen_width / 18, Ly + screen_height / 5.6, R1B, G1B, B1B);
		myLine(Lx1 + screen_width / 18, Ly + screen_height / 5.6 + screen_height / 14.5, Lx2 + screen_width / 18, Ly + screen_height / 14.5 + screen_height / 5.6, R1B, G1B, B1B);
		//Menu Selections
		drawTextBold(size, x + screen_width / 32, y + screen_height / 5.6, R1, G1, B1, "EASY MODE\n");
		drawTextBold(size, x + screen_width / 20, y + screen_height / 2.5, R2, G2, B2, "HARD MODE\n");
		drawTextBold(size, x - screen_width / 40, y + screen_height / 1.6, R3, G3, B3, "BACK");

		if (VerticalMovementCheck(whichKey)) // VerticalMovementCheck function returns true if the up or down or Enter key is pressed and whichKey tells that which key was pressed
		{
			switch (whichKey)
			{
				//return cases
				//count 0-3 for menu selections
			case 3:
				if (count == 0)
					return 'n';
				else if (count == 1)
					return 'h';
				else if (count == 2)
					return'e';

				break;
			case 2:
				//down key case
				myLine(Lx1 + screen_width / 18, Ly + screen_height / 5.6, Lx2 + screen_width / 18, Ly + screen_height / 5.6, 12, 12, 12);
				myLine(Lx1 + screen_width / 18, Ly + screen_height / 5.6 + screen_height / 14.5, Lx2 + screen_width / 18, Ly + screen_height / 14.5 + screen_height / 5.6, 12, 12, 12);
				if (count == 0)
				{
					G1 -= 60;
					G2 += 60;
					count = 1;
					Lx1 = screen_left + screen_width / 12.3;
					Lx2 = screen_left + screen_width / 4.25;
					Ly = screen_top + screen_height / 3.05;
				}
				else if (count == 1)
				{
					G2 -= 60;
					G3 += 60;
					count = 2;
					Lx1 = screen_left + screen_width / 160;
					Lx2 = screen_left + screen_width / 12.4;
					Ly = screen_top + screen_height / 1.81;
				}
				break;

			case 1:
				//up key case
				myLine(Lx1 + screen_width / 18, Ly + screen_height / 5.6, Lx2 + screen_width / 18, Ly + screen_height / 5.6, 12, 12, 12);
				myLine(Lx1 + screen_width / 18, Ly + screen_height / 5.6 + screen_height / 14.5, Lx2 + screen_width / 18, Ly + screen_height / 14.5 + screen_height / 5.6, 12, 12, 12);
				if (count == 2)
				{
					G2 += 60;
					G3 -= 60;
					count = 1;
					Lx1 = screen_left + screen_width / 12.3;
					Lx2 = screen_left + screen_width / 4.25;
					Ly = screen_top + screen_height / 3.05;
				}
				else if (count == 1)
				{
					G1 += 60;
					G2 -= 60;
					count = 0;
					Lx1 = screen_left + screen_width / 16.0;
					Lx2 = screen_left + screen_width / 4.63;
					Ly = screen_top + screen_height / 9.47;
				}
				break;
			}
		}
	}
}

void highscoreMenu(int size = 25)
{
	int colorArr[5][3] = { {255,223,0},{189,199,206},{205,127,50},{0,210,210},{255,255,255} };
	system("cls");
	Sleep(10);
	drawTextBold(size + screen_height / 180, screen_left + screen_width / 32, screen_top + screen_height / 36, 0, 150, 250, "LEADERBOARDS");
	drawTextBold(size, screen_left + screen_width / 1.52, screen_top + screen_height / 1.4, 0, 150, 250, "YOUR SCORE: ", 1, score);

	/*myLine(size + screen_height / 45, screen_left + screen_width / 2.51, screen_top + screen_height / 5.8, screen_left + screen_width / 2.51, 0, 132, 255);
	myLine(size + screen_height / 45, screen_left + screen_width / 2.51 + screen_height / 14.5, screen_top + screen_height / 5.8, screen_left + screen_width / 2.51 + screen_height / 14.5, 0, 132, 255);
	*/
	drawTextBold(size, screen_left + screen_width / 32, screen_top + screen_height / 1.4, 0, 210, 250, "BACK");
	for (int i = 0; i < 5; i++)
	{
		drawTextVar(8, size, screen_left + screen_width / 32, screen_top + screen_height / 7.5 + (i * (screen_top + screen_height / 9)), 158, 158, 158, "", 1, i + 1);
		drawTextVar(8, size, screen_left + screen_width / 22, screen_top + screen_height / 7.5 + (i * (screen_top + screen_height / 9)), 158, 158, 158, " .. ");
		drawTextVar(8, size, screen_left + screen_width / 8, screen_top + screen_height / 7.5 + (i * (screen_top + screen_height / 9)), 158, 158, 158, leaderBoard[i].position);
		drawTextVar(8, size, screen_left + screen_width / 1.18, screen_top + screen_height / 7.5 + (i * (screen_top + screen_height / 9)), 158, 158, 158, " ", 1, leaderBoard[i].score);

		drawTextVar(4, size, screen_left + screen_width / 32, screen_top + screen_height / 7.5 + (i * (screen_top + screen_height / 9)), colorArr[i][0], colorArr[i][1], colorArr[i][2], "", 1, i + 1);
		drawTextVar(4, size, screen_left + screen_width / 22, screen_top + screen_height / 7.5 + (i * (screen_top + screen_height / 9)), colorArr[i][0], colorArr[i][1], colorArr[i][2], " .. ");
		drawTextVar(4, size, screen_left + screen_width / 8, screen_top + screen_height / 7.5 + (i * (screen_top + screen_height / 9)), colorArr[i][0], colorArr[i][1], colorArr[i][2], leaderBoard[i].position);
		drawTextVar(4, size, screen_left + screen_width / 1.18, screen_top + screen_height / 7.5 + (i * (screen_top + screen_height / 9)), colorArr[i][0], colorArr[i][1], colorArr[i][2], " ", 1, leaderBoard[i].score);
	}
	do
	{
	} while (!EnterKeyCheck());
}

//A function to draw Hearts
void drawHeart(int x, int y, int size)
{
	double unit = size / 30.0;
	myTriangle(x - 13.5 * unit, y - 1.5 * unit, x + 13.5 * unit, y - 1.5 * unit, x + 0 * unit, y + 12.5 * unit, 202, 0, 0, 202, 0, 0);
	myEllipse(x - 15 * unit, y - 12.5 * unit, x + 0 * unit, y + 2.5 * unit, 202, 0, 0, 202, 0, 0);
	myEllipse(x + 0 * unit, y - 12.5 * unit, x + 15 * unit, y + 2.5 * unit, 202, 0, 0, 202, 0, 0);
}
void drawHeartS(int lives)
{
	for (int i = 0; i < lives; i++)
	{
		drawHeart(screen_right - 150 + (i * 35), screen_top + 25, 30);
	}
}
void removeHeartS()
{
	myRect(screen_right - 220, screen_top, screen_right, screen_top + 40, 12, 12, 12, 12, 12, 12);
}

// A Bullet structure for the purpose of dealing multiple bullets on screen
const int max_bullets = 1;
struct Bullet
{
	int x, y;
	bool isActive;
};
Bullet bullets[max_bullets];

// Prints a Black Bullet to remove it
void remove_bullet(int current_x, int current_y)
{
	myEllipse(current_x - 3, current_y - 7, current_x + 3, current_y + 7, 0, 0, 0, 0, 0, 0);
}
// Prints a Purple Bullet
void draw_bullet(int current_x, int current_y)
{
	myEllipse(current_x - 3, current_y - 7, current_x + 3, current_y + 7, 169, 42, 255, 143, 36, 215);
}
// Moves the Bullet
void move_bullet(int x, int& y)
{
	remove_bullet(x, y);
	int step_size = 30;
	y -= step_size;
	draw_bullet(x, y);
}

// A Bullet structure by aliens for the purpose of dealing multiple bullets on screen
const int max_alien_bullets = 4;
struct alien_Bullet
{
	int x, y;
	bool isActive;
};
alien_Bullet alien_bullets[max_alien_bullets];

// Prints a Black Alien Bullet to remove it
void remove_alien_bullet(int current_x, int current_y)
{
	myEllipse(current_x - 3, current_y - 7, current_x + 3, current_y + 7, 0, 0, 0, 0, 0, 0);
}
// Prints a green Alien Bullet
void draw_alien_bullet(int current_x, int current_y)
{
	myEllipse(current_x - 3, current_y - 7, current_x + 3, current_y + 7, 28, 232, 38, 28, 232, 38);
}
// Moves the Alien Bullet
void move_alien_bullet(int x, int& y)
{
	remove_alien_bullet(x, y);
	int step_size = 15;
	y += step_size;
	draw_alien_bullet(x, y);
}

// An alien structure for the purpose of handling multiple aliens with thier unique IDs
const int alien_rows = 5, alien_columns = 10;
int aliens_x_step_size = 30, aliens_y_step_size = 0;
struct Alien
{
	int type;
	int x_coord;
	int y_coord;
	bool isActive;
};
Alien aliens[alien_rows][alien_columns];

void drawAlien(int x, int y, int type, int size)
{
	double unit = size / 20.0;
	if (type == 3)
	{
		drawAlienType3(x, y, size);
	}
	else if (type == 1)
	{
		drawAlienType1(x, y, size);
	}
	else if (type == 2)
	{
		drawAlienType2(x, y, size);
	}
	/*myEllipse(x - 20, y - 20, x + 20, y + 20, R, G, B, R, G, B);
	myEllipse(x - 5, y - 5, x - 2, y + 2, 255, 255, 255, 255, 255, 255);
	myEllipse(x + 2, y - 5, x + 5, y + 2, 255, 255, 255, 255, 255, 255);*/
}
void removeAlien(int x, int y, int type, int size)
{
	int unit = size / 20;
	if (type == 3)
	{
		removeAlienType3(x, y, size);
	}
	else if (type == 2)
	{
		removeAlienType2(x, y, size);
	}
	else if (type == 1)
	{
		removeAlienType1(x, y, size);
	}
}
void moveAlien(int& x, int& y, int type)
{
	removeAlien(x, y, type, 50);
	x += aliens_x_step_size;
	y += aliens_y_step_size;
	drawAlien(x, y, type, 50);
}
void moveAlienArray()
{
	// Move all active aliens based on updated step sizes
	for (int i = 0; i < alien_rows; i++)
	{
		for (int j = 0; j < alien_columns; j++)
		{
			if (aliens[i][j].isActive) {
				moveAlien(aliens[i][j].x_coord, aliens[i][j].y_coord, aliens[i][j].type);
			}
		}
	}
}

// A function that check if any of the bullets overlaps an argumented alien, if it does, it removes the bullet and the alien
void Alien_Bullet_Overlap_Check(int i, int j, int& kill_counter)
{
	// Go through every active bullet to check its coordinates
	for (int k = 0; k < max_bullets; k++)
	{
		if (bullets[k].isActive)
		{
			// If the bullet overlaps with the Alien...
			if ((bullets[k].y - 30 >= aliens[i][j].y_coord - 20) && (bullets[k].y - 30 <= aliens[i][j].y_coord + 20) && (bullets[k].x >= aliens[i][j].x_coord - 25) && (bullets[k].x <= aliens[i][j].x_coord + 25))
			{
				bullets[k].isActive = 0; // De-activate the bullet
				aliens[i][j].isActive = 0;// De-activate the alien

				// Scoring standards
				if (aliens[i][j].type == 3)
				{
					score += (30 - deduction); // 30 basic score if type 3
				}
				else if (aliens[i][j].type == 2)
				{
					score += (20 - deduction); // 20 basic score if type 3
				}
				else
				{
					score += (10 - deduction); // 10 basic score if type 3
				}

				remove_bullet(bullets[k].x, bullets[k].y);// Remove the bullet
				removeAlien(aliens[i][j].x_coord, aliens[i][j].y_coord, aliens[i][j].type, 50);// Remove the alien
				kill_counter++; // Counting the number of kills
				//score
				myRect(screen_left + 15, screen_top + 10, screen_left + 250, screen_top + 40, 12, 12, 12, 12, 12, 12);
				drawText(15, screen_top + 15, screen_left + 10, 0, 255, 0, "Score: ", 1, score);
				break;
			}
		}
	}
}
// A function the creates a bounce effect when aliens hit the boundary
void bounce_sequence(bool& bounce_once, int& bounce_count)
{
	// The Bounce Sequence
	if (bounce_once)
	{
		aliens_x_step_size *= -1; // Change the x Direction of Aliens
		bounce_count++; // Counting the number of bounces
		bounce_once = 0; // The bounce Sequence is complete
		// A condition to check every 3rd bounce to initiate a close_up sequence
		if (bounce_count == 3)
		{
			aliens_y_step_size = 40; // Changing the y step_size
			bounce_count = 0; // Resetting the bounce_counter
		}
	}
}
void alien_shoot()
{
	int count = 0;
	for (int j = 0; j < alien_columns; j++)
	{
		if (aliens[0][j].isActive)
		{
			count++;
		}
	}
	int randomCount = randomValues(0, count);
	int thatAlien = 0;
	for (int i = 0, j = 0; i < alien_columns; i++)
	{
		if (aliens[0][i].isActive)
		{
			j++;
		}
		if (j == randomCount)
		{
			thatAlien = i;
		}
	}

	if (randomCount != -1)
	{
		for (int i = 0; i < max_alien_bullets; i++)
		{
			if (!alien_bullets[i].isActive)
			{
				alien_bullets[i].x = aliens[0][thatAlien].x_coord;
				alien_bullets[i].y = aliens[0][thatAlien].y_coord + 20;
				alien_bullets[i].isActive = 1;
				break;
			}
		}
	}
}
void Player_Bullet_Overlap_Check(int ship_x, int ship_y, int& lives, int i)
{
	alien_bullets[i].isActive = false; // De-activate the bullet
	remove_alien_bullet(alien_bullets[i].x, alien_bullets[i].y);// Remove the bullet
	removeShip(ship_x, ship_y, 50);// Remove the Ship
	Sleep(300);
	drawShip(ship_x, ship_y, 50);
	lives--; // Subtracting the one life lost
	removeHeartS();
	drawHeartS(lives);
}

int main()
{
	bool reMenu;
	do
	{
		score = 0;
		// Ship related
		int box_x = 700, box_y = 600 - 5, step_size = 20, ShipSize = 50, lives = 3; // Initial Coords and Size of Ship and also the ship size
		char planeHorzDirection = ' ', planeVertDirection = ' '; // Initial Direction (rest) of Plane Movement

		// Intital Activation States of Bullets
		for (int i = 0; i < max_bullets; i++)
		{
			bullets[i].isActive = 0;
		}

		for (int i = 0; i < max_alien_bullets; i++)
		{
			alien_bullets[i].isActive = 0;
		}

		// Intital Activation States of Aliens and their positions and colors
		int alienPosition_x = 300, alienPosition_y = 100;
		for (int i = 0; i < alien_rows; i++)
		{
			for (int j = 0; j < alien_columns; j++)
			{
				aliens[i][j].isActive = 1;
				aliens[i][j].x_coord = alienPosition_x + (j * 90);
				aliens[i][j].y_coord = alienPosition_y + (i * 70);
				if (i < 1)
				{
					aliens[i][j].type = 3;
				}
				else if (i < 3)
				{
					aliens[i][j].type = 2;
				}
				else
				{
					aliens[i][j].type = 1;
				}
			}
		}

		// Bool Check for if game is paused Currently, for Pause menu
		bool isPaused = 0;

		// Bool check to cater a few lose conditions
		bool Invaded = false, Destroyed = false;

		// An Integer variable to keep track of time/cycles of bullets movement before firing another bullet
		int fire_countdown = 0;
		int kill_counter = 0;
		int alien_shoot_frequency;

		// Key states that are wither 1 or 2 depending on which key is pressed
		int HorizontalKey = 0, VerticalKey = 0;

		// Counting the number of time Aliens have hit the wall
		int bounce_count = 0, aliens_step_counter = 15;
		bool bounce_once = 0;

		char play_difficulty = 't';
		char play_option;

		ifstream Highscores("highscores.txt");
		for (int i = 0; i < 5; i++)
		{
			Highscores >> leaderBoard[i].score;
		}
		strcpy_s(leaderBoard[0].position, "Gold Tier");
		strcpy_s(leaderBoard[1].position, "Silver Tier");
		strcpy_s(leaderBoard[2].position, "Bronze Tier");
		strcpy_s(leaderBoard[3].position, "Diamond Tier");
		strcpy_s(leaderBoard[4].position, "Platinum Tier");
		do
		{
			reMenu = false;
			ifstream filer("store.txt");
			filer >> firstTime;
			play_option = menu(0); // Opening the main menu with false/0 as the isPaused argument

			if (play_option == 'c')
			{
				system("cls");
				Sleep(20);
				filer >> lives >> score >> deduction;
				filer >> game_loop_counter >> loop_counter;
				filer >> box_x >> box_y;
				for (int i = 0; i < max_bullets; i++)
				{
					filer >> bullets[i].y >> bullets[i].x >> bullets[i].isActive;
				}
				for (int i = 0; i < max_alien_bullets; i++)
				{
					filer >> alien_bullets[i].y >> alien_bullets[i].x >> alien_bullets[i].isActive;
				}
				for (int i = 0; i < alien_rows; i++)
				{
					for (int j = 0; j < alien_columns; j++)
					{
						filer >> aliens[i][j].x_coord;
						filer >> aliens[i][j].y_coord;
						filer >> aliens[i][j].isActive;
						filer >> aliens[i][j].type;
					}
				}
				filer >> ShipSize >> aliens_step_counter;
				filer >> bounce_count >> bounce_once >> isHard >> alien_shoot_frequency;
				filer >> kill_counter >> fire_countdown;
			}
			else if (play_option == 'n')
			{
				system("cls");
				Sleep(10);

				play_difficulty = difficultyMenu(0);

				if (play_difficulty == 'n')
				{
					isHard = 0;
					alien_shoot_frequency = 60;
					firstTime = 0;
					system("cls");
					Sleep(10);
				}
				else if (play_difficulty == 'h')
				{
					isHard = 1;
					alien_shoot_frequency = 30;
					firstTime = 0;
					system("cls");
					Sleep(10);
				}
				else if (play_difficulty == 'e')
				{
					reMenu = 1;
				}
			}
			else if (play_option == 'h')
			{
				highscoreMenu(25);
				system("cls");
				Sleep(20);
				reMenu = 1;
			}
			else if (play_option == 'e')
			{
				system("cls");
				Sleep(10);
				cout << "GOOD BYE";
				return 0;
			}
			filer.close();
		} while (reMenu == 1);
		// Setting the Initial Scene for the game
		drawHeartS(lives);
		myRect(left_limit, top_limit, right_limit, bottom_limit, 61, 0, 194); // box border or outline purple
		drawShip(box_x, box_y, ShipSize);
		drawText(15, screen_top + 15, screen_left + 10, 0, 255, 0, "Score: ");

		// Main Game Loop where each iteration of loop is synonymous to one frame
		do
		{
			//auto start_time = high_resolution_clock::now();

			// Movement Cases
			if (HorizontalMovementCheck(HorizontalKey)) // HorizontalMovementCheck function returns true if the left or right arrow key is pressed and HorizontalKey tells that which key was pressed
			{
				switch (HorizontalKey)
				{
				case 1:
					planeHorzDirection = 'L';
					break;
				case 2:
					planeHorzDirection = 'R';
					break;
				}
			}
			if (VerticalMovementCheck(HorizontalKey)) // VerticalMovementCheck function returns true if the up or down arrow key is pressed and VerticalKey tells that which key was pressed
			{
				switch (HorizontalKey)
				{
				case 1:
					planeVertDirection = 'U';
					break;
				case 2:
					planeVertDirection = 'D';
					break;
				}
			}
			// Firing Case
			if (SpaceKeyCheck()) // SpaceKeyCheck function returns true if the space key is pressed
			{
				//Only fire a bullet after 10 cycles of reload time after firing a bullet
				if (fire_countdown == 0)
				{
					//Check for each of 1 bullets
					for (int i = 0; i < max_bullets; i++)
					{
						//Check if that bullet is Active right now
						if (!bullets[i].isActive)
						{
							//If Active rn Store the initial position
							bullets[i].x = box_x;
							bullets[i].y = box_y - 35;
							//That Bullet is now Active
							bullets[i].isActive = true;
							break;  // Only fire one bullet
						}
					}
					//Reload time of 10 Cycles
					fire_countdown = 10;
				}
			}
			// pausing Case
			if (EscapeKeyCheck()) // EscapeKeyCheck function returns true if Escape key is pressed
			{
				isPaused = 1;
			}

			if (isPaused) // A conditon to check if game is paused
			{
				do
				{
					system("cls"); // Clean the screen to create space for the menu
					Sleep(10); // A delay to properly display graphics
					play_option = menu(1); // Opening the menu with true/0 for the isPaused argument
					if (play_option == 'c')
					{
						isPaused = 0; // Game is now not paused
						system("cls"); //Clean the screen to create space for game graphics
						Sleep(10); // Setting the Game Screen
						myRect(left_limit, top_limit, right_limit, bottom_limit, 61, 0, 194);
						drawShip(box_x, box_y, ShipSize);
						drawHeartS(lives);
						drawText(15, screen_top + 15, screen_left + 10, 0, 255, 0, "Score: ", 1, score);
						reMenu = 0;
					}
					else if (play_option == 'n')
					{
						ofstream file1("store.txt");
						file1 << firstTime << "\n";
						file1 << lives << "\n" << score << "\n" << deduction << "\n";
						file1 << game_loop_counter << "\n" << loop_counter << "\n";
						file1 << box_x << "\n" << box_y << "\n";
						for (int i = 0; i < max_bullets; i++) {
							file1 << bullets[i].y << "\n" << bullets[i].x << "\n" << bullets[i].isActive << "\n";
						}
						for (int i = 0; i < max_alien_bullets; i++)
						{
							file1 << alien_bullets[i].y << "\n" << alien_bullets[i].x << "\n" << alien_bullets[i].isActive << "\n";
						}
						for (int i = 0; i < alien_rows; i++)
						{
							for (int j = 0; j < alien_columns; j++)
							{
								file1 << aliens[i][j].x_coord << "\n";
								file1 << aliens[i][j].y_coord << "\n";
								file1 << aliens[i][j].isActive << "\n";
								file1 << aliens[i][j].type << "\n";
							}
							file1 << "\n";
						}
						file1 << ShipSize << "\n" << aliens_step_counter << "\n";
						file1 << bounce_count << "\n" << bounce_once << "\n" << isHard << "\n" << alien_shoot_frequency << "\n";
						file1 << kill_counter << "\n" << fire_countdown << "\n";
						file1.close();
					}
					else if (play_option == 'h')
					{
						highscoreMenu(25);
						system("cls");
						Sleep(20);
						reMenu = 1;
					}
					else if (play_option == 'e')
					{
						system("cls");
						Sleep(10);
						reMenu = 0;
						Continue = 0;
						cout << "GOOD BYE";
					}
				} while (reMenu);
			}

			// Going through each alien to check for step_counters, directions, alien_bullet_overlap, invasions and hit cases
			for (int i = alien_rows - 1; i > -1; i--)
			{
				for (int j = alien_columns - 1; j > -1; j--)
				{
					// Go through every active alien to check if it is at the boundary limit
					if (aliens[i][j].isActive)
					{
						Alien_Bullet_Overlap_Check(i, j, kill_counter);
						// This condition ensure the aliens movement in every 10th iteration of game loop only
						if (aliens_step_counter >= 15 - (isHard * 10))
						{
							// If Even One Alien is at the Boundary Limit, initiate a Bounce Sequence thorugh bounce_once boolean
							if (bounce_once != 1 && (aliens[i][j].x_coord - 20 <= box_left_limit || aliens[i][j].x_coord + 20 >= box_right_limit))
							{
								bounce_once = 1;
								// No Break is used since the bullet and Alien overlap logic has to checked for each of the 50 aliens
							}
						}
						// A condition to check if the aliens are crossing bottom limit
						if (aliens[i][j].y_coord > bottom_limit - 120)
						{
							Invaded = true; // A bool condition to initiate an immediate loss sequence
							break;
						}
						// A condition to check if the aliens have hit the ship
						if (aliens[i][j].x_coord - 25 < box_x + 25 && aliens[i][j].x_coord + 25 > box_x - 25 && aliens[i][j].y_coord - 25 < box_y + 25 && aliens[i][j].y_coord + 25 > box_y - 25)
						{
							Destroyed = true; // A bool condition to decrease the player's life
							break;
						}
					}
				}
			}

			bounce_sequence(bounce_once, bounce_count); // Bounce in the case of hitting the walls

			// Move the aliens if the alien_step_counter is at 15
			if (aliens_step_counter >= 15 - (isHard * 10))
			{
				moveAlienArray();
				// After updating every aliens y coords we are changing the y step_size back
				if (aliens_y_step_size != 0)
				{
					aliens_y_step_size = 0;
				}
				aliens_step_counter = 0;
			}

			aliens_step_counter++; // Alien stepping counter increase

			Sleep(25); // Sleep to maintain the CPU usage

			// Player Bullet Movement
			for (int i = 0; i < max_bullets; i++) // Check for each of 3 bullets
			{
				if (bullets[i].isActive) // Move the bullet only if the bullet is currently active
				{
					if (bullets[i].y - 31 > box_top_limit) // Condition to check if the bullet is in the limits
					{
						move_bullet(bullets[i].x, bullets[i].y);
					}
					else
					{
						remove_bullet(bullets[i].x, bullets[i].y);
						bullets[i].isActive = false;  // Deactivate off-screen bullets
					}
				}
			}

			// Reload time
			if (fire_countdown > 0)
			{
				fire_countdown--; // Going through the reload time
			}

			// Random alien shoot mechanic at regular intervals
			if (game_loop_counter % alien_shoot_frequency == (58 / (isHard + 1)))
			{
				alien_shoot();
			}

			//Player_Bullet_Overlap_Check(box_x, box_y, lives);
			for (int i = 0; i < max_alien_bullets; i++)
			{
				if (alien_bullets[i].isActive)
				{
					// If the bullet overlaps with the Alien...
					if ((alien_bullets[i].y + 15 >= box_y - 25) && (alien_bullets[i].y + 15 <= box_y + 25) && (alien_bullets[i].x >= box_x - 20) && (alien_bullets[i].x <= box_x + 20))
					{
						Player_Bullet_Overlap_Check(box_x, box_y, lives, i);
						break;
					}
					if (alien_bullets[i].y + 15 < box_bottom_limit) // Condition to check if the bullet is in the limits
					{
						move_alien_bullet(alien_bullets[i].x, alien_bullets[i].y);
					}
					else
					{
						remove_alien_bullet(alien_bullets[i].x, alien_bullets[i].y);
						alien_bullets[i].isActive = false;  // Deactivate off-screen bullets
					}
				}
			}

			// Playe Movement in the desired direction
			if (planeHorzDirection == 'L')
			{
				// Left
				removeShip(box_x, box_y, ShipSize);
				if (box_x > box_left_limit)
				{
					box_x -= step_size;
					planeHorzDirection = ' ';
				}
				else
				{
					planeHorzDirection = ' ';
				}
				drawShip(box_x, box_y, ShipSize);
			}
			else if (planeHorzDirection == 'R')
			{
				// Right
				removeShip(box_x, box_y, ShipSize);
				if (box_x < box_right_limit)
				{
					box_x += step_size;
					planeHorzDirection = ' ';
				}
				else
				{
					planeHorzDirection = ' ';
				}
				drawShip(box_x, box_y, ShipSize);
			}
			if (planeVertDirection == 'U')
			{
				// Up
				removeShip(box_x, box_y, ShipSize);
				if (box_y > box_top_limit)
				{
					box_y -= step_size;
					planeVertDirection = ' ';
				}
				else
				{
					planeVertDirection = ' ';
				}
				drawShip(box_x, box_y, ShipSize);
			}
			else if (planeVertDirection == 'D')
			{
				// Down
				removeShip(box_x, box_y, ShipSize);
				if (box_y < box_bottom_limit)
				{
					box_y += step_size;
					planeVertDirection = ' ';
				}
				else
				{
					planeVertDirection = ' ';
				}
				drawShip(box_x, box_y, ShipSize);
			}

			game_loop_counter++;
			if (kill_counter == 50)
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						aliens[i][j].isActive = 1;
						aliens[i][j].x_coord = alienPosition_x + (j * 90);
						aliens[i][j].y_coord = alienPosition_y + (i * 70);
					}
				}
				kill_counter = 0;
			}

			// Loop counter to maintain the decrease in score
			loop_counter++;
			if (loop_counter >= 700 && deduction <= 6)
			{
				deduction += 2;
				loop_counter = 0;
			}

			// In case we are invaded
			if (Invaded)
			{
				lives = 0;
			}
			// In case the ship gets destroyed
			if (Destroyed) {
				--lives;
				removeHeartS();
				drawHeartS(lives);
				removeShip(box_x, box_y, ShipSize);
				box_x = 700, box_y = 600 - 5;
				drawShip(box_x, box_y, ShipSize);
				Destroyed = false;
			}

			// Immediate loss sequence
			if (lives == 0)
			{
				firstTime = 1;
				system("cls");
				Sleep(10);
				for (int i = 4; i >= 0; i--)
				{
					if (leaderBoard[i].score < score)
					{
						leaderBoard[i + 1] = leaderBoard[i];
						leaderBoard[i].score = score;
					}
				}
				ofstream LeaderBoards("highscores.txt");
				for (int i = 0; i < 5; i++)
				{
					LeaderBoards << leaderBoard[i].score << "\n";
				}
				LeaderBoards.close();
				highscoreMenu();
				system("cls");
				Sleep(20);
				reMenu = 1;
				firstTime = 1;
				break;
			}
		} while (Continue);
		ofstream LeaderBoards("highscores.txt");
		for (int i = 0; i < 5; i++)
		{
			LeaderBoards << leaderBoard[i].score << "\n";
		}
		LeaderBoards.close();
	} while (reMenu);
	return 0;
}

