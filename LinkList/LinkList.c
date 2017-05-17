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
pListNode AddNode(DataType data)
{
	pListNode Node = (pListNode)malloc(sizeof(ListNode));
	if (Node == NULL)
	{
		printf("out of memory£¡\n");
		exit(0);
	}
	Node->data = data;
	Node->next = NULL;
	return Node;
}
//void PushFront(pLinkList plist, DataType data)
//{}
void PushBack(pLinkList plist, DataType data)
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
//void PopFront(pLinkList plist);
//void PopBack(pLinkList plist);
//void Remove(pLinkList plist, DataType data);
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
void ReverPrintList(pLinkList plist)
{
	assert(plist);
	//pListNode cur = plist->Head;
	if(plist->Head)
	{
		if(plist->Head->next)
		{
			ReverPrintList(plist->Head->next);
		}
		printf("%d ->", plist->Head->data);
	}
}