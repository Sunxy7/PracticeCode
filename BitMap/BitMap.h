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
		size_t index = num >> 5;     //右移5位相当于除以32，找出该位在第几个数中
		size_t pos = num % 32;       //找出该位是某个数中的哪一位
		_bitMap[index] |= (1 << pos);  //该位置1
	}
	void reset(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		_bitMap[index] &= (~(1 << pos) );
	}
	bool test(size_t num)//判断该位是否为1，是true，否false
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		return _bitMap[index] &(1 << pos);
	}
private:
	vector<size_t> _bitMap;

};