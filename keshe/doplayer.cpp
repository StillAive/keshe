#include"doplayer.h"

void doplayer::loadGame(players* pc)
{
	FILE* pf = fopen("玩家.txt", "rb");
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
void doplayer::inGame(players* pc)//初始化玩家单元
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
	FILE* pf = fopen("玩家.txt", "wb");
	if (pf == NULL)
	{
		perror("savecontact::fopen");
		return;
	}
	int i = 0;
	for (int i = 0; i < pc->isz; i++)
	{
		fwrite(pc->people + i, sizeof(playersinfo), 1, pf); //将创建一个名为 contact.dat 的文件，并将缓冲区的内容存储到其中。缓冲区包含 Gameinfo 元素，但它可以包含任何其他类型。
														 //每次写一个，写pc->sz个
	}

	fclose(pf);
	pf = NULL;
}
//30

void doplayer::menu1()//菜单
{

	printf("----------------管理玩家信息页面--------------\n");
	printf("----------------------------------------------\n");
	printf("-------1.查找玩家信息     2.删除玩家信息------\n");
	printf("-------3.玩家充值额排序   4.玩家通关数排序----\n");
	printf("-------5.玩家活跃度排序   6.清空所有玩家信息--\n");
	printf("-------7.登记玩家信息     0.退出--------------\n");
	printf("----------------------------------------------\n");
	printf("----------------------------------------------\n");
}
void doplayer::addGame(players* pc)//添加游戏单元
{
	assert(pc);


	printf("请输入玩家名字：");
	scanf("%s", pc->people[pc->isz].playersname);
	printf("请输入玩家性别：");
	scanf("%s", pc->people[pc->isz].sex);
	printf("请输入玩家游戏时长：");
	scanf("%d", &pc->people[pc->isz].time);
	printf("请输入充值数额：");
	scanf("%d", &pc->people[pc->isz].money);
	printf("请输入通关次数：");
	scanf("%d", &pc->people[pc->isz].pass);
	pc->isz++;
	printf("加入成功！\n");
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
void doplayer::delGame(players* pc)//删除玩家
{
	assert(pc);

	if (pc->isz == 0)
	{
		printf("无玩家，无法执行\n");
		return;
	}

	char name[NAME_MAX] = { 0 };
	printf("请输入玩家姓名：");
	scanf("%s", name);
	int pow = FindByName(pc, name);

	if (-1 == FindByName(pc, name))
	{
		printf("未找到该玩家\n");
		return;
	}

	for (int i = pow; i < pc->isz - 1; i++)
	{
		pc->people[i] = pc->people[i + 1];
	}
	pc->isz--;
	printf("删除成功!\n");
}
void doplayer::searchGame(players* pc)//查找玩家
{
	assert(pc);

	if (pc->isz == 0)
	{
		printf("无玩家，无法执行\n");
		return;
	}

	char name[NAME_MAX] = { 0 };
	printf("请输入姓名：");
	scanf("%s", name);
	int pow = FindByName(pc, name);

	if (-1 == FindByName(pc, name))
	{
		printf("未找到该玩家\n");
		return;
	}

	printf("%-5s %-20s %-20s %-20s %-20s\n",
		"姓名",
		"性别",
		"游戏次数",
		"充值数额",
		"通关次数");

	printf("%-5s %-20s %-20d %-20d %-20d\n",

		pc->people[pow].playersname,
		pc->people[pow].sex,
		pc->people[pow].time,
		pc->people[pow].money,
		pc->people[pow].pass);



	printf("共%d人\n", pc->isz);
}
//70

void doplayer::modifyGame1(players* pc) //玩家充值额排序   
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
		"姓名",
		"性别",
		"游戏次数",
		"充值数额",
		"通关次数");

	for (int i = 0; i < pc->isz; i++)
	{
		printf("%-5s %-20s %-20d %-20d %-20d\n",
			pc->people[i].playersname,
			pc->people[i].sex,
			pc->people[i].time,
			pc->people[i].money,
			pc->people[i].pass);
	}


	printf("共%d人\n", pc->isz);
}
void doplayer::modifyGame2(players* pc) //玩家通关数排序
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
		"姓名",
		"性别",
		"游戏次数",
		"充值数额",
		"通关次数");

	for (int i = 0; i < pc->isz; i++)
	{
		printf("%-5s %-20s %-20d %-20d %-20d\n",
			pc->people[i].playersname,
			pc->people[i].sex,
			pc->people[i].time,
			pc->people[i].money,
			pc->people[i].pass);
	}


	printf("共%d人\n", pc->isz);
}
void doplayer::modifyGame3(players* pc) //玩家活跃度排序
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
		"姓名",
		"性别",
		"游戏次数",
		"充值数额",
		"通关次数");

	for (int i = 0; i < pc->isz; i++)
	{
		printf("%-5s %-20s %-20d %-20d %-20d\n",
			pc->people[i].playersname,
			pc->people[i].sex,
			pc->people[i].time,
			pc->people[i].money,
			pc->people[i].pass);
	}


	printf("共%d人\n", pc->isz);
}
void doplayer::clearGame(players* pc)//清空所有玩家
{
	assert(pc);
	pc->isz = 0;
	memset(pc->people, 0, sizeof(pc->people));

	printf("清空成功！\n");
}
void doplayer::printGame(players* pc)//打印玩家
{
	assert(pc);


	if (pc->isz == 0)
	{
		printf("暂无玩家！\n");
		return;
	}


	printf("%-5s %-20s %-20s %-20s %-20s\n",
		"姓名",
		"性别",
		"游戏次数",
		"充值数额",
		"通关次数");

	for (int i = 0; i < pc->isz; i++)
	{
		printf("%-5s %-20s %-20d %-20d %-20d\n",
			pc->people[i].playersname,
			pc->people[i].sex,
			pc->people[i].time,
			pc->people[i].money,
			pc->people[i].pass);
	}

	printf("共%d人\n", pc->isz);
}
//130






