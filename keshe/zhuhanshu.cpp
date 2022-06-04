#include"zhuhanshu.h"

void zhuhanshu::caidan()
{
	printf("----------凌晨三分游戏管理系统--------\n");
	printf("--------------------------------------\n");
	printf("---------------1.管理者模式-----------\n");
	printf("---------------2.玩家模式-------------\n");
	printf("---------------0.退出界面-------------\n");
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
	
	printf("选择进入模式种类：\n");
	scanf("%d", &a);
	t.inContact(&con);
	Sleep(100);//睡眠0.1秒
	system("cls");//清屏


	do
	{
		if (a == 10)
		{
			caidan();
			printf("选择进入模式种类：\n");
			cin.clear();	//如果输入字符型，将会出现switch死循环，所以我们要清楚缓冲区，用
			cin.ignore(9999, '\n');  //clear清除错误状态，然后再用ignore清除缓冲区。
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
						printf("请输入：\n");
	
						scanf("%d", &input);
						cin.clear();	//如果输入字符型，将会出现switch死循环，所以我们要清楚缓冲区，用
						cin.ignore(99999, '\n');  //clear清除错误状态，然后再用ignore清除缓冲区。
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
							printf("退出\n");
							break;
						default:
							printf("选择错误\n");
							Sleep(1000);
							system("cls");
							break;
						}
					} while (input);



					b = 0;



					Sleep(100);
					system("cls");
					printf("输入123直接退出\n");
					printf("输入1返回上一界面\n");
					printf("输入其他数据则到达下一界面\n");
					scanf("%d", &b);
				
					Sleep(100);
					system("cls");
				} while (b == 1);
				if (b == 123)
				{
					printf("退出成功\n");
					break;
				}

			case 2:
				do
				{
					put = -1;
					q.menu();
					printf("请输入：\n");

					cin.clear();	//如果输入字符型，将会出现switch死循环，所以我们要清楚缓冲区，用
					cin.ignore(9999, '\n');  //clear清除错误状态，然后再用ignore清除缓冲区。
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

						printf("请输入游戏序号并开始游戏：\n");
						cin.clear();	//如果输入字符型，将会出现switch死循环，所以我们要清楚缓冲区，用
						cin.ignore(9999, '\n');  //clear清除错误状态，然后再用ignore清除缓冲区。

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
							printf("该功能暂未开放\n");
							Sleep(1000);
							system("cls");
							break;
						}
					case 0:
						printf("退出\n");
						break;
					default:
						printf("输入错误，请重试\n");
						break;
					}
					Sleep(1000);
					system("cls");
				} while (put);
				break;


			case 0:
				printf("退出界面\n");
				break;



			default:
				printf("选择错误\n");
				printf("请重新输入：\n");
				Sleep(3000);
				system("cls");
			} 

		
	}while (a == 10);

}



