#include"quanbu.h"
#define _CRT_SECURE_NO_DEPRECATE 1

#define MAX 1000

#define NAME_MAX 20

//ͨѶ¼��ʼ��Ĭ�ϴ�С
#define DEFAULT_SZ 3

enum Option
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

	char xuhao[NAME_MAX];
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
	void inContact(Contact* pc);//��ʼ��ͨѶ¼
	void addContact(Contact* pc);//�����ϵ��
	void delContact(Contact* pc);//ɾ����ϵ��
	void searchContact(Contact* pc);//������ϵ��
	void remakeContact(Contact* pc);//�޸���ϵ��
	void modifyContact(Contact* pc); //����������������ϵ��
	void sortContact(Contact* pc);//���������ϵ��
	void printContact(Contact* pc);//��ӡ��ϵ��
	void loadContact(Contact* pc);//��ȡ����
	void savecontact(const Contact* pc);//��¼����;
	
private:

};

