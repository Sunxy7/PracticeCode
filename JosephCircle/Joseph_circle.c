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

pNode CreateNode( DataType n)//�õ�ѭ��������Լɪ��
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
			
			printf("��%d�����ֵ����ǵ�%d λ\n", i, cur->data);
			pre->next = cur->next;
			free(cur);
			cur = pre->next;
		}
	}
	printf("���ջ����������ǵ� %d λ\n", cur->data);
}
int main()
{
	int num;
	int count;
	printf("������Լɪ�������������num-> ");
	scanf("%d", &num);
	printf("������Լɪ�������еڼ����������˳���-> ");
	scanf("%d", &count);
	JosephCircle( num,  count);
	system("pause");
	return 0;
}