#include"guanli.h"

void guanli::menu()//菜单
{

	printf("--------------管理者页面------------\n");
	printf("------------------------------------\n");
	printf("-------1.加游戏       2.删游戏------\n");
	printf("-------3.找游戏       4.修改游戏----\n");
	printf("-------5.游戏排序     6.清空游戏----\n");
	printf("-------7.游戏展示     0.退出--------\n");
	printf("------------------------------------\n");
	printf("------------------------------------\n");
}

void  guanli::checkCapacity(Contact* pc)
{
	//动态版本
	if (pc->sz == pc->capacity)
	{
		Peoinfo* tmp = (Peoinfo*)realloc(pc->people, (pc->capacity + 2) * sizeof(Peoinfo));
		if (tmp != NULL)
		{
			pc->people = tmp;
		}
		pc->capacity += 2;
		printf("增容成功！\n");
	}
}



void  guanli::loadContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		perror("loadContact::fopen");
		return;
	}

	Peoinfo tmp = { 0 };
	while (fread(&tmp, sizeof(Peoinfo), 1, pf))
	{
		checkCapacity(pc);
		pc->people[pc->sz] = tmp;
		pc->sz++;
	}

	fclose(pf);
	pf = NULL;
}


void guanli::inContact(Contact* pc)//初始化游戏单
{
	assert(pc);
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->people = (Peoinfo*)malloc(pc->capacity * sizeof(Peoinfo));

	if (pc->people == NULL)
	{
		perror("initContact::malloc");
		return;
	}
	memset(pc->people, 0, pc->capacity * sizeof(Peoinfo));

	loadContact(pc);
}






void guanli::addContact(Contact* pc)//添加游戏单
{
	assert(pc);

	//静态版本
	/*if (pc->sz == MAX)
	{
		printf("游戏已满\n");
		return;
	}*/

	checkCapacity(pc);

	printf("请输入新游戏序号：");
	scanf("%d", &pc->people[pc->sz].xuhao);
	printf("请输入新游戏名字：");
	scanf("%s", pc->people[pc->sz].gamename);
	printf("请输入新游戏大小：");
	scanf("%s", pc->people[pc->sz].size);
	pc->sz++;
	printf("加入成功！\n");
}


int FindByName(const Contact* pc, char name[])
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


void guanli::delContact(Contact* pc)//删除游戏
{
	assert(pc);

	if (pc->sz == 0)
	{
		printf("无游戏，无法执行\n");
		return;
	}

	char name[NAME_MAX] = { 0 };
	printf("请输入游戏姓名：");
	scanf("%s", name);
	int pow = FindByName(pc, name);


	if (-1 == FindByName(pc, name))
	{
		printf("未找到该游戏\n");
		return;
	}

	for (int i = pow; i < pc->sz - 1; i++)
	{
		pc->people[i] = pc->people[i + 1];
	}
	pc->sz--;
	printf("删除成功!\n");
}

void guanli::searchContact(Contact* pc)//查找联系人
{
	assert(pc);

	if (pc->sz == 0)
	{
		printf("无游戏，无法执行\n");
		return;
	}

	char name[NAME_MAX] = { 0 };
	printf("请输入姓名：");
	scanf("%s", name);
	int pow = FindByName(pc, name);


	if (-1 == FindByName(pc, name))
	{
		printf("未找到该游戏\n");
		return;
	}

	printf("该游戏为：");
	printf("%-5d %-20s %-5s\n",
		pc->people[pow].xuhao,
		pc->people[pow].gamename,
		pc->people[pow].size);
}

void guanli::remakeContact(Contact* pc)//修改游戏信息
{
	assert(pc);

	if (pc->sz == 0)
	{
		printf("无游戏，无法执行\n");
		return;
	}

	char name[NAME_MAX] = { 0 };
	printf("请输入姓名：");
	scanf("%s", name);
	int pow = FindByName(pc, name);


	if (-1 == FindByName(pc, name))
	{
		printf("未找到该游戏\n");
		return;
	}

	printf("请输入新游戏序号：");
	scanf("%d", &pc->people[pow].xuhao);
	printf("请输入新游戏名字：");
	scanf("%s", pc->people[pow].gamename);
	printf("请输入新游戏大小：");
	scanf("%s", pc->people[pow].size);



	printf("修改成功！\n");

}

void guanli::modifyContact(Contact* pc) //以名字排序所有游戏
{
	assert(pc);
	Peoinfo tmp;
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

	printf("调整成功！\n");
}

void guanli::sortContact(Contact* pc)//清空所有游戏
{
	assert(pc);
	pc->sz = 0;
	memset(pc->people, 0, sizeof(pc->people));

	printf("清空成功！\n");
}

void guanli::printContact(Contact* pc)//打印游戏
{
	assert(pc);


	if (pc->sz == 0)
	{
		printf("暂无游戏！\n");
		return;
	}


	printf("%-5s %-20s %-5s\n",
		"序号",
		"名称",
		"大小");

	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-5d %-20s %-5s\n",
			pc->people[i].xuhao,
			pc->people[i].gamename,
			pc->people[i].size);
	}

	printf("共%d款游戏\n", pc->sz);
}

void guanli::savecontact(const Contact* pc)
{
	FILE* pf = fopen("contact.dat", "wb");
	if (pf == NULL)
	{
		perror("savecontact::fopen");
		return;
	}
	int i = 0;
	for (int i = 0; i < pc->sz; i++)
	{
		fwrite(pc->people + i, sizeof(Peoinfo), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}

