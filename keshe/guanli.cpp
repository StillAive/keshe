#include"guanli.h"


void  guanli::checkCapacity(Game* pc)
{
	if (pc->sz == pc->capacity)
	{
		Gameinfo* tmp = (Gameinfo*)realloc(pc->people, (pc->capacity + 2) * sizeof(Gameinfo));
		if (tmp != NULL)
		{
			pc->people = tmp;
		}
		pc->capacity += 2;
		printf("���ݳɹ���\n");
	}
}
void  guanli::loadGame(Game* pc)
{
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("loadGame::fopen");
		return;
	}

	Gameinfo tmp = { 0 };
	while (fread(&tmp, sizeof(Gameinfo), 1, pf))
	{
		checkCapacity(pc);
		pc->people[pc->sz] = tmp;
		pc->sz++;
	}

	fclose(pf);
	pf = NULL;
}
void guanli::saveGame(const Game* pc)
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("saveGame::fopen");
		return;
	}
	int i = 0;
	for (int i = 0; i < pc->sz; i++)
	{
		fwrite(pc->people + i, sizeof(Gameinfo), 1, pf); //������һ����Ϊ contact.dat ���ļ������������������ݴ洢�����С����������� Gameinfo Ԫ�أ��������԰����κ��������͡�
														 //ÿ��дһ����дpc->sz��
	}

	fclose(pf);
	pf = NULL;
}
void guanli::inGame(Game* pc)//��ʼ����Ϸ��Ԫ
{
	assert(pc);
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->people = (Gameinfo*)malloc(pc->capacity * sizeof(Gameinfo));

	if (pc->people == NULL)
	{
		perror("initContact::malloc");
		return;
	}
	memset(pc->people, 0, pc->capacity * sizeof(Gameinfo));

	loadGame(pc);
}//ljm
//50


void guanli::menu()//�˵�
{

	printf("-----------������Ϸ��Ϣҳ��---------\n");
	printf("------------------------------------\n");
	printf("-------1.����Ϸ       2.ɾ��Ϸ------\n");
	printf("-------3.����Ϸ       4.�޸���Ϸ----\n");
	printf("-------5.��Ϸ����     6.�����Ϸ----\n");
	printf("-------7.��Ϸչʾ     0.�˳�--------\n");
	printf("------------------------------------\n");
	printf("------------------------------------\n");
}
void guanli::addGame(Game* pc)//�����Ϸ��Ԫ
{
	assert(pc);
	checkCapacity(pc);

	printf("����������Ϸ��ţ�");
	scanf("%d", &pc->people[pc->sz].xuhao);
	printf("����������Ϸ���֣�");
	scanf("%s", pc->people[pc->sz].gamename);
	printf("����������Ϸ��С��");
	scanf("%s", pc->people[pc->sz].size);
	pc->sz++;
	printf("����ɹ���\n");
}//xwh
int FindByName(const Game* pc, char name[])
{
	assert(pc);
	for (int i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(pc->people[i].gamename, name))
		{
			return i;
		}
	}
	return -1;
}
void guanli::delGame(Game* pc)//ɾ����Ϸ
{
	assert(pc);

	if (pc->sz == 0)
	{
		printf("����Ϸ���޷�ִ��\n");
		return;
	}

	char name[NAME_MAX] = { 0 };
	printf("��������Ϸ������");
	scanf("%s", name);
	int pow = FindByName(pc, name);

	if (-1 == FindByName(pc, name))
	{
		printf("δ�ҵ�����Ϸ\n");
		return;
	}

	for (int i = pow; i < pc->sz - 1; i++)
	{
		pc->people[i] = pc->people[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�!\n");
}
void guanli::searchGame(Game* pc)//������Ϸ
{
	assert(pc);

	if (pc->sz == 0)
	{
		printf("����Ϸ���޷�ִ��\n");
		return;
	}

	char name[NAME_MAX] = { 0 };
	printf("������������");
	scanf("%s", name);
	int pow = FindByName(pc, name);

	if (-1 == FindByName(pc, name))
	{
		printf("δ�ҵ�����Ϸ\n");
		return;
	}

	printf("����ϷΪ��");
	printf("%-5d %-20s %-5s\n",
		pc->people[pow].xuhao,
		pc->people[pow].gamename,
		pc->people[pow].size);
}
void guanli::remakeGame(Game* pc)//�޸���Ϸ��Ϣ
{
	assert(pc);

	if (pc->sz == 0)
	{
		printf("����Ϸ���޷�ִ��\n");
		return;
	}

	char name[NAME_MAX] = { 0 };
	printf("������������");
	scanf("%s", name);
	int pow = FindByName(pc, name);


	if (-1 == FindByName(pc, name))
	{
		printf("δ�ҵ�����Ϸ\n");
		return;
	}

	printf("����������Ϸ��ţ�");
	scanf("%d", &pc->people[pow].xuhao);
	printf("����������Ϸ���֣�");
	scanf("%s", pc->people[pow].gamename);
	printf("����������Ϸ��С��");
	scanf("%s", pc->people[pow].size);



	printf("�޸ĳɹ���\n");

}
//110


void guanli::modifyGame(Game* pc) //����������������Ϸ
{
	assert(pc);
	Gameinfo tmp;
	for (int i = 0; i < pc->sz - 1; i++)
	{
		for (int j = 0; j < pc->sz - 1 - i; j++)
		{
			if (pc->people[j].xuhao - pc->people[j + 1].xuhao > 0)
			{
				tmp = pc->people[j];
				pc->people[j] = pc->people[j + 1];
				pc->people[j + 1] = tmp;
			}
		}
	}

	printf("�����ɹ���\n");
}
void guanli::clearGame(Game* pc)//���������Ϸ
{
	assert(pc);
	pc->sz = 0;
	memset(pc->people, 0, sizeof(pc->people));

	printf("��ճɹ���\n");
}
void guanli::printGame(Game* pc)//��ӡ��Ϸ
{
	assert(pc);


	if (pc->sz == 0)
	{
		printf("������Ϸ��\n");
		return;
	}


	printf("%-5s %-20s %-5s\n",
		"���",
		"����",
		"��С");

	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-5d %-20s %-5s\n",
			pc->people[i].xuhao,
			pc->people[i].gamename,
			pc->people[i].size);
	}

	printf("��%d����Ϸ\n", pc->sz);
}
//30


