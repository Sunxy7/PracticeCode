#include"LinkList.h"
void InitList(pLinkList plist)
{
	assert(plist);
	plist->Head = NULL;
}
void DestoryList(pLinkList plist)
{
	assert(plist);
	pListNode cur = plist->Head;
	pListNode tmp = NULL;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = NULL;
		cur = tmp;
	}
	plist->Head = NULL;
}
pListNode AddNode(DataType data)//申请一个节点
{
	pListNode Node = (pListNode)malloc(sizeof(ListNode));
	if (Node == NULL)
	{
		printf("out of memory！\n");
		exit(0);
	}
	Node->data = data;
	Node->next = NULL;
	return Node;
}
void PushFront(pLinkList plist, DataType data)//头插
{
	assert(plist);
	pListNode NewNode = AddNode(data);
	if (plist->Head != NULL)
	{
		NewNode->next = plist->Head;
	}
	plist->Head = NewNode;
}
void PushBack(pLinkList plist, DataType data)//尾插
{
	assert(plist);
	pListNode cur = plist->Head;
	pListNode NewNode = AddNode(data);
	pListNode prev = NULL;
	if (plist->Head == NULL)
	{
		plist->Head = NewNode;
		return;
	}
	while (cur)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = NewNode; 
}
void PopFront(pLinkList plist)//头删
{
	assert(plist);
	pListNode cur = plist->Head;
	if (plist->Head ==NULL)
	{
		printf("list is empty!\n");
		return;
	}
	plist->Head = cur->next;
	free(cur);
	cur = NULL;
}
void PopBack(pLinkList plist)//尾删
{
	assert(plist);
	pListNode cur = plist->Head;
	pListNode prev = NULL;
	if (plist->Head==NULL)
	{
		printf("list is empty!\n");
		return;
	}
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	free(cur);
	prev->next = NULL;
}
void Remove(pLinkList plist, DataType data)//删除第一个数据为data的节点
{
	assert(plist);
	pListNode cur = plist->Head;
	if (plist->Head == NULL)
	{
		printf("list is empty!\n");
		return;
	}
	while (cur)
	{
		if (cur->next== NULL && cur->data == data)
		{
			PopBack(plist);
			return;
		}
		else if(cur->next != NULL && cur->data==data)
		{
			pListNode tmp = cur->next;
			cur->data = cur->next->data;
			cur->next = cur->next->next;
			free(tmp);
			tmp = NULL;
			return;
		} 
		cur = cur->next;
	}
	printf("data is not find!\n");
}
void RemoveAll(pLinkList plist, DataType data)//删除所有数据为data的节点
{
	assert(plist);
	pListNode cur = plist->Head;
	int flag = 0;
	if (plist->Head == NULL)
	{
		printf("list is empty!\n");
		return;
	}
	while (cur)
	{
		if (cur->next == NULL && cur->data == data)
		{
			flag = 1;
			PopBack(plist);
			return;
		}
		while (cur->next != NULL && cur->data == data)
		{
			flag = 1;
			pListNode tmp = cur->next;
			cur->data = cur->next->data;
			cur->next = cur->next->next;
			free(tmp);
			tmp = NULL;
		}
		cur = cur->next;
	}
	if (flag == 0)
	{
		printf("data is not find!\n");
	}
}
void PrintList(pLinkList plist)
{
	assert(plist);
	pListNode cur = plist->Head;
	while (cur)
	{
		printf("%d ->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}
void ReverPrintList(pListNode head)//逆序输出链表
{
	assert(head);
	//pListNode cur = plist->Head;
	if(head)
	{
		if(head->next)
		{
			ReverPrintList(head->next);
		}
		printf("%d ->", head->data);
	}
}