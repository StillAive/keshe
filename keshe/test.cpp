#include"saolei.h"
#include"sanziqi.h"
#include"guanli.h"
#include"player.h"

void caidan()
{
	printf("----------�賿������Ϸ����ϵͳ--------\n");
	printf("--------------------------------------\n");
	printf("---------------1.������ģʽ-----------\n");
	printf("---------------2.���ģʽ-------------\n");
	printf("---------------0.�˳�����-------------\n");
	printf("--------------------------------------\n");
}


guanli t;
Contact con;
sanziqi s;
saolei l;

int main()
{
	
	caidan();






	int a = 0;
	int b = 0;
	int xunhao = 0;
	int input = 0;
	int put = 0;


	
	

	printf("ѡ�����ģʽ���ࣺ\n");
	scanf("%d", &a);
	t.inContact(&con);
	
	cin.clear();	//��������ַ��ͣ��������switch��ѭ������������Ҫ�������������
	cin.ignore(9999, '\n');  //clear�������״̬��Ȼ������ignore�����������

	switch (a)
	{

		do
		{
			case 1:	
			do
			{
				t.menu();
				printf("�����룺\n");

				scanf("%d", &input);
				cin.clear();	//��������ַ��ͣ��������switch��ѭ������������Ҫ�������������
				cin.ignore(9999, '\n');  //clear�������״̬��Ȼ������ignore�����������
				switch (input)
				{
				case ADD:
					t.addContact(&con);
					break;
				case DEL:
					t.delContact(&con);
					break;
				case SEARCH:
					t.searchContact(&con);
					break;
				case REMAKE:
					t.remakeContact(&con);
					break;
				case MODIFY:
					t.modifyContact(&con);
					break;
				case SORT:
					t.sortContact(&con);
					break;
				case PRINT:
					t.printContact(&con);
					break;
				case Exti:
					t.savecontact(&con);
					printf("�˳�\n");
					break;
				default:
					printf("ѡ�����\n");
					break;
				}
			} while (input);
			printf("ѡ��������ģʽ����ֱ���˳���\n");
			printf("1.���ģʽ        0.ֱ���˳�\n");
			scanf("%d", &b);
			if (b == 1)
			{
				break;
			}
		} while (b == 1);
		if (b == 0)
		{
			printf("�˳��ɹ�\n");
			break;
		}

		case 2:
			player q;
			
			do
			{
				q.menu();
				printf("�����룺\n");


				scanf("%d", &put);
				cin.clear();	//��������ַ��ͣ��������switch��ѭ������������Ҫ�������������
				cin.ignore(9999, '\n');  //clear�������״̬��Ȼ������ignore�����������
				
				switch (put)
				{
				case 1:
					t.printContact(&con);
					break;
				case 2:
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
						break;
					}
					break;
				case 0:
					printf("�˳�\n");
					break;
				default:
					printf("�������������\n");
					break;
				}

			} while (put);

			break;


		case 0:
			printf("�˳�����\n");
			break;
		default:
			printf("ѡ�����\n");
			printf("�˳�����\n");
			break;
		
	}

}