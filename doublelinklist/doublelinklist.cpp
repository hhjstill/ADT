#include "doublelinklist.h"
void CDList::insertHead(int nVal) {
	NODE* p = new NODE;
	p->data = nVal;
	p->next = m_pHead->next;
	p->pre = m_pHead;
	m_pHead->next = p;
	if(p->next)
		p->next->pre = p;
}
void CDList::insertTail(int nVal) {
	NODE* p = new NODE;
	p->data = nVal;
	NODE* q = m_pHead;
	while (q->next)
		q = q->next;
	p->next = q->next;
	p->pre = q;
	q->next = p;
}
bool CDList::insert(int pos, int nVal) {
	NODE* p = m_pHead;
	int nCount = 1;
	while (p && nCount < pos)
	{
		nCount++;
		p = p->next;
	}
	if (!p || nCount > pos)
		return false;
	NODE* q = new NODE;
	q->data = nVal;
	q->next = p->next;
	q->pre = p;
	p->next = q;
	if(q->next)
		q->next->pre = q;
	return true;
}
