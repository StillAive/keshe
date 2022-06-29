#pragma once
#include"quanbu.h"

#define ROWq 3
#define COLq 3


class sanziqi
{
public:
	//≥ı ºªØ∆Â≈Ã
	void kongge(char a1[ROWq][COLq], int row, int col);

	//¥Ú”°∆Â≈Ã
	void QIPANG(char a1[ROWq][COLq], int row, int col);

	//ÕÊº“
	void wanjia(char a1[ROWq][COLq], int row, int col);

	//µÁƒ‘
	void diannao(char a1[ROWq][COLq], int row, int col);

	//≈–∂œ ‰”Æ
	char shuying(char a1[ROWq][COLq], int row, int col);

	void meun();


	void game();

	void play();

private:

};




