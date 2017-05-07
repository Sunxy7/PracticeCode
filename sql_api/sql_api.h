#include<iostream>
#include"/usr/include/mysql/mysql.h"
#include<string>
#include<stdio.h>
using namespace std;

class sql_api
{
public:
	sql_api();
	~sql_api();
	bool sql_connect(string host,string user,string password,string dbname);
	bool Insert(const char * str);
	bool Delete(const char *str);
	bool Update(const char *str);
	bool Select();
private:
	MYSQL * conn;//mysql连接
};
