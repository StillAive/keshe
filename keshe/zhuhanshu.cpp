#include"zhuhanshu.h"

void zhuhanshu::caidan2()
{
	printf("*********** 凌晨三分游戏管理系统 ***********\n");
	printf("*------------------------------------------*\n");
	printf("*-----------请输入用户名进行登录-----------*\n");
	printf("*-----------------0.退出界面---------------*\n");
	printf("*------------------------------------------*\n");
	printf("********************************************\n");
}

void zhuhanshu::caidan()
{
	printf("----------  凌晨三分游戏管理系统  ----------\n");
	printf("--------------------------------------------\n");
	printf("----------------1.管理游戏模式--------------\n");
	printf("----------------2.管理玩家模式--------------\n");
	printf("----------------0.退出界面------------------\n");
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



void zhuhanshu::test()//运行的逻辑的实现
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
	

	printf("请输入用户名进行登录：\n");
	scanf("%s", name);
	

	if (strcmp(name, "0") == 0)
	{
		a = 0;
	}
	if (strcmp(name, "李佳茗") == 0 || strcmp(name, "谢玮豪") == 0 || strcmp(name, "党俊刚") == 0)
	{
		a = 1;
		printf("欢迎您，亲爱的管理者！\n");
		printf("即将进入管理者系统！\n");
		Sleep(5000);
	}
	if (((strcmp(name, "李佳茗") != 0) && (strcmp(name, "谢玮豪") != 0) && (strcmp(name, "党俊刚") != 0) ) && (strcmp(name, "0") != 0))
	{
		a = 3;
		printf("欢迎您，亲爱的玩家！\n");
		printf("即将进入玩家系统！\n");
		Sleep(5000);

	}

	Sleep(100);//睡眠0.1秒
	system("cls");//清屏
	
	do
	{
		if (a != 0 && a != 2 && a != 3)
		{
			caidan();
			printf("选择进入模式种类：\n");
			a = 10;
			cin.clear();	//如果输入字符型，将会出现switch死循环，所以我们要清除缓冲区，用
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
				printf("输入123至系统界面\n");
				printf("输入1至刚才界面\n");
				printf("输入其他数据至管理玩家界面\n");
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
					printf("请输入：\n");

					scanf("%d", &iiput);
					cin.clear();	//如果输入字符型，将会出现switch死循环，所以我们要清楚缓冲区，用
					cin.ignore(99999, '\n');  //clear清除错误状态，然后再用ignore清除缓冲区。
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
						printf("退出\n");
						break;
					default:
						printf("选择错误\n");
						Sleep(1000);
						system("cls");
						break;
					}
				} while (iiput);

				b = 0;
				Sleep(100);
				system("cls");
				printf("输入123至系统界面\n");
				printf("输入1至刚才界面\n");
				printf("输入其他数据至玩家界面\n");
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
				printf("请输入：\n");

				cin.clear();	//如果输入字符型，将会出现switch死循环，所以我们要清楚缓冲区，用
				cin.ignore(9999, '\n');  //clear清除错误状态，然后再用ignore清除缓冲区。
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

					printf("请输入游戏序号并开始游戏：\n");
					cin.clear();	//如果输入字符型，将会出现switch死循环，所以我们要清除缓冲区，用
					cin.ignore(9999, '\n');  //clear清除错误状态，然后再用ignore清除缓冲区。

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
						printf("退出\n");
						break;
					default:
						printf("该功能暂未开放\n");
						Sleep(1000);
						system("cls");
						break;
					}
				case 0:
					a = 0;
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


	} while (a != 0);

}
//360


