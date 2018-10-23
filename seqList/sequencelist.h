#pragma once
#include <cstring>
#include <iostream>
using namespace std;
//���Ա�
class CSeqList
{
public:
	CSeqList() {
		m_data = new int[m_maxSize];
	}
	//����ռ��ʼ��Ϊ0
	void initList();
	//��ĳ��λ��ǰ���룬���������β�����������һ��λ�ò���
	bool insert(int pos, int num);
	//��̬�����ռ䣬һ������10��int
	bool reNew();
	//β��
	bool insertTail(int num);
	//ͷ��
	bool insertHead(int num);
	//ɾ��β��Ԫ��
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
	int m_curSize = 0;//��ǰԪ�ظ���
	int* m_data = nullptr;
};