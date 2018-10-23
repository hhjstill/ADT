#pragma once
struct NODE
{
	int data;
	NODE* pre;
	NODE* next;
};
class CDoubleCircleList
{
public:
	CDoubleCircleList() {
		m_pHead = new NODE;
		m_pHead->next = m_pHead->pre = m_pHead;
	}
	void insertHead(int nVal);
	void insertTail(int nVal);
	bool insert(int pos, int nVal);
	bool erase(int pos);
private:
	NODE* m_pHead;
};
