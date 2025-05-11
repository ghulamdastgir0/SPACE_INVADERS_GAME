# SPACE_INVADERS_GAME
Space Invaders Game (First Semester Project)
This project is a first semester project for learning basic C++ programming and simple graphics handling using the Windows API. It's a classic implementation of the Space Invaders game, where you control a spaceship and must defend Earth from waves of alien invaders.

Features:
Game Mechanics: The player controls a spaceship at the bottom of the screen that can move left and right, shooting bullets to destroy advancing alien invaders. The goal is to eliminate all the aliens before they reach the ground.

Alien Waves: The aliens move in a wave pattern across the screen, dropping lower with each cycle. As the game progresses, the aliens’ speed increases, adding to the challenge.

Bullets: The player can shoot bullets, and the aliens can also shoot back. Bullet collision detection is implemented, so when a bullet hits an alien, both the bullet and the alien are removed from the screen.

Graphics: The game uses basic 2D shapes like lines, rectangles, and ellipses, all drawn on the console using the Windows GDI functions. This involves direct manipulation of the console output, using the windows.h library.

Highscore System: The game tracks your score and stores the top 5 scores in a leaderboard.

Installation & Running:
To run the game, ensure you have a C++ development environment (like Visual Studio) set up. Compile and run the code. If you encounter a blank screen in the console, it is likely due to the use of windows.h for graphical output. In that case, run Visual Studio as Administrator to allow the necessary permissions for drawing to the console window.

Controls:
Arrow Keys: Move the spaceship left and right.

Spacebar: Shoot bullets.

Enter Key: Start a new game or continue from the main menu.

Escape Key: Pause or exit the game.

Notes:
This is a first-semester project, demonstrating basic programming skills and simple graphical rendering in C++.


