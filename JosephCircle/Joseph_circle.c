#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node * next;
}Node, *pNode;
pNode cur = NULL;
pNode pre = NULL;
pNode head = NULL;

pNode CreateNode( DataType n)//用单循环链表创建约瑟夫环
{
	int i = 0;
	for (i = 1; i <= n;i++)
	{
		pNode tmp = (pNode)malloc(sizeof(Node));
		if (NULL == tmp)
		{
			printf("out of memory !\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			cur = tmp;
			cur->data = i;
			cur->next = NULL;
		}
		if (head == NULL)
		{
			head = cur;
		}
		else
		{
			pre->next = cur;
		}
		pre = cur;	
	}
	cur ->next = head;
	return head;
}

void JosephCircle(DataType num, DataType count)
{
	int i = 0;
	int j = 0;
	cur =CreateNode(num);
	while (cur->next != cur)
	{
		for (i = 1; i <num ;i++)
		{
			for (j = 1;j < count ; j++)
			{
				pre = cur;
				cur = cur->next;
			}
			
			printf("第%d个出局的人是第%d 位\n", i, cur->data);
			pre->next = cur->next;
			free(cur);
			cur = pre->next;
		}
	}
	printf("最终活下来的人是第 %d 位\n", cur->data);
}
int main()
{
	int num;
	int count;
	printf("请输入约瑟夫环问题的总人数num-> ");
	scanf("%d", &num);
	printf("请输入约瑟夫环问题中第几个报数的人出局-> ");
	scanf("%d", &count);
	JosephCircle( num,  count);
	system("pause");
	return 0;
}