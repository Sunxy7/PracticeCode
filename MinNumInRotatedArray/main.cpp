#include <iostream>
using namespace std;

int Min(int arr[],int len)
{
	  int mid=0;
	  int pos1 =0;
	  int pos2 =len-1;
	  while (arr[pos1]>arr[pos2])
	  {
		  if(pos2-pos1 ==1)
		  {
			  mid=pos2;
			  break;
		  }
	      mid = (pos2-pos1)/2;
		  if (arr[mid]<= arr[pos1])
		  {
			  pos2=mid;
		  }
		  else if(arr[mid]>=arr[pos1])
		  {
			  pos1=mid;
		  }
	  }

	  return arr[mid];  
}

int main()
{
	int arr[5]={3,4,5,1,2};
	int len=sizeof(arr)/sizeof(arr[0]);
	int min=Min(arr,len);
	cout<<"min num is:"<<min<<endl;
	system("pause");
	return 0;
}