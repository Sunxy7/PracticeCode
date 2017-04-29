
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define NAME_MAX 15
#define SEX_MAX 5
#define TEL_MAX 12
#define ADDR_MAX 20
#define SIZE 1000
typedef struct contact//定义一个结构体来存放通讯录中的人员信息  
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

void menu();//菜单函数
void init(pcon p);//初始化通讯录
int search(pcon p);//用姓名查找一个联系人
void add_people(pcon p);//录入联系人信息
void find_people(pcon p);//查找一个联系人，并输出他的所有信息
void delete_people(pcon p);//删除某联系人信息
void change_people(pcon p);//修改联系人信息
void show_people(pcon p);//显示所有联系人信息
void empty_people(pcon p);//清空通讯录
void sort_people(pcon p);//按姓名对联系人排序,并输出