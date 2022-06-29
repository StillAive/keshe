#include"doplayer.h"

void doplayer::loadGame(players* pc)
{
	FILE* pf = fopen("���.txt", "rb");
	if (pf == NULL)
	{
		perror("loadContact::fopen");
		return;
	}

	playersinfo tmp = { 0 };
	while (fread(&tmp, sizeof(playersinfo), 1, pf))
	{
		
		pc->people[pc->isz] = tmp;
		pc->isz++;
	}

	fclose(pf);
	pf = NULL;
}
void doplayer::inGame(players* pc)//��ʼ����ҵ�Ԫ
{
	assert(pc);
	pc->isz = 0;
	pc->icapacity = DEFAULT_SZ;
	memset(pc->people, 0, sizeof(pc->people));

	if (pc->people == NULL)
	{
		perror("initContact::malloc");
		return;
	}
	memset(pc->people, 0, pc->icapacity * sizeof(playersinfo));

	loadGame(pc);
}//ljm
void doplayer::saveGame(const players* pc)
{
	FILE* pf = fopen("���.txt", "wb");
	if (pf == NULL)
	{
		perror("savecontact::fopen");
		return;
	}
	int i = 0;
	for (int i = 0; i < pc->isz; i++)
	{
		fwrite(pc->people + i, sizeof(playersinfo), 1, pf); //������һ����Ϊ contact.dat ���ļ������������������ݴ洢�����С����������� Gameinfo Ԫ�أ��������԰����κ��������͡�
														 //ÿ��дһ����дpc->sz��
	}

	fclose(pf);
	pf = NULL;
}
//30

void doplayer::menu1()//�˵�
{

	printf("----------------���������Ϣҳ��--------------\n");
	printf("----------------------------------------------\n");
	printf("-------1.���������Ϣ     2.ɾ�������Ϣ------\n");
	printf("-------3.��ҳ�ֵ������   4.���ͨ��������----\n");
	printf("-------5.��һ�Ծ������   6.������������Ϣ--\n");
	printf("-------7.�Ǽ������Ϣ     0.�˳�--------------\n");
	printf("----------------------------------------------\n");
	printf("----------------------------------------------\n");
}
void doplayer::addGame(players* pc)//�����Ϸ��Ԫ
{
	assert(pc);


	printf("������������֣�");
	scanf("%s", pc->people[pc->isz].playersname);
	printf("����������Ա�");
	scanf("%s", pc->people[pc->isz].sex);
	printf("�����������Ϸʱ����");
	scanf("%d", &pc->people[pc->isz].time);
	printf("�������ֵ���");
	scanf("%d", &pc->people[pc->isz].money);
	printf("������ͨ�ش�����");
	scanf("%d", &pc->people[pc->isz].pass);
	pc->isz++;
	printf("����ɹ���\n");
}//xwh
int FindByName(const players* pc, char name[])
{
	assert(pc);
	for (int i = 0; i < pc->isz; i++)
	{
		if (0 == strcmp(pc->people[i].playersname, name))
		{
			return i;
		}
	}
	return -1;
}
void doplayer::delGame(players* pc)//ɾ�����
{
	assert(pc);

	if (pc->isz == 0)
	{
		printf("����ң��޷�ִ��\n");
		return;
	}

	char name[NAME_MAX] = { 0 };
	printf("���������������");
	scanf("%s", name);
	int pow = FindByName(pc, name);

	if (-1 == FindByName(pc, name))
	{
		printf("δ�ҵ������\n");
		return;
	}

	for (int i = pow; i < pc->isz - 1; i++)
	{
		pc->people[i] = pc->people[i + 1];
	}
	pc->isz--;
	printf("ɾ���ɹ�!\n");
}
void doplayer::searchGame(players* pc)//�������
{
	assert(pc);

	if (pc->isz == 0)
	{
		printf("����ң��޷�ִ��\n");
		return;
	}

	char name[NAME_MAX] = { 0 };
	printf("������������");
	scanf("%s", name);
	int pow = FindByName(pc, name);

	if (-1 == FindByName(pc, name))
	{
		printf("δ�ҵ������\n");
		return;
	}

	printf("%-5s %-20s %-20s %-20s %-20s\n",
		"����",
		"�Ա�",
		"��Ϸ����",
		"��ֵ����",
		"ͨ�ش���");

	printf("%-5s %-20s %-20d %-20d %-20d\n",

		pc->people[pow].playersname,
		pc->people[pow].sex,
		pc->people[pow].time,
		pc->people[pow].money,
		pc->people[pow].pass);



	printf("��%d��\n", pc->isz);
}
//70

void doplayer::modifyGame1(players* pc) //��ҳ�ֵ������   
{
	assert(pc);
	playersinfo tmp;
	for (int i = 0; i < pc->isz - 1; i++)
	{
		for (int j = 0; j < pc->isz - 1 - i; j++)
		{
			if (pc->people[j].money < pc->people[j + 1].money)
			{
				tmp = pc->people[j];
				pc->people[j] = pc->people[j + 1];
				pc->people[j + 1] = tmp;
			}
		}
	}

	printf("%-5s %-20s %-20s %-20s %-20s\n",
		"����",
		"�Ա�",
		"��Ϸ����",
		"��ֵ����",
		"ͨ�ش���");

	for (int i = 0; i < pc->isz; i++)
	{
		printf("%-5s %-20s %-20d %-20d %-20d\n",
			pc->people[i].playersname,
			pc->people[i].sex,
			pc->people[i].time,
			pc->people[i].money,
			pc->people[i].pass);
	}


	printf("��%d��\n", pc->isz);
}
void doplayer::modifyGame2(players* pc) //���ͨ��������
{
	assert(pc);
	playersinfo tmp;
	for (int i = 0; i < pc->isz - 1; i++)
	{
		for (int j = 0; j < pc->isz - 1 - i; j++)
		{
			if (pc->people[j].pass < pc->people[j + 1].pass)  
			{
				tmp = pc->people[j];
				pc->people[j] = pc->people[j + 1];
				pc->people[j + 1] = tmp;
			}
		}
	}

	printf("%-5s %-20s %-20s %-20s %-20s\n",
		"����",
		"�Ա�",
		"��Ϸ����",
		"��ֵ����",
		"ͨ�ش���");

	for (int i = 0; i < pc->isz; i++)
	{
		printf("%-5s %-20s %-20d %-20d %-20d\n",
			pc->people[i].playersname,
			pc->people[i].sex,
			pc->people[i].time,
			pc->people[i].money,
			pc->people[i].pass);
	}


	printf("��%d��\n", pc->isz);
}
void doplayer::modifyGame3(players* pc) //��һ�Ծ������
{
	assert(pc);
	playersinfo tmp;
	for (int i = 0; i < pc->isz - 1; i++)
	{
		for (int j = 0; j < pc->isz - 1 - i; j++)
		{
			if (pc->people[j].time< pc->people[j + 1].time) 
			{
				tmp = pc->people[j];
				pc->people[j] = pc->people[j + 1];
				pc->people[j + 1] = tmp;
			}
		}
	}

	printf("%-5s %-20s %-20s %-20s %-20s\n",
		"����",
		"�Ա�",
		"��Ϸ����",
		"��ֵ����",
		"ͨ�ش���");

	for (int i = 0; i < pc->isz; i++)
	{
		printf("%-5s %-20s %-20d %-20d %-20d\n",
			pc->people[i].playersname,
			pc->people[i].sex,
			pc->people[i].time,
			pc->people[i].money,
			pc->people[i].pass);
	}


	printf("��%d��\n", pc->isz);
}
void doplayer::clearGame(players* pc)//����������
{
	assert(pc);
	pc->isz = 0;
	memset(pc->people, 0, sizeof(pc->people));

	printf("��ճɹ���\n");
}
void doplayer::printGame(players* pc)//��ӡ���
{
	assert(pc);


	if (pc->isz == 0)
	{
		printf("������ң�\n");
		return;
	}


	printf("%-5s %-20s %-20s %-20s %-20s\n",
		"����",
		"�Ա�",
		"��Ϸ����",
		"��ֵ����",
		"ͨ�ش���");

	for (int i = 0; i < pc->isz; i++)
	{
		printf("%-5s %-20s %-20d %-20d %-20d\n",
			pc->people[i].playersname,
			pc->people[i].sex,
			pc->people[i].time,
			pc->people[i].money,
			pc->people[i].pass);
	}

	printf("��%d��\n", pc->isz);
}
//130






