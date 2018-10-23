#pragma once
#include <cstring>
class CStack
{
public:
	CStack():m_nMaxSize(20),m_top(-1){
		m_data = new int[m_nMaxSize];
		memset(m_data, 0, m_nMaxSize * sizeof(int));
	}
	bool reNew();
	void push(int nVal);
	void pop(int& e);
	void destroyStack();
	bool getTopElem(int& e);
	bool empty();
	virtual ~CStack() {
		destroyStack();
	}
private:
	int m_nMaxSize;
	int m_top;
	int* m_data;
};