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
	//ͷ��
	void insertHead(int num);
	
	//β��
	void insertTail(int num);
	//��ĳ��Ԫ��֮ǰ����һ��Ԫ��
	bool insertBehind(int pos, int num);
	//ɾ��ĳ��Ԫ��
	bool erase(int pos);
	//����ĳ��λ�õ�Ԫ�أ����򷵻ظ�e
	bool getElem(int pos, int&e);
	//�����Ƿ���ֵΪval��Ԫ�أ����򷵻�λ�ã�û���򷵻�0
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