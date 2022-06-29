#pragma once
#pragma once
#include"quanbu.h"
#define MAX 1000
#define NAME_MAX 20
#define DEFAULT_SZ 3




typedef struct playersinfo
{
	char playersname[NAME_MAX];
	char sex[MAX];
	int time;
	int money;
	int pass;
}playersinfo;

typedef struct players
{
	playersinfo people[MAX];
	int isz;
	int icapacity;
}players;




class doplayer
{
public:
	void menu1();
	void inGame(players* pc);//初始化游戏单元
	void addGame(players* pc);//添加游戏和其信息

	void searchGame(players* pc);//查找游戏
	void delGame(players* pc);//删除游戏
	
	void modifyGame1(players* pc); //玩家充值额排序;
	void modifyGame2(players* pc); //玩家通关数排序
	void modifyGame3(players* pc); //玩家活跃度排序

	void clearGame(players* pc);//清空所有游戏
	void printGame(players* pc);//打印游戏

	void loadGame(players* pc);//读取本地
	void saveGame(const players* pc);//记录本地;
private:

};
