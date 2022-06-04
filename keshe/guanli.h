#include"quanbu.h"
#define _CRT_SECURE_NO_DEPRECATE 1

#define MAX 1000

#define NAME_MAX 20

//通讯录初始化默认大小
#define DEFAULT_SZ 3

enum Option//枚举常量使代码可读性增强
{
	Exti,
	ADD,
	DEL,
	SEARCH,
	REMAKE,
	MODIFY,
	SORT,
	PRINT
};


typedef struct Peoinfo
{
	int xuhao;
	char gamename[NAME_MAX];
	char size[MAX];
}Peoinfo;


//typedef struct Contact
//{
//	Peoinfo people[MAX];
//	int sz;
//}Contact;静态版本

typedef struct Contact
{
	Peoinfo* people;
	int sz;
	int capacity;
}Contact;

class guanli
{
public:
	void menu();//菜单
	void checkCapacity(Contact* pc);//查看内存
	void inContact(Contact* pc);//初始化游戏单
	void addContact(Contact* pc);//添加游戏和其信息
	void delContact(Contact* pc);//删除游戏
	void searchContact(Contact* pc);//查找游戏
	void remakeContact(Contact* pc);//修改游戏信息
	void modifyContact(Contact* pc); //以序号排序所有游戏
	void sortContact(Contact* pc);//清空所有游戏
	void printContact(Contact* pc);//打印游戏
	void loadContact(Contact* pc);//读取本地
	void savecontact(const Contact* pc);//记录本地;
	
private:

};

