#pragma once
//ɨ����

#include"quanbu.h"



#define _CRT_SECURE_NO_WARNINGS 1


//�궨����Ʊ������ı�ʱ���������
#define ROW 9
#define COL 9

#define ROWS 2 + ROW
#define COLS 2 + COL

#define shuliang 10

class saolei
{
public:
	void meun();//�˵�

	void quyu(char mine[ROWS][COLS], int rows, int cols, char n);//�涨�߽�

	void xianshi(char show[ROWS][COLS], int row, int col);//�߽��ڵĲ���

	void buzhi(char mine[ROWS][COLS], int row, int col);//������

	void play(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//��ҵĲ����߼�

	void saoleilou();//��Ϸ�����߼�

	void game();
private:

};




