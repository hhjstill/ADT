#pragma once
#include <cstring>
#include <iostream>
using namespace std;
//线性表
class CSeqList
{
public:
	CSeqList() {
		m_data = new int[m_maxSize];
	}
	//数组空间初始化为0
	void initList();
	//在某个位置前插入，如果在数列尾部，则在最后一个位置插入
	bool insert(int pos, int num);
	//动态增长空间，一次增加10个int
	bool reNew();
	//尾插
	bool insertTail(int num);
	//头插
	bool insertHead(int num);
	//删除尾部元素
	bool popback();
	int getLenth();
	int& operator[](int index);
	friend ostream& operator<<(ostream& o, CSeqList& list) {
		for (int i = 0; i < list.m_curSize; i++)
			o << list.m_data[i] << " ";
		cout << endl;
		return o;
	}
	virtual ~CSeqList() {
		if (m_data)
			delete[] m_data;
		m_data = nullptr;
	}
	
private:
	int m_maxSize = 20;
	int m_curSize = 0;//当前元素个数
	int* m_data = nullptr;
};