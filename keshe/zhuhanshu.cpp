#include"zhuhanshu.h"

void zhuhanshu::caidan()
{
	printf("----------�賿������Ϸ����ϵͳ--------\n");
	printf("--------------------------------------\n");
	printf("---------------1.������ģʽ-----------\n");
	printf("---------------2.���ģʽ-------------\n");
	printf("---------------0.�˳�����-------------\n");
	printf("--------------------------------------\n");
}

zhuhanshu p;

guanli t;
Contact con;

player q;

sanziqi s;

saolei l;

void zhuhanshu::test()
{
	
	p.caidan();

	int a = 10;
	int b = 0;
	int xunhao = 0;
	int put = 0;
	int input = -1;
	
	printf("ѡ�����ģʽ���ࣺ\n");
	scanf("%d", &a);
	t.inContact(&con);
	Sleep(100);//˯��0.1��
	system("cls");//����


	do
	{
		if (a == 10)
		{
			caidan();
			printf("ѡ�����ģʽ���ࣺ\n");
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
							t.addContact(&con); 
							input = -1;
							break;
						case DEL:
							Sleep(100);
							system("cls");
							t.delContact(&con); 
							input = -1;
							break;
						case SEARCH:
							Sleep(100);
							system("cls");
							t.searchContact(&con); 
							input = -1;
							break;
						case REMAKE:
							Sleep(100);
							system("cls");
							t.remakeContact(&con); 
							input = -1;
							break;
						case MODIFY:
							Sleep(100);
							system("cls");
							t.modifyContact(&con); 
							input = -1;
							break;
						case SORT:
							Sleep(100);
							system("cls");
							t.sortContact(&con);
							input = -1;
							break;
						case PRINT:
							Sleep(100);
							system("cls");
							t.printContact(&con);
							input = -1;
							break;
						case Exti:
							t.savecontact(&con);
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
					printf("����123ֱ���˳�\n");
					printf("����1������һ����\n");
					printf("�������������򵽴���һ����\n");
					scanf("%d", &b);
				
					Sleep(100);
					system("cls");
				} while (b == 1);
				if (b == 123)
				{
					printf("�˳��ɹ�\n");
					break;
				}

			case 2:
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
						Sleep(1000);
						system("cls");
						t.printContact(&con);
						put = -1;
						break;
					case 2:
						Sleep(100);
						system("cls");

						t.printContact(&con);
						q.choose();

						printf("��������Ϸ��Ų���ʼ��Ϸ��\n");
						cin.clear();	//��������ַ��ͣ��������switch��ѭ������������Ҫ�������������
						cin.ignore(9999, '\n');  //clear�������״̬��Ȼ������ignore�����������

						scanf("%d", &xunhao);

						switch (xunhao)
						{
						case 1:
							s.caidan();
							break;
						case 2:
							l.saoleilou();
							break;
						default:
							printf("�ù�����δ����\n");
							Sleep(1000);
							system("cls");
							break;
						}
					case 0:
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

		
	}while (a == 10);

}



