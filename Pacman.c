////Name of student:Abolfazl Yousefi Choobini
////Student No:810196591
////Field:Electrical Engineering
////Pacman.h & Pacman.c & main.c
#include "Pacman.h"


void initScreen()
{
	COORD coord;
	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(stdHandle, CONSOLE_FULLSCREEN_MODE, &coord);

}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int waitAndGetDirection(int waitTime, char *direction)
{
	DWORD start_time, check_time;

	start_time = GetTickCount();
	check_time = start_time + waitTime; //GetTickTime returns time in miliseconds
	char ch = 0;
	char hit = 0;

	while (check_time>GetTickCount())
	{
		if (_kbhit())
		{
			hit = 1;
			ch = _getch();
			if (ch == 0)
				ch = _getch();
			break;
		}
	}

	switch (ch)
	{
	case 'w':
		ch = 'u';
		break;
	case 'z':
		ch = 'd';
		break;
	case 'a':
		ch = 'l';
		break;
	case 's':
		ch = 'r';
		break;
	default:
		break;
	}

	if (ch != *direction && (ch == 'u' || ch == 'd' || ch == 'l' || ch == 'r'))
	{
		*direction = ch;
		return 1;
	}
	else
		return 0;

}
void drawtable()
{
	int i, j,k,x,y;
	int table[7][6][2];
	for (i = 0;i <= 6;i++)
		for (j = 0;j <= 5;j++)
			for (k = 0;k <= 1;k++)
				table[i][j][k] = 0; ////get first value to all lines=0
	{table[0][0][0] = 1;
	table[1][0][0] = 1;
	table[2][0][0] = 1;
	table[3][0][0] = 1;
	table[4][0][0] = 1;
	table[5][0][0] = 1;
	table[0][0][1] = 1;
	table[0][1][1] = 1;
	table[0][2][1] = 1;
	table[0][3][1] = 1;
	table[0][4][1] = 1;
	table[4][0][1] = 1;
	table[4][1][0] = 1;
	table[5][1][1] = 1;
	table[6][0][1] = 1;
	table[6][1][1] = 1;
	table[6][2][1] = 1;
	table[6][3][1] = 1;
	table[6][4][1] = 1;
	table[2][1][1] = 1;
	table[2][2][0] = 1;
	table[3][2][1] = 1;
	table[3][3][0] = 1;
	table[4][3][1] = 1;
	table[4][4][0] = 1;
	table[5][4][1] = 1;
	table[5][5][0] = 1;
	table[4][5][0] = 1;
	table[3][5][0] = 1;
	table[2][5][0] = 1;
	table[1][5][0] = 1;
	table[0][5][0] = 1;
	table[0][3][0] = 1;
	table[1][3][1] = 1;
	table[1][4][0] = 1;}
	int heightoftable = CELL_WIDTH * 5 + 1;////chars of height of table
	int widthoftable = CELL_WIDTH * 6 + 1;///chars of width of table
	for (i = 1;i <= heightoftable;i++)
	{
		for (j = 1;j <= widthoftable;j++)
		{
			x = (j-1) / CELL_WIDTH;
			y = (i-1) / CELL_WIDTH;
			if (i % CELL_WIDTH == 1)
			{
				if (table[x][y][0] == 1)
					printf("-");
				else
				{
					if (j % CELL_WIDTH == 1)
					{
						if (table[x][y][1] == 1)
							printf("|");
						else
							printf(" ");
					}
					else
						printf(" ");
				}

			}
			else
			{
				if (j % CELL_WIDTH == 1)
					if (table[x][y][1] == 1)
						printf("|");
					else
						printf(" ");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
}
void colooche(int x, int y) /////print colooche in one cell
{
	int i, j;
	for (i = 0;i <= 4;i++)
	{
		gotoxy(CELL_WIDTH * x + 5, CELL_WIDTH * y + 4 + i);
		for (j = 0;j <= 4;j++)
			printf("*");
		
	}
}
void coloch()
{
	int i, j;
	for (i = 0;i <= 5;i++)
		for (j = 0;j <= 4;j++)
			colooche(i, j);
} ///print colooche in each cell
void clearcell(int x, int y)
{
	
	int i, j;
	for (i = 0;i <= 12;i++)
	{
		gotoxy(CELL_WIDTH * x+1, CELL_WIDTH * y + i+1);
		for (j = 0;j <= CELL_WIDTH-2;j++)
			printf(" ");
	}

} ///clear one cell
void drawpacman(int dx, int dy, int mouthDegree, char direction)
{
	int pix[50][50]; ///////array for each pixel of pacman
	int i, j, k, m;
	for (i = -PACMAN_RADIUS - 1;i <= PACMAN_RADIUS + 1;i++)
	{
		for (j = -PACMAN_RADIUS - 1;j <= PACMAN_RADIUS + 1;j++)
		{
			k = i + PACMAN_RADIUS + 1;
			m = j + PACMAN_RADIUS + 1;
			if (i*i + j*j<(PACMAN_RADIUS + 1)*(PACMAN_RADIUS + 1))
			{
				if (i - j*tan(PI * mouthDegree / 360)>=0 || i + j*tan(PI * mouthDegree / 360)<=0)
					pix[m][k] = 1; ////////if pix[m][k]==1 ==> #
				else
					pix[m][k] = 0; ////////if pix[m][k]==0 ==> space
			}
			else
				pix[m][k] = 0;  ////////if pix[m][k]==0 ==> space
		}
	}
	if (direction == 'l')  ////////direction is Left
	{
		for (i = -PACMAN_RADIUS ;i <= PACMAN_RADIUS;i++)
		{
			gotoxy(14 * dx + 1, 14 * dy + 7+i);
			for (j = -PACMAN_RADIUS;j <= PACMAN_RADIUS ;j++)
			{
				k = i + PACMAN_RADIUS + 1;
				m = PACMAN_RADIUS + 1 - j;
				if (pix[m][k] == 1)
					printf("#");
				else
					printf(" ");
			}
		}
	}
	if (direction == 'r') ////////direction is Right
	{
		for (i = -PACMAN_RADIUS ;i <= PACMAN_RADIUS ;i++)
		{
			gotoxy(14 * dx + 1, 14 * dy + 7 + i);
			for (j = -PACMAN_RADIUS ;j <= PACMAN_RADIUS ;j++)
			{
				k = i + PACMAN_RADIUS + 1;
				m = PACMAN_RADIUS + 1 + j;
				if (pix[m][k] == 1)
					printf("#");
				else
					printf(" ");
			}
		}
	}
	if (direction=='u') ////////direction is Up
	{
		for (i = -PACMAN_RADIUS ;i <= PACMAN_RADIUS ;i++)
		{
			gotoxy(14 * dx + 1, 14 * dy + 7 + i);
			for (j = -PACMAN_RADIUS ;j <= PACMAN_RADIUS;j++)
			{
				k = -i + PACMAN_RADIUS + 1;
				m = PACMAN_RADIUS + 1 - j;
				if (pix[k][m] == 1)
					printf("#");
				else
					printf(" ");
			}
		}
	}
	if (direction=='d') ////////direction is Down
	{
		
		for (i = -PACMAN_RADIUS;i <= PACMAN_RADIUS ;i++)
		{
			gotoxy(14 * dx + 1, 14 * dy + 7 + i);
			for (j = -PACMAN_RADIUS ;j <= PACMAN_RADIUS ;j++)
			{
				k = i + PACMAN_RADIUS + 1;
				m = PACMAN_RADIUS + 1 - j;
				if (pix[k][m] == 1)
					printf("#");
				else
					printf(" ");
			}
		}
	}
}///draw pacman
void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
void drawOpeningMouthPacman(int x, int y, char direction)
{
	int table[7][6][2];
	int bonus[6][5];
	int i, j, n,total_score=0;
	for (i = 0;i <= 5;i++)
		for (j = 0;j <= 4;j++)
			bonus[i][j] = 1;
	bonus[0][0]=0;
	for (i = 0;i <= 6;i++)
		for (j = 0;j <= 5;j++)
			for (n = 0;n <= 1;n++)
				table[i][j][n] = 0;////get first value of each line of table
	{table[0][0][0] = 1;
	table[1][0][0] = 1;
	table[2][0][0] = 1;
	table[3][0][0] = 1;
	table[4][0][0] = 1;
	table[5][0][0] = 1;
	table[0][0][1] = 1;
	table[0][1][1] = 1;
	table[0][2][1] = 1;
	table[0][3][1] = 1;
	table[0][4][1] = 1;
	table[4][0][1] = 1;
	table[4][1][0] = 1;
	table[5][1][1] = 1;
	table[6][0][1] = 1;
	table[6][1][1] = 1;
	table[6][2][1] = 1;
	table[6][3][1] = 1;
	table[6][4][1] = 1;
	table[2][1][1] = 1;
	table[2][2][0] = 1;
	table[3][2][1] = 1;
	table[3][3][0] = 1;
	table[4][3][1] = 1;
	table[4][4][0] = 1;
	table[5][4][1] = 1;
	table[5][5][0] = 1;
	table[4][5][0] = 1;
	table[3][5][0] = 1;
	table[2][5][0] = 1;
	table[1][5][0] = 1;
	table[0][5][0] = 1;
	table[0][3][0] = 1;
	table[1][3][1] = 1;
	table[1][4][0] = 1;}
	clearcell(x, y);
	int  m,*x1,*y1,*x2,*y2;
	char *p = (char*)malloc(sizeof(char));
	char e;
	x1 = (int*)malloc(sizeof(int)); ///x of pacman
	y1 = (int*)malloc(sizeof(int));  ///y of pacman
	x2 = (int*)malloc(sizeof(int)); ///x of ghost
	y2 = (int*)malloc(sizeof(int));  ///y of ghost
	*x1 = x;
	*y1 = y;
	*x2 = 5;
	*y2 = 4;
	*p = direction; ////direction of pacman
	int flag = 1; ///for when ghost to pacman
	while (total_score<=29 && flag==1) {
		
		drawghost(*x2, *y2);
		for (i = 0;i <= 120;i = i + 30)
		{

			drawpacman(*x1, *y1, i, *p);
			m=waitAndGetDirection(100, p);
			e = *p;
			clearcell(*x1, *y1);
			
			
			/*if (m == 1)
			{
				setNextLocation(x1, y1, *p, table);
				if (bonus[*x1][*y1] == 1)
				{
					total_score++;
					bonus[*x1][*y1] = 0;
				}
			}*/
		}
		for (i = 120;i >= 0;i = i - 30)
		{
			drawpacman(*x1, *y1, i, *p);
			
			m=waitAndGetDirection(100,p);
			e = *p;
			clearcell(*x1, *y1);
			
			/*if (m == 1)
			{ 
				setNextLocation(x1, y1, *p, table);
				if (bonus[*x1][*y1] == 1)
				{
					total_score++;
					bonus[*x1][*y1] = 0;
				}
			 }*/
		}
		clearcell(*x2, *y2);
		if (bonus[*x2][*y2] == 1)
			colooche(*x2, *y2);////to draw colooche that removed by ghost
		setNextLocation(x1, y1, e, table);////set next location of pacman
		setNextLocationghost(x2, y2, *x1, *y1, table);////set next location of ghost
		if (bonus[*x1][*y1] == 1)////calculate score of palyer
		{
			total_score++;
			bonus[*x1][*y1] = 0;
		}
		gotoxy(0, 12*6-1);///set location of print the score
		printf("total_score:%d", total_score);
		if (total_score == 29) ////finish game after picking all scores
			total_score++;
		if (*x2 == *x1)
			if (*y1 == *y2)
				flag = 0; ////if ghost get the pacman
	}

	}
void setNextLocation(int *x, int *y, char direction, int table[][COLUMN_PER_TABLE][2])
{
	if (direction == 'l')
	{
		
		if (table[*x][*y][1] == 0)
		{
			*x = *x - 1;
			
		}
	}
	if (direction == 'd')
	{
		if (table[*x][*y + 1][0] == 0)
			*y = *y + 1;
	}
	if (direction == 'r')
	{
		
		if (table[*x+1][*y][1] == 0)
			*x = *x + 1;
	}
	if (direction == 'u')
	{
		if (table[*x][*y][0] == 0)
			*y = *y - 1;
	}

}
void setNextLocationghost(int *x, int *y,int x1,int y1, int table[][COLUMN_PER_TABLE][2])
{
	float c, u, d, l, r;   ////calculate distance ghost`s cell - pacman`s cell
		c = sqrt((*x - x1)*(*x - x1) + (*y - y1)*(*y - y1));
		
		u = sqrt((*x  - x1)*(*x  - x1) + ((*y-1) - y1)*((*y-1) - y1));
		
		d = sqrt((*x  - x1)*(*x- x1) + (*y+1 - y1)*(*y+1 - y1));
		
		r = sqrt((*x+1 - x1)*(*x+1 - x1) + (*y - y1)*(*y - y1));
		
		l = sqrt((*x -1 - x1)*(*x -1 - x1) + (*y - y1)*(*y - y1));
		
		if (u <= c && u <= l && u <= r && u <= d) 
		{
			if (table[*x][*y][0] == 0)
				*y = *y - 1;
		}
		if (d <= c && d <= l && d <= r && d <= u)
		{
			if (table[*x][*y+1][0] == 0)
				*y = *y + 1;
		}
		if (r <= c && r <= l && r <= d && r <= u)
		{
			if (table[*x+1][*y][1] == 0)
				*x = *x + 1;
		}
		if (l <= c && l <= r && l <= d && l <= u)
		{
			if (table[*x ][*y][1] == 0)
				*x = *x - 1;
		}
}
void drawghost(int dx, int dy)
{
	int i, j;
	for (i = -PACMAN_RADIUS ;i <= PACMAN_RADIUS;i++)
	{
		gotoxy(14 * dx + 1, 14 * dy + 7 + i);
		for (j = -PACMAN_RADIUS;j <= PACMAN_RADIUS ;j++)
		{
			
			if (i*i + j*j<(PACMAN_RADIUS + 1)*(PACMAN_RADIUS + 1))
			{
				if (i - j*tan(0) >= 0 || i + j*tan(0) <= 0)
					printf("^");
				else
					printf(" "); 
			}
			else
				printf(" ");  
		}
	}
} ////print ghost with ^ charachter