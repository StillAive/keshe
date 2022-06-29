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
	void inGame(players* pc);//��ʼ����Ϸ��Ԫ
	void addGame(players* pc);//�����Ϸ������Ϣ

	void searchGame(players* pc);//������Ϸ
	void delGame(players* pc);//ɾ����Ϸ
	
	void modifyGame1(players* pc); //��ҳ�ֵ������;
	void modifyGame2(players* pc); //���ͨ��������
	void modifyGame3(players* pc); //��һ�Ծ������

	void clearGame(players* pc);//���������Ϸ
	void printGame(players* pc);//��ӡ��Ϸ

	void loadGame(players* pc);//��ȡ����
	void saveGame(const players* pc);//��¼����;
private:

};
