#include"sql_api.h"

sql_api::sql_api()
{
	conn = mysql_init(NULL);
}	
sql_api::~sql_api()
{
	mysql_close(conn);
}
bool sql_api::sql_connect(string host,string user,string password,string dbname)
{
	conn = mysql_real_connect(conn,host.c_str(),user.c_str(),password.c_str(), dbname.c_str(),0,NULL,0);
	if(conn ==NULL)
	{
		cout<<"mysql_real_connect is failed"<<endl;
		return false;
	}
		return true;
}
//插入数据
bool sql_api::Insert(const char *info)
{
	string sql ="INSERT INTO myhttp_info(id,name,age,sex,school)values(";
	sql += info;
	sql += ");";
	cout<<sql<<endl;
	int ret =mysql_query(conn,sql.c_str());
	if(ret != 0)
	{
		return false;
	}
	return true;
} 
//删除数据
bool sql_api::Delete(const char *info)
{
	string sql ="DELETE FROM myhttp_info WHERE(";
	sql += info;
	sql += ");";
	cout<<sql<<endl;
	int ret =mysql_query(conn,sql.c_str());
    if (ret != 0)
	{
		return false;
	}
	return true;
}
//修改数据
bool sql_api::Update(const char * info)
{
	string sql = "UPDATE myhttp_info SET ";
	sql += info;
	sql += ';';
	cout<<sql<<endl;
	int ret =mysql_query(conn,sql.c_str());
	if(ret != 0)
	{
		return false;
	}
	return true;
}
//查找数据
bool sql_api::Select()
{
	string sql="SELECT * FROM myhttp_info;";
	int ret = mysql_query(conn,sql.c_str());
	if (ret != 0)
	{
		return false;
	}
		MYSQL_RES *res =mysql_store_result(conn);
		//"id" "name" "age" "sex" "school"
		if (res == NULL)
		{
			return false;
		}
		int num_fields =mysql_num_fields(res);//行数
		MYSQL_FIELD *field ;//
		MYSQL_ROW rows;//结果集的下一行
		while(field = mysql_fetch_field(res))
		{
			cout<<field->name<<' ';
		}
		cout<<endl;
		while(rows = mysql_fetch_row(res))
		{	
			int i=0;
			for(i=0;i<num_fields;i++)
			{
				cout<<rows[i]<<' ';
			}
			cout<<endl;
		}
	mysql_free_result(res);
	return true;
}

int main()
{
	sql_api my_api;
	if(!my_api.sql_connect("127.0.0.1","root","qaz","myhttp"))
	{
		return -1;
	}
	my_api.Select();
	my_api.Insert("1,'张三',20,'男','SUST'");
	my_api.Insert("2,'李四',21,'男','XATU'");
	my_api.Insert("3,'王五',20,'男','清华'");
	my_api.Insert("4,'小红',20,'男','北大'");
	my_api.Insert("5,'小明',19,'女','西工大'");
	my_api.Insert("6,'小李',22,'男','交大'");
	my_api.Select();
	my_api.Update("age=30 where name ='王五'");
	my_api.Select();
	my_api.Update("school ='xatu' where id =2");
	my_api.Select();
	my_api.Update("sex ='女' where name ='小红'");
	my_api.Select();
	my_api.Delete("name ='张三'");
	my_api.Select();
	my_api.Delete("school ='西工大'");
	my_api.Select();
	return 0;


}
