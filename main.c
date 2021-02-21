////Name of student:Abolfazl Yousefi Choobini
////Student No:810196591
////Field:Electrical Engineering
////Pacman.h & Pacman.c & main.c
#include <stdio.h>
#include <conio.h>
#include "Pacman.h"
int main()
{
	char*p, direction,m='r';
	initScreen();///to fullscreen 
	drawtable();/// drawing table
	coloch(); ///print colooche in each cell
	drawOpeningMouthPacman(0, 0, m); ////print pacman and ghost in each time
}