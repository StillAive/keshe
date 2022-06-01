#include"sanziqi.h"

void sanziqi::kongge(char a1[ROWq][COLq], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			a1[i][j] = ' ';
		}
	}
}

void sanziqi::QIPANG(char a1[ROWq][COLq], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", a1[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void sanziqi::wanjia(char a1[ROWq][COLq], int row, int col) 
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("�����������λ�ã�\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (a1[x - 1][y - 1] == ' ')
			{
				a1[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("��ռ��\n");
				continue;
			}
		}
		else
		{
			printf("�������������\n");
		}
	}
}

void sanziqi::diannao(char a1[ROWq][COLq], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("������������λ�ã�\n");
		x = rand() % row;//0-2
		y = rand() % col;//0-2

		if (a1[x][y] == ' ')
		{
			a1[x][y] = '#';
			break;
		}
	}
}

static int pingju(char a1[ROWq][COLq], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (a1[i][j] == ' ')
			{
				return 1;
			}
		}
	}
	return 0;
}


char sanziqi::shuying(char a1[ROWq][COLq], int row, int col)
{
	int i = 0;

	for (i = 0; i < row; i++)
	{
		if (a1[i][0] == a1[i][1] && a1[i][1] == a1[i][2] && a1[i][0] != ' ')
		{
			return a1[i][0];
		}
	}

	for (i = 0; i < row; i++)
	{
		if (a1[0][i] == a1[1][i] && a1[1][i] == a1[2][i] && a1[0][i] != ' ')
		{
			return a1[0][i];
		}
	}

	if (a1[0][0] == a1[1][1] && a1[1][1] == a1[2][2] && a1[1][1] != ' ')
	{
		return a1[1][1];
	}

	if (a1[0][2] == a1[1][1] && a1[1][1] == a1[2][0] && a1[1][1] != ' ')
	{
		return a1[1][1];
	}

	if (pingju(a1, row, col) == 0)
	{
		return 'q';
	}
	return 'c';

}

void sanziqi::meun()
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

void sanziqi::game()
{
	char fu = 0;
	char braod[ROWq][COLq] = { 0 };
	//��ʼ��
	kongge(braod, ROWq, COLq);
	//����
	QIPANG(braod, ROWq, COLq);

	while (1)
	{
		//���
		wanjia(braod, ROWq, COLq);
		QIPANG(braod, ROWq, COLq);

		fu = shuying(braod, ROWq, COLq);
		if (fu != 'c')
		{
			break;
		}

		//����
		diannao(braod, ROWq, COLq);
		QIPANG(braod, ROWq, COLq);


		fu = shuying(braod, ROWq, COLq);
		if (fu != 'c')
		{
			break;
		}

	}

	printf("��Ϸ����\n");

	if (fu == '*')
	{
		printf("���Ӯ\n");
	}

	else if (fu == '#')
	{
		printf("����Ӯ\n");
	}

	else if (fu == 'p')
	{
		printf("ƽ��\n");
	}

	QIPANG(braod, ROWq, COLq);
}

void sanziqi::caidan()
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