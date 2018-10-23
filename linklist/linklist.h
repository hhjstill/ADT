#pragma once
struct NODE
{
	int data;
	NODE* pnext;
};
class CLinkList
{
public:
	CLinkList() {
		m_pHead = new NODE;
		m_pHead->pnext = nullptr;
	}
	//头插
	void insertHead(int num);
	
	//尾插
	void insertTail(int num);
	//在某个元素之前插入一个元素
	bool insertBehind(int pos, int num);
	//删除某个元素
	bool erase(int pos);
	//查找某个位置的元素，有则返回给e
	bool getElem(int pos, int&e);
	//查找是否有值为val的元素，有则返回位置，没有则返回0
	int elemLocate(int nVal);
	
	virtual ~CLinkList() {
		NODE* p = m_pHead->pnext;
		NODE* q = p;
		while (q)
		{
			q = p->pnext;
			delete[] p;
			p = q;
		}
		delete m_pHead;
		m_pHead = nullptr;
	}
private:
	NODE* m_pHead;
};