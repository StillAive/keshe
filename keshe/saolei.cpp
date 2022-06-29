


#include"saolei.h"


void saolei::quyu(char mine[ROWS][COLS], int rows, int cols, char n)//����rows��cols���ַ�n�ڶ�ά������
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
			printf("%c ", show[i][j]);//��ʾshow�������ͼ��
		}
		printf("\n");
	}
	printf("\n");
}


void saolei::buzhi(char mine[ROWS][COLS], int row, int col)//�ı�һ��mine�����е��ַ�
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

int zhouweilei(char mine[ROWS][COLS], int x, int y)//��Χ�׵�����
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
	while (win < row * col - shuliang)//��row * col - shuliang�����׿ո�
	{
		printf("���������꣺");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("��\n");
				xianshi(mine, ROW, COL);//����ʱ����ʾһ���׵Ĳ���
				printf("��Ϸ����\n");
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
			printf("����������\n");
			continue;
		}
		win++;
	}
	if (win == row * col - shuliang)
	{
		printf("Ӯ��\n");
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

	quyu(mine, ROWS, COLS, '0');//����
	quyu(show, ROWS, COLS, '*');//������


	buzhi(mine, ROW, COL);//�ı�����

	xianshi(show, ROW, COL);//�ı���õ��ַ����������ѡ��ֱ����ʾ������show�ĳ�mine��

	play(mine, show, ROW, COL);
}


void saolei::saoleilou()
{

	int xuanze = 0;
	srand((unsigned int)time(NULL));
	do
	{
		meun();
		printf("�����룺");
		scanf("%d", &xuanze);
		switch (xuanze)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (xuanze);
}

