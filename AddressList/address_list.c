#include"contact.h"
void menu()
{
	printf("-----------------------通讯录管理--------------------\n");
	printf("----------------------0、退出------------------------\n");
	printf("-----------------1、添加联系人信息------------------\n");
	printf("-----------------2、删除联系人信息-----------------\n");
	printf("-----------------3.查找联系人信息-------------------\n");
	printf("----------------4、修改联系人信息------------------\n");
	printf("----------------5、显示联系人信息------------------\n");
	printf("----------------6、清空所有联系人------------------\n");
	printf("--------------7、按姓名对联系人排序----------------\n");
	printf("----------------------请选择------------------------\n");
}
void init(pcon p)//初始化通讯录  
{
	memset(p->student, 0, SIZE*sizeof(contact));//用 0 将结构体中成员信息进行初始化  
	p->count = 0;
}
//因为后边几个函数中都用姓名查找一个联系人，所以单独写一个查找函数方便使用  
int search(pcon p)
{
	int i = 0;
	char name[15];
	scanf("%s", name);
	for (i = 0;i < p->count;i++)
	{
		if (strcmp(p->student[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void add_people(pcon p)//录入联系人信息  
{
	if ((p->count) >= SIZE)
	{
		printf("通讯录已满！\n");
		return;
	}
	printf("请输入姓名：\n");
	scanf("%s", p->student[p->count].name);
	printf("请输入性别：\n");
	scanf("%s", p->student[p->count].sex);
	printf("请输入年龄：\n");
	scanf("%d", &(p->student[p->count].age));
	printf("请输入电话号码：\n");
	scanf("%s", p->student[p->count].tel);
	printf("请输入地址：\n");
	scanf("%s", p->student[p->count].address);
	printf("添加联系人成功\n");
	p->count++;
}
void find_people(pcon p)//查找一个联系人，并输出他的所有信息  
{
	printf("请输入要查找的人的姓名：\n");
	int ret = search(p);
	if (ret != -1)
	{
		printf("    name       sex     age          tel         address      \n");
		printf("%10s   %5s   %5d   %13s   %8s \n",
			p->student[ret].name,
			p->student[ret].sex,
			p->student[ret].age,
			p->student[ret].tel,
			p->student[ret].address);
	}
	else
		printf("联系人不存在!\n ");
}

void delete_people(pcon p)//删除某联系人信息  
{
	 int i = 0;
	 printf("请输入要删除的人的姓名：\n");
	 int ret = search(p);
	 if (ret != -1)
	  {
	       for (i = ret;i < p->count;i++)
		      {
		         p->student[i] = p->student[i + 1];
		      }
		   printf("删除成功！\n");
	  }
	 else
     printf("联系人不存在！\n");
}

void change_people(pcon p)//修改联系人信息  
{
	printf("请输入要修改的人的姓名：\n");
	int ret = search(p);
	if (ret != -1)
	{
		printf("请把姓名修改为：\n");
		scanf("%s", &(p->student[ret].name));
		printf("请把性别修改为：\n");
		scanf("%s", &(p->student[ret].sex));
		printf("请把年龄修改为：\n");
		scanf("%d", &(p->student[ret].age));
		printf("请把电话修改为：\n");
		scanf("%s", &(p->student[ret].tel));
		printf("请把地址修改为：\n");
		scanf("%s", &(p->student[ret].address));
	}
	else
	{
	  printf("联系人不存在！\n");
	}
}

void show_people(pcon p)//显示所有联系人信息  
{
	int i = 0;
	printf("    name       sex     age          tel         address      \n");
	for (i = 0;i < p->count;i++)
	{
		printf("%10s   %5s   %5d   %13s   %8s \n",
			p->student[i].name,
			p->student[i].sex,
			p->student[i].age,
			p->student[i].tel,
			p->student[i].address);
	}
}

void empty_people(pcon p)//清空通讯录  
{
	p->count = 0;
}

void sort_people(pcon p)//按姓名对联系人排序,并输出  
{
	int i = 0, j = 0;
	contact tmp = { 0 };
	for (i = 0;i < p->count - 1;i++)
	{
		for (j = 0;j < (p->count) - 1 - i;j++)
		{
			if (strcmp(p->student[j].name, p->student[j + 1].name)>0)//按姓名降序排列  
			{
				tmp = p->student[j];
				p->student[j] = p->student[j + 1];
				p->student[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int input = 1;
	people  count;
	init(&count);
	while (input)
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1: 
			add_people(&count);
			break;
		case 2:
			delete_people(&count);
			break;
		case 3:
			find_people(&count);
			break;
		case 4:
			change_people(&count);
			break;
		case 5:
			show_people(&count);
			break;
		case 6:
			empty_people(&count);
			break;
		case 7:
			sort_people(&count);
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("输入错误！");
			break;
		}
	}
	system("pause");
	return 0;
}
