#include<stdio.h>
#include<string.h>

void ReplaceSpase(char * str,int len)//»ù´¡°æO(N2)
{
	char * start=str;
	int count=0;
	int Newend=len;
	while(*start != '\0')
	{
		if(*start == ' ')
		{
			count++;
		}
		start++;
	}
	Newend+=2*count;
	while(len<Newend)
	{
		if(str[len]!=' ')
		{
			str[Newend--] = str[len--];
		}
		else
		{
			str[Newend--]='0';
			str[Newend--]='2';
			str[Newend--]='%';
		}
		len--;
	}


}
int main()
{
	char * str ="we are happy";
	ReplaceSpase(str,strlen(str));
	printf("%s\n",str);
	system("pause");
	return 0;
}