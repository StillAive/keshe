#pragma once
#include"quanbu.h"

#define ROWq 3
#define COLq 3


class sanziqi
{
public:
	//��ʼ������
	void kongge(char a1[ROWq][COLq], int row, int col);

	//��ӡ����
	void QIPANG(char a1[ROWq][COLq], int row, int col);

	//���
	void wanjia(char a1[ROWq][COLq], int row, int col);

	//����
	void diannao(char a1[ROWq][COLq], int row, int col);

	//�ж���Ӯ
	char shuying(char a1[ROWq][COLq], int row, int col);

	void meun();


	void game();

	void play();

private:

};




