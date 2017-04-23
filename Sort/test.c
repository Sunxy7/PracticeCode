int main()
{
	int i=0;
	int arr[10]={3,5,7,2,4,0,1,6,9,8};
	int len =sizeof(arr)/sizeof(arr[0]);
	InsertSort(arr,len);
	for (i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	system("pause");
	return 0;
}