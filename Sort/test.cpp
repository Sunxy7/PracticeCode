int main()
{
	int i=0;
	int arr[100]={0};
	int len=sizeof(arr)/sizeof(arr[0]);
	srand((unsigned)time(NULL));//������ͬ�����������
	for(i=0;i<len;i++)
	{
		arr[i]=rand()%101;//��1-100�����������ʼ������
	}
	//InsertSort1(arr,len);
	//InsertSort2(arr,len);
	InsertSort3(arr,len);
	for(i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}