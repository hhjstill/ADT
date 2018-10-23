#include "dcirclelist.h"
void CDoubleCircleList::insertHead(int nVal) {
	NODE* p = new NODE;
	p->data = nVal;
	p->next = m_pHead->next;
	p->pre = m_pHead;
	m_pHead->next = p;
	p->next->pre = p;
}
void CDoubleCircleList::insertTail(int nVal) {
	NODE* p = m_pHead;
	while (p->next != m_pHead)
		p = p->next;
	NODE* q = new NODE;
	q->data = nVal;
	q->next = p->next;
	q->pre = p;
	p->next = q;
	q->next->pre = q;
}
bool CDoubleCircleList::insert(int pos, int nVal) {
	NODE* p = m_pHead;
	int nCount = 1;
	while (p->next != m_pHead && nCount < pos)
	{
		nCount++;
		p = p->next;
	}
	if (p->next == m_pHead || nCount > pos)
		return false;
	NODE* q = new NODE;
	q->data = nVal;
	q->next = p->next;
	q->pre = p;
	p->next = q;
	q->next->pre = q;
	return true;
}
bool CDoubleCircleList::erase(int pos) {
	NODE* p = m_pHead;
	int nCount = 1;
	while (p->next != m_pHead && nCount < pos)
	{
		nCount++;
		p = p->next;
	}
	if (p->next == m_pHead || nCount > pos)
		return false;
	NODE* q = p->next;
	p->next = q->next;
	q->next->pre = p;
	delete q;
	q = nullptr;
	return true;
}