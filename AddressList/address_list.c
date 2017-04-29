#include"contact.h"
void menu()
{
	printf("-----------------------ͨѶ¼����--------------------\n");
	printf("----------------------0���˳�------------------------\n");
	printf("-----------------1�������ϵ����Ϣ------------------\n");
	printf("-----------------2��ɾ����ϵ����Ϣ-----------------\n");
	printf("-----------------3.������ϵ����Ϣ-------------------\n");
	printf("----------------4���޸���ϵ����Ϣ------------------\n");
	printf("----------------5����ʾ��ϵ����Ϣ------------------\n");
	printf("----------------6�����������ϵ��------------------\n");
	printf("--------------7������������ϵ������----------------\n");
	printf("----------------------��ѡ��------------------------\n");
}
void init(pcon p)//��ʼ��ͨѶ¼  
{
	memset(p->student, 0, SIZE*sizeof(contact));//�� 0 ���ṹ���г�Ա��Ϣ���г�ʼ��  
	p->count = 0;
}
//��Ϊ��߼��������ж�����������һ����ϵ�ˣ����Ե���дһ�����Һ�������ʹ��  
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
void add_people(pcon p)//¼����ϵ����Ϣ  
{
	if ((p->count) >= SIZE)
	{
		printf("ͨѶ¼������\n");
		return;
	}
	printf("������������\n");
	scanf("%s", p->student[p->count].name);
	printf("�������Ա�\n");
	scanf("%s", p->student[p->count].sex);
	printf("���������䣺\n");
	scanf("%d", &(p->student[p->count].age));
	printf("������绰���룺\n");
	scanf("%s", p->student[p->count].tel);
	printf("�������ַ��\n");
	scanf("%s", p->student[p->count].address);
	printf("�����ϵ�˳ɹ�\n");
	p->count++;
}
void find_people(pcon p)//����һ����ϵ�ˣ����������������Ϣ  
{
	printf("������Ҫ���ҵ��˵�������\n");
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
		printf("��ϵ�˲�����!\n ");
}

void delete_people(pcon p)//ɾ��ĳ��ϵ����Ϣ  
{
	 int i = 0;
	 printf("������Ҫɾ�����˵�������\n");
	 int ret = search(p);
	 if (ret != -1)
	  {
	       for (i = ret;i < p->count;i++)
		      {
		         p->student[i] = p->student[i + 1];
		      }
		   printf("ɾ���ɹ���\n");
	  }
	 else
     printf("��ϵ�˲����ڣ�\n");
}

void change_people(pcon p)//�޸���ϵ����Ϣ  
{
	printf("������Ҫ�޸ĵ��˵�������\n");
	int ret = search(p);
	if (ret != -1)
	{
		printf("��������޸�Ϊ��\n");
		scanf("%s", &(p->student[ret].name));
		printf("����Ա��޸�Ϊ��\n");
		scanf("%s", &(p->student[ret].sex));
		printf("��������޸�Ϊ��\n");
		scanf("%d", &(p->student[ret].age));
		printf("��ѵ绰�޸�Ϊ��\n");
		scanf("%s", &(p->student[ret].tel));
		printf("��ѵ�ַ�޸�Ϊ��\n");
		scanf("%s", &(p->student[ret].address));
	}
	else
	{
	  printf("��ϵ�˲����ڣ�\n");
	}
}

void show_people(pcon p)//��ʾ������ϵ����Ϣ  
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

void empty_people(pcon p)//���ͨѶ¼  
{
	p->count = 0;
}

void sort_people(pcon p)//����������ϵ������,�����  
{
	int i = 0, j = 0;
	contact tmp = { 0 };
	for (i = 0;i < p->count - 1;i++)
	{
		for (j = 0;j < (p->count) - 1 - i;j++)
		{
			if (strcmp(p->student[j].name, p->student[j + 1].name)>0)//��������������  
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
			printf("�������");
			break;
		}
	}
	system("pause");
	return 0;
}
