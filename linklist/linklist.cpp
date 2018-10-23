#include "linklist.h"
#include "stdafx.h"
void CLinkList::insertHead(int num) {
	NODE* p = new NODE;
	p->data = num;
	p->pnext = m_pHead->pnext;
	m_pHead->pnext = p;
}
void CLinkList::insertTail(int num) {
	NODE* p = m_pHead;
	while (p->pnext)
		p = p->pnext;
	NODE* q = new NODE;
	q->data = num;
	q->pnext = p->pnext;
	p->pnext = q;
	p = nullptr;
}
bool CLinkList::insertBehind(int pos, int num) {
	int nCount = 1;
	NODE* p = m_pHead;
	while (p && nCount < pos)
	{
		p = p->pnext;
		nCount++;
	}
	if (!p || nCount > pos)
		return false;
	NODE* q = new NODE;
	q->data = num;
	q->pnext = p->pnext;
	p->pnext = q;
	p = nullptr;
	return true;
}
bool CLinkList::erase(int pos) {
	NODE* p = m_pHead;
	int nCount = 1;
	while (p->pnext && nCount < pos)
	{
		nCount++;
		p = p->pnext;
	}
	if (!p->pnext || nCount > pos)
		return false;
	NODE* q = p->pnext;
	p->pnext = q->pnext;
	delete q;
	p = q = nullptr;
	return true;
}
bool CLinkList::getElem(int pos, int&e) {
	NODE* p = m_pHead->pnext;
	int nCount = 1;
	while (p && nCount < pos)
	{
		nCount++;
		p = p->pnext;
	}
	if (!p || nCount > pos)
		return false;
	e = p->data;
	return true;
}
int CLinkList::elemLocate(int nVal) {
	NODE* p = m_pHead->pnext;
	int nCount = 1;
	while (p && p->data != nVal)
	{
		p = p->pnext;
		nCount++;
	}
	if (!p)
		return 0;
	return nCount;
}