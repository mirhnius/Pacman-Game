////Name of student:Abolfazl Yousefi Choobini
////Student No:810196591
////Field:Electrical Engineering
////Pacman.h & Pacman.c & main.c
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include<time.h>


#define PI 3.141592
#define PACMAN_RADIUS 6
#define PACMAN_DIAMETER 12
#define ROWS_PER_TABLE 5
#define COLUMN_PER_TABLE 6
#define CELL_WIDTH 14


//Sets console screen to full screen
//Use this function at the beginning of your program in main()
void initScreen();
//The following function manipulates cursor position
void gotoxy(int x, int y);
//This function will wait for "waitTime" milliseconds and get the new direction from the keybord
//100<waitTime<250
//Use this function between printing the pacman shapes in a single cell
//If the direction is changed the return value is 1 else the return value is 0
int waitAndGetDirection(int waitTime, int *direction);
///draw table with all the properties
void drawtable();
/////draw bonus in x,y cell
void colooche(int x, int y);
///draw all bonuses in the table
void coloch();
///draw pacman in x,y position with mouth degree, in a special direction
void drawpacman(int dx, int dy, int mouthDegree, char direction);
///////clear cell in x,y 
void clearcell(int x, int y);
////print pacman and ghost in each time
void drawOpeningMouthPacman(int x, int y, char direction);
////set next location of pacman
void setNextLocation(int *x, int *y, char direction, int table[][COLUMN_PER_TABLE ][2]);
////wait mseconds 
void delay(unsigned int mseconds);
///drawing ghost
void drawghost(int dx, int dy);
////set next location of ghost
void setNextLocationghost(int *x, int *y, int x1, int y1, int table[][COLUMN_PER_TABLE][2]);
