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
	void menu();//�˵�
	void checkCapacity(Game* pc);//�鿴�ڴ�
	void inGame(Game* pc);//��ʼ����Ϸ��Ԫ
	void addGame(Game* pc);//�����Ϸ������Ϣ
	void delGame(Game* pc);//ɾ����Ϸ
	void searchGame(Game* pc);//������Ϸ
	void remakeGame(Game* pc);//�޸���Ϸ��Ϣ
	void modifyGame(Game* pc); //���������������Ϸ
	void clearGame(Game* pc);//���������Ϸ
	void printGame(Game* pc);//��ӡ��Ϸ
	void loadGame(Game* pc);//��ȡ����
	void saveGame(const Game* pc);//��¼����;
};

