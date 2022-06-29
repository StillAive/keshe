


#include"saolei.h"


void saolei::quyu(char mine[ROWS][COLS], int rows, int cols, char n)//储存rows×cols的字符n在二维数组中
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = n;
		}
	}
}


void saolei::xianshi(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", show[i][j]);//显示show数组里的图案
		}
		printf("\n");
	}
	printf("\n");
}


void saolei::buzhi(char mine[ROWS][COLS], int row, int col)//改变一下mine数组中的字符
{
	int m = shuliang;
	int x = 0;
	int y = 0;
	while (m)
	{
		x = rand() % row + 1;
		y = rand() % row + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			m--;
		}
	}
}

int zhouweilei(char mine[ROWS][COLS], int x, int y)//周围雷的数量
{

	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] -
		8 * '0';
}


void saolei::play(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - shuliang)//有row * col - shuliang个非雷空格
	{
		printf("请输入坐标：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("死\n");
				xianshi(mine, ROW, COL);//死的时候显示一下雷的布局
				printf("游戏结束\n");
				break;
			}
			else
			{
				int m = zhouweilei(mine, x, y);
				show[x][y] = m + '0';
				xianshi(show, ROW, COL);
			}
		}
		else
		{
			printf("请重新输入\n");
			continue;
		}
		win++;
	}
	if (win == row * col - shuliang)
	{
		printf("赢了\n");
		xianshi(mine, ROW, COL);
	}
}


void saolei::meun()
{
	Sleep(5000);
	char a1[] = "******** 1.  play *******";
	char a2[] = "******** 0.  exit *******";
	char a3[] = "########          #######";
	char a4[] = "########          #######";
	int left1 = 0;
	int right1 = strlen(a1) - 1;
	int left2 = 0;
	int right2 = strlen(a2) - 1;
	while (left1 < right1 && left2 < right2)
	{
		a3[left1] = a1[left1];
		a3[right1] = a1[right1];
		a4[left2] = a2[left2];
		a4[right2] = a2[right2];

		printf("%s\n", a3);
		printf("%s\n", a4);

		left1++;
		right1--;
		left2++;
		right2--;

		Sleep(100);
		system("cls");
	}
	printf("%s\n", a3);
	printf("%s\n", a4);
}


void saolei::game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	quyu(mine, ROWS, COLS, '0');//雷区
	quyu(show, ROWS, COLS, '*');//覆盖区


	buzhi(mine, ROW, COL);//改变雷区

	xianshi(show, ROW, COL);//改变调用的字符串数组可以选择直接显示雷区（show改成mine）

	play(mine, show, ROW, COL);
}


void saolei::saoleilou()
{

	int xuanze = 0;
	srand((unsigned int)time(NULL));
	do
	{
		meun();
		printf("请输入：");
		scanf("%d", &xuanze);
		switch (xuanze)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (xuanze);
}

