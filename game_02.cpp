#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable:4996)
using namespace std;

//全局定义
#define AREA_ROW 20
#define AREA_COL 80
#define STDSPEED 70
#define SUBSPEED 35

//全局声明
FILE *fp;
char BoolBodyLen = 0, BoolFood = 0;//是否加长
char SnakeLife;   //生命
int BodyLen = 0, SnakeSpeed;   //初始蛇身、移速
int score = 0, Mscore;     //积分
enum DIR {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	PAUSE,
	CONTINUE
};
DIR key;       //键值指向
DIR sharp;     //蛇头朝向
enum BlockType {
	NONE,
	WALL,
	HEAD,
	FOOD
} area[AREA_ROW + 1][AREA_COL + 1];//方块状态
struct SnakeLoc {
	int x;
	int y;
};
SnakeLoc snake[AREA_ROW*AREA_COL], OldSnake[2], food;//蛇节位置
void startmap();
void movebody();
void movehead();
void checkkey();
void HideCursor();
void gotoxy(int s, int y);
void headout();
void bodyout(int location);
void throwtail();
void checkhead();
void foodout();
int getrand(int min, int max);
void menuout();
void scoreout();
void createfile();
void writefile();
void renewMscore();

//初始化
void startmap()
{
	for (int i = 0; i <= AREA_ROW; i++)
	{
		for (int j = 0; j <= AREA_COL; j++)
		{
			area[i][j] = NONE;
		}
	}
	system("cls");
	for (int x = 0; x <= AREA_COL; x += 2)
	{
		gotoxy(x, 0);
		area[0][x] = WALL;
		cout << "\033[34m■\033[0m";
		gotoxy(x, AREA_ROW);
		area[AREA_ROW][x] = WALL;
		cout << "\033[34m■\033[0m";
	}
	for (int y = 1; y < AREA_ROW; y++)
	{
		gotoxy(0, y);
		area[y][0] = WALL;
		cout << "\033[34m■\033[0m";
		gotoxy(AREA_COL, y);
		area[y][AREA_COL] = WALL;
		cout << "\033[34m■\033[0m";
	}
	menuout();
	snake[0].x = AREA_COL / 8 * 4;
	snake[0].y = AREA_ROW / 2;
	snake[1].x = snake[0].x - 2;
	snake[1].y = snake[0].y;
	snake[2].x = snake[1].x - 2;
	snake[2].y = snake[0].y;
	headout();
	bodyout(1);
	bodyout(2);
	BodyLen = 2;
	SnakeLife = 1;
	SnakeSpeed = STDSPEED;
	key = RIGHT;
	sharp = RIGHT;
	score = 0;
	BoolFood = 0;
	foodout();
	_getch();
};

//蛇体操作
void movebody()
{
	//蛇节传递
	for (int i = 1; i <= BodyLen; i++)
	{
		OldSnake[1] = snake[i];
		snake[i] = OldSnake[0];
		OldSnake[0] = OldSnake[1];
		bodyout(i);
	}
	if (BoolBodyLen == 1)
	{
		BoolBodyLen = 0;
		foodout();
	}
	else throwtail();//去尾
	Sleep(SnakeSpeed);
}
void movehead()
{
	checkkey();
	OldSnake[0] = snake[0];
	switch (key)
	{
	case LEFT:
		if (sharp != RIGHT)
		{
			snake[0].x -= 2; sharp = key;
		}
		else snake[0].x += 2;
		break;
	case RIGHT:
		if (sharp != LEFT)
		{
			snake[0].x += 2; sharp = key;
		}
		else snake[0].x -= 2;
		break;
	case UP:
		if (sharp != DOWN)
		{
			snake[0].y--; sharp = key;
		}
		else snake[0].y++;
		break;
	case DOWN:
		if (sharp != UP)
		{
			snake[0].y++; sharp = key;
		}
		else snake[0].y--;
		break;
	}
	checkhead();
	headout();
}

//按键检查
void checkkey()
{
	//检查方向键
	if (_kbhit())
	{
		fflush(stdin);
		switch (_getch())
		{
		case 'w':
		case 'W':
			key = UP; break;
		case 's':
		case 'S':
			key = DOWN; break;
		case 'a':
		case 'A':
			key = LEFT; break;
		case 'd':
		case 'D':
			key = RIGHT; break;
		}
	}
	//检查移速键
	if (GetKeyState(75) < 0)
	{
		SnakeSpeed = STDSPEED - SUBSPEED;
	}
	else SnakeSpeed = STDSPEED;
}

//光标函数
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//打印
void headout()
{
	gotoxy(snake[0].x, snake[0].y);
	area[snake[0].y][snake[0].x] = HEAD;
	cout << "\033[36m■\033[0m";
}
void bodyout(int location)
{
	gotoxy(snake[location].x, snake[location].y);
	area[snake[location].y][snake[location].x] = WALL;
	cout << "\033[36m□\033[0m";
}
void throwtail()
{
	gotoxy(OldSnake[0].x, OldSnake[0].y);
	area[OldSnake[0].y][OldSnake[0].x] = NONE;
	cout << "  ";
}
void gameover()
{
	writefile();
	fflush(stdin);
	system("cls");
	gotoxy(0, 0);
	cout << endl << endl << endl << "			**************************************************" << endl << endl;
	cout << "					   GAME OVER" << endl << endl << "			**************************************************";
	cout << endl << endl << "					Try again? (y/n)";
loop:switch (_getch())
	{
	case 'y':
	case 'Y':
		startmap(); break;
	case 'n':
	case 'N':
		system("cls");
		cout << endl << endl << endl << "			**************************************************" << endl << endl;
		cout << "					   \033[1;31mGAME END\033[0m" << endl << endl << "			**************************************************"; 
		cout << endl << endl;
		break;
	default:
		goto loop;
	}
}

//judge函数
void checkhead()
{
	switch (area[snake[0].y][snake[0].x])
	{
	case NONE:break;
	case WALL:
		SnakeLife = 0;
		break;
	case FOOD:
		area[food.y][food.x] = NONE;
		BoolFood = 0;
		BodyLen++;
		score += (BodyLen + 10) / 5;
		BoolBodyLen = 1;
		break;
	}
}

//范围随机数
int getrand(int min, int max)
{
	srand((unsigned)time(NULL));
	return rand() % (max + 1 - min) + min;
}

//食物打印
void foodout()
{
	if (BoolFood)return;
	food.x = getrand(2, AREA_COL - 2);
	food.y = getrand(1, AREA_ROW - 1);
	if (!(food.x % 2) && area[food.y][food.x] == NONE)
	{
		area[food.y][food.x] = FOOD;
		gotoxy(food.x, food.y);
		cout << "\033[33m○\033[0m";
		BoolFood = 1;
	}
}

//积分系统
void menuout()
{
	gotoxy(AREA_COL + 4, 3);
	cout << "MENU:";
	gotoxy(AREA_COL + 4, 5);
	cout << "Key W means UP";
	gotoxy(AREA_COL + 4, 6);
	cout << "Key S means DOWN";
	gotoxy(AREA_COL + 4, 7);
	cout << "Key A means LEFT";
	gotoxy(AREA_COL + 4, 8);
	cout << "Key D means RIGHT";
	gotoxy(AREA_COL + 4, 9);
	cout << "Key K means SPEEDUP";
	gotoxy(AREA_COL + 4, 13);
	cout << "当前分数:";
	gotoxy(AREA_COL + 4, 15);
	cout << "历史最高:";
}
void scoreout()
{
	gotoxy(AREA_COL + 14, 13);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << score;
	gotoxy(AREA_COL + 14, 15);
	renewMscore();
	cout << Mscore;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void createfile()
{
	fp=fopen("D:\\SnakeSnakeSnake.txt","a+");
	fscanf(fp, "%d", &Mscore);
	fclose(fp);
}
void writefile()
{
	fp = fopen("D:\\SnakeSnakeSnake.txt", "w");
	fprintf(fp, "%d", Mscore);
	fclose(fp);
}
void renewMscore()
{
	if (score > Mscore) Mscore = score;
}


//主进程
int main()
{
	createfile();
	HideCursor();
	startmap();
	scoreout();
	while (SnakeLife)
	{
		movehead();
		movebody();
		foodout();
		scoreout();
		if (SnakeLife == 0)gameover();
	}
	system("pause");
	return 0;
}


