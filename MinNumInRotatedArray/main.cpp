#include <iostream>
using namespace std;
int MinInOrder(int arr[],int pos1,int pos2)
{
	int min =pos1;
	int i=0;
	for (i=pos1;i<=pos2;i++)
	{
		if (arr[i]<arr[min])
		{
			min=i;
		}
	}
	return arr[min];
}
int Min(int arr[],int len)
{
	  int mid=0;
	  int pos1 =0;
	  int pos2 =len-1;
	  while (arr[pos1]>=arr[pos2])
	  {
		  if(pos2-pos1 ==1)
		  {
			  mid=pos2;
			  break;
		  }
	      mid = (pos2+pos1)/2;
		  if (arr[pos1]==arr[pos2] && arr[mid]==arr[pos1])
		  {
			  return MinInOrder(arr,pos1,pos2);
		  }
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
	//int arr[10]={3,4,5,6,7,8,9,0,1,2};
	//int arr[]={1,1,0,1,1,1,1};
	int arr[]={1,1,1,0,1};
	int len=sizeof(arr)/sizeof(arr[0]);
	int min=Min(arr,len);
	cout<<"min num is:"<<min<<endl;
	system("pause");
	return 0;
}