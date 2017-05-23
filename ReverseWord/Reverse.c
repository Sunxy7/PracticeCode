#include<stdio.h>
#include<assert.h>

void Reverse(char *begin, char *end)
{
	if (begin == NULL || end == NULL)
		return;
	while (begin < end)
	{
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;

	}
}
char * ReverseString(char *str)
{
	if (str == NULL)
		return NULL;
	char *start = str;
	char *end = str;
	while (*end != '\0')
	{
		end++;
	}
	end--;             //end�ƶ���'\0'ǰһ��λ��
	Reverse(start, end);//��ת�����ַ���
						//��תһ������
	start = str;
	end = str;
	while (*start != '\0')
	{
		if (*start == ' ')
		{
			start++;
			end++;
		}

		else if (*end == ' ' || *end == '\0')
		{
			Reverse(start, --end);
			start = ++end;
		}
		else
		{
			end++;
		}
	}
	return str;
}
int main()
{
	char str[] = "I am a strudent.";
	char *rstr = ReverseString(str);
	printf("%s\n", rstr);

	system("pause");
	return 0;
}