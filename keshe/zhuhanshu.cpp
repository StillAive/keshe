#include"zhuhanshu.h"

void zhuhanshu::caidan2()
{
	printf("*********** �賿������Ϸ����ϵͳ ***********\n");
	printf("*------------------------------------------*\n");
	printf("*-----------�������û������е�¼-----------*\n");
	printf("*-----------------0.�˳�����---------------*\n");
	printf("*------------------------------------------*\n");
	printf("********************************************\n");
}

void zhuhanshu::caidan()
{
	printf("----------  �賿������Ϸ����ϵͳ  ----------\n");
	printf("--------------------------------------------\n");
	printf("----------------1.������Ϸģʽ--------------\n");
	printf("----------------2.�������ģʽ--------------\n");
	printf("----------------0.�˳�����------------------\n");
	printf("--------------------------------------------\n");
}

zhuhanshu p;

doplayer tt;
players ggg;

guanli t;
Game gg;

player q;

sanziqi s;

saolei l;



void zhuhanshu::test()//���е��߼���ʵ��
{

	p.caidan2();

	tt.inGame(&ggg);
	t.inGame(&gg);

	int a = 10;
	int b = 0;
	int xunhao = 0;
	int put = 0;
	int input = -1;
	int iiput = -1;
	char name[20] = { 0 };
	

	printf("�������û������е�¼��\n");
	scanf("%s", name);
	

	if (strcmp(name, "0") == 0)
	{
		a = 0;
	}
	if (strcmp(name, "�����") == 0 || strcmp(name, "л���") == 0 || strcmp(name, "������") == 0)
	{
		a = 1;
		printf("��ӭ�����װ��Ĺ����ߣ�\n");
		printf("�������������ϵͳ��\n");
		Sleep(5000);
	}
	if (((strcmp(name, "�����") != 0) && (strcmp(name, "л���") != 0) && (strcmp(name, "������") != 0) ) && (strcmp(name, "0") != 0))
	{
		a = 3;
		printf("��ӭ�����װ�����ң�\n");
		printf("�����������ϵͳ��\n");
		Sleep(5000);

	}

	Sleep(100);//˯��0.1��
	system("cls");//����
	
	do
	{
		if (a != 0 && a != 2 && a != 3)
		{
			caidan();
			printf("ѡ�����ģʽ���ࣺ\n");
			a = 10;
			cin.clear();	//��������ַ��ͣ��������switch��ѭ������������Ҫ�������������
			cin.ignore(9999, '\n');  //clear�������״̬��Ȼ������ignore�����������
			scanf("%d", &a);
			Sleep(100);
			system("cls");
		}
	
		switch (a)
		{
			do
				{
			case 1:
				do
				{

					input = -1;
					t.menu();
					printf("�����룺\n");

					scanf("%d", &input);
					cin.clear();	//��������ַ��ͣ��������switch��ѭ������������Ҫ�������������
					cin.ignore(99999, '\n');  //clear�������״̬��Ȼ������ignore�����������
					switch (input)
					{
					case ADD:
						Sleep(100);
						system("cls");
						t.addGame(&gg);
						input = -1;
						break;
					case DEL:
						Sleep(100);
						system("cls");
						t.delGame(&gg);
						input = -1;
						break;
					case SEARCH:
						Sleep(100);
						system("cls");
						t.searchGame(&gg);
						input = -1;
						break;
					case REVISE:
						Sleep(100);
						system("cls");
						t.remakeGame(&gg);
						input = -1;
						break;
					case MODIFY:
						Sleep(100);
						system("cls");
						t.modifyGame(&gg);
						input = -1;
						break;
					case CLEAR:
						Sleep(100);
						system("cls");
						t.clearGame(&gg);
						input = -1;
						break;
					case PRINT:
						Sleep(100);
						system("cls");
						t.printGame(&gg);
						input = -1;
						break;
					case Exti:
						t.saveGame(&gg);
						printf("�˳�\n");
						break;
					default:
						printf("ѡ�����\n");
						Sleep(1000);
						system("cls");
						break;
					}
				} while (input);

				b = 0;
				Sleep(100);
				system("cls");
				printf("����123��ϵͳ����\n");
				printf("����1���ղŽ���\n");
				printf("��������������������ҽ���\n");
				scanf("%d", &b);

				Sleep(100);
				system("cls");
				} while (b == 1);
				if (b == 123)
				{
					a = 10;
					break;
				}

				do
				{
			case 2:
				do
				{
					iiput = -1;
					tt.menu1();
					printf("�����룺\n");

					scanf("%d", &iiput);
					cin.clear();	//��������ַ��ͣ��������switch��ѭ������������Ҫ�������������
					cin.ignore(99999, '\n');  //clear�������״̬��Ȼ������ignore�����������
					switch (iiput)
					{
					case 1:
						Sleep(100);
						system("cls");
						tt.searchGame(&ggg);
						iiput = -1;
						break;
					case 2:
						Sleep(100);
						system("cls");
						tt.delGame(&ggg);
						iiput = -1;
						break;
					case 3:
						Sleep(100);
						system("cls");
						tt.modifyGame1(&ggg);
						iiput = -1;
						break;
					case 4:
						Sleep(100);
						system("cls");
						tt.modifyGame2(&ggg);
						iiput = -1;
						break;
					case 5:
						Sleep(100);
						system("cls");
						tt.modifyGame3(&ggg);
						iiput = -1;
						break;
					case 6:
						Sleep(100);
						system("cls");
						tt.clearGame(&ggg);
						iiput = -1;
						break;
					case 7:
						Sleep(100);
						system("cls");
						tt.addGame(&ggg);
						iiput = -1;
						break;
					case 0:
						tt.saveGame(&ggg);
						printf("�˳�\n");
						break;
					default:
						printf("ѡ�����\n");
						Sleep(1000);
						system("cls");
						break;
					}
				} while (iiput);

				b = 0;
				Sleep(100);
				system("cls");
				printf("����123��ϵͳ����\n");
				printf("����1���ղŽ���\n");
				printf("����������������ҽ���\n");
				scanf("%d", &b);

				Sleep(100);
				system("cls");
			
				} while (b == 1);
				if (b == 123)
				{
					a = 10;
					break;
				}
			
			


		case 3:
			do
			{
				
				put = -1;
				q.menu();
				printf("�����룺\n");

				cin.clear();	//��������ַ��ͣ��������switch��ѭ������������Ҫ�������������
				cin.ignore(9999, '\n');  //clear�������״̬��Ȼ������ignore�����������
				scanf("%d", &put);


				switch (put)
				{
				case 1:

					system("cls");
					t.printGame(&gg);
					Sleep(5000);
					put = -1;
					break;
				case 2:
					Sleep(100);
					system("cls");

					t.printGame(&gg);
					q.choose();

					printf("��������Ϸ��Ų���ʼ��Ϸ��\n");
					cin.clear();	//��������ַ��ͣ��������switch��ѭ������������Ҫ�������������
					cin.ignore(9999, '\n');  //clear�������״̬��Ȼ������ignore�����������

					scanf("%d", &xunhao);

					switch (xunhao)
					{
					case 1:
						s.play();
						break;
					case 2:
						l.saoleilou();
						break;
					case 0:
						printf("�˳�\n");
						break;
					default:
						printf("�ù�����δ����\n");
						Sleep(1000);
						system("cls");
						break;
					}
				case 0:
					a = 0;
					printf("�˳�\n");
					break;
				default:
					printf("�������������\n");
					break;
				}
				Sleep(1000);
				system("cls");
			} while (put);
			break;


		case 0:
			printf("�˳�����\n");
			break;



		default:
			printf("ѡ�����\n");
			printf("���������룺\n");
			Sleep(3000);
			system("cls");
		}


	} while (a != 0);

}
//360


