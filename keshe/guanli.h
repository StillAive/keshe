#include"quanbu.h"
#define _CRT_SECURE_NO_DEPRECATE 1

#define MAX 1000

#define NAME_MAX 20

//ͨѶ¼��ʼ��Ĭ�ϴ�С
#define DEFAULT_SZ 3

enum Option//ö�ٳ���ʹ����ɶ�����ǿ
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
//}Contact;��̬�汾

typedef struct Contact
{
	Peoinfo* people;
	int sz;
	int capacity;
}Contact;

class guanli
{
public:
	void menu();//�˵�
	void checkCapacity(Contact* pc);//�鿴�ڴ�
	void inContact(Contact* pc);//��ʼ����Ϸ��
	void addContact(Contact* pc);//�����Ϸ������Ϣ
	void delContact(Contact* pc);//ɾ����Ϸ
	void searchContact(Contact* pc);//������Ϸ
	void remakeContact(Contact* pc);//�޸���Ϸ��Ϣ
	void modifyContact(Contact* pc); //���������������Ϸ
	void sortContact(Contact* pc);//���������Ϸ
	void printContact(Contact* pc);//��ӡ��Ϸ
	void loadContact(Contact* pc);//��ȡ����
	void savecontact(const Contact* pc);//��¼����;
	
private:

};

