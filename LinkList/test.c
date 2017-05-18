#include"LinkList.h"

int main()
{
	LinkList list;
	InitList(&list);
	PushFront(&list, 0);
	PushFront(&list, -1);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, -1);
	PushBack(&list, 5);
	PushBack(&list, 6);
	PushBack(&list, -1);
	PrintList(&list);
	PopFront(&list);
	PrintList(&list);
	PopFront(&list);
	PrintList(&list);
	PopBack(&list);
	PrintList(&list);
	PopBack(&list);
	PrintList(&list);
	RemoveAll(&list, -1);
	PrintList(&list);
	Remove(&list, -1);
	PrintList(&list);
	Remove(&list, 6);
	PrintList(&list);
	ReverPrintList((&list)->Head);
	DestoryList(&list);
	system("pause");
	return 0;
}