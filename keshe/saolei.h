#pragma once
//扫雷类

#include"quanbu.h"



#define _CRT_SECURE_NO_WARNINGS 1


//宏定义控制变量，改变时更方便操作
#define ROW 9
#define COL 9

#define ROWS 2 + ROW
#define COLS 2 + COL

#define shuliang 10

class saolei
{
public:
	void meun();//菜单

	void quyu(char mine[ROWS][COLS], int rows, int cols, char n);//规定边界

	void xianshi(char show[ROWS][COLS], int row, int col);//边界内的布局

	void buzhi(char mine[ROWS][COLS], int row, int col);//布置雷

	void play(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//玩家的操作逻辑

	void saoleilou();//游戏运行逻辑

	void game();
private:

};




