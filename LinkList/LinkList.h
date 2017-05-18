#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataType;
typedef struct ListNode
{
	DataType data;
	struct ListNode * next;
}ListNode,*pListNode;
typedef struct LinkList
{
	ListNode *Head;
}LinkList,*pLinkList;

void InitList(pLinkList plist);
void DestoryList(pLinkList plist);
void PushFront(pLinkList plist,DataType data);
void PushBack(pLinkList plist,DataType data);
void PopFront(pLinkList plist);
void PopBack(pLinkList plist);
void Remove(pLinkList plist,DataType data);
void RemoveAll(pLinkList plist, DataType data);
void PrintList(pLinkList plist);
void ReverPrintList(pListNode head);



