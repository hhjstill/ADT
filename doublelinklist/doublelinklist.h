#pragma once
struct NODE
{
	int data;
	NODE* pre;
	NODE* next;
};
class CDList
{
public:
	CDList() {
		m_pHead = new NODE;
		m_pHead->next = m_pHead->pre = nullptr;
	}
	void insertHead(int nVal);
	void insertTail(int nVal);
	bool insert(int pos, int nVal);
private:
	NODE* m_pHead;
};