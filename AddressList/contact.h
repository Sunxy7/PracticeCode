
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define NAME_MAX 15
#define SEX_MAX 5
#define TEL_MAX 12
#define ADDR_MAX 20
#define SIZE 1000
typedef struct contact//����һ���ṹ�������ͨѶ¼�е���Ա��Ϣ  
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tel[TEL_MAX];
	char address[ADDR_MAX];
}contact;
typedef struct people
{
	contact student[SIZE];
	int count;
}people, *pcon;

void menu();//�˵�����
void init(pcon p);//��ʼ��ͨѶ¼
int search(pcon p);//����������һ����ϵ��
void add_people(pcon p);//¼����ϵ����Ϣ
void find_people(pcon p);//����һ����ϵ�ˣ����������������Ϣ
void delete_people(pcon p);//ɾ��ĳ��ϵ����Ϣ
void change_people(pcon p);//�޸���ϵ����Ϣ
void show_people(pcon p);//��ʾ������ϵ����Ϣ
void empty_people(pcon p);//���ͨѶ¼
void sort_people(pcon p);//����������ϵ������,�����