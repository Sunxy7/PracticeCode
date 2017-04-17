#pragma once
#include<iostream>
#include<vector>
using namespace std;

class BitMap
{
public:
	BitMap(size_t range)
	{
		_bitMap.resize(((range-1)>>5)+1);
	}
	void set(size_t num)
	{
		size_t index = num >> 5;     //����5λ�൱�ڳ���32���ҳ���λ�ڵڼ�������
		size_t pos = num % 32;       //�ҳ���λ��ĳ�����е���һλ
		_bitMap[index] |= (1 << pos);  //��λ��1
	}
	void reset(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		_bitMap[index] &= (~(1 << pos) );
	}
	bool test(size_t num)//�жϸ�λ�Ƿ�Ϊ1����true����false
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		return _bitMap[index] &(1 << pos);
	}
private:
	vector<size_t> _bitMap;

};