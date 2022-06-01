#include"saolei.h"
#include"sanziqi.h"
#include"guanli.h"
#include"player.h"

void caidan()
{
	printf("----------凌晨三分游戏管理系统--------\n");
	printf("--------------------------------------\n");
	printf("---------------1.管理者模式-----------\n");
	printf("---------------2.玩家模式-------------\n");
	printf("---------------0.退出界面-------------\n");
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


	
	

	printf("选择进入模式种类：\n");
	scanf("%d", &a);
	t.inContact(&con);
	
	cin.clear();	//如果输入字符型，将会出现switch死循环，所以我们要清楚缓冲区，用
	cin.ignore(9999, '\n');  //clear清除错误状态，然后再用ignore清除缓冲区。

	switch (a)
	{

		do
		{
			case 1:	
			do
			{
				t.menu();
				printf("请输入：\n");

				scanf("%d", &input);
				cin.clear();	//如果输入字符型，将会出现switch死循环，所以我们要清楚缓冲区，用
				cin.ignore(9999, '\n');  //clear清除错误状态，然后再用ignore清除缓冲区。
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
					printf("退出\n");
					break;
				default:
					printf("选择错误\n");
					break;
				}
			} while (input);
			printf("选择进入玩家模式或者直接退出：\n");
			printf("1.玩家模式        0.直接退出\n");
			scanf("%d", &b);
			if (b == 1)
			{
				break;
			}
		} while (b == 1);
		if (b == 0)
		{
			printf("退出成功\n");
			break;
		}

		case 2:
			player q;
			
			do
			{
				q.menu();
				printf("请输入：\n");


				scanf("%d", &put);
				cin.clear();	//如果输入字符型，将会出现switch死循环，所以我们要清楚缓冲区，用
				cin.ignore(9999, '\n');  //clear清除错误状态，然后再用ignore清除缓冲区。
				
				switch (put)
				{
				case 1:
					t.printContact(&con);
					break;
				case 2:
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
						break;
					}
					break;
				case 0:
					printf("退出\n");
					break;
				default:
					printf("输入错误，请重试\n");
					break;
				}

			} while (put);

			break;


		case 0:
			printf("退出界面\n");
			break;
		default:
			printf("选择错误\n");
			printf("退出界面\n");
			break;
		
	}

}