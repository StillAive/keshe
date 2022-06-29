#include"quanbu.h"
#define _CRT_SECURE_NO_DEPRECATE 1
#define MAX 1000
#define NAME_MAX 20
#define DEFAULT_SZ 3



typedef struct Gameinfo
{
	int xuhao;
	char gamename[NAME_MAX];
	char size[MAX];
}Gameinfo;

typedef struct Game
{
	Gameinfo* people;
	int sz;
	int capacity;
}Game;

class guanli
{
public:
	void menu();//菜单
	void checkCapacity(Game* pc);//查看内存
	void inGame(Game* pc);//初始化游戏单元
	void addGame(Game* pc);//添加游戏和其信息
	void delGame(Game* pc);//删除游戏
	void searchGame(Game* pc);//查找游戏
	void remakeGame(Game* pc);//修改游戏信息
	void modifyGame(Game* pc); //以序号排序所有游戏
	void clearGame(Game* pc);//清空所有游戏
	void printGame(Game* pc);//打印游戏
	void loadGame(Game* pc);//读取本地
	void saveGame(const Game* pc);//记录本地;
};

