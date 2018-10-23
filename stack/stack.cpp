#include "stack.h"
bool CStack::reNew() {
	int* p = new int[m_nMaxSize + 10];
	if (!p)return false;
	memset(p, 0, (m_nMaxSize + 10) * sizeof(int));
	memcpy(p, m_data, m_nMaxSize * sizeof(int));
	delete[] m_data;
	m_data = p;
	p = nullptr;
	m_nMaxSize += 10;
	return true;
}
void CStack::push(int nVal) {
	if (m_top == m_nMaxSize)
	{
		if (!reNew())return;
	}
	m_top++;
	m_data[m_top] = nVal;
}
void CStack::pop(int& e) {
	if (m_top == -1)return;
	e = m_data[m_top];
	m_top--;
}
void CStack::destroyStack() {
	if (m_data)
		delete[] m_data;
	m_data = nullptr;
	m_top = -1;
}
bool CStack::getTopElem(int& e) {
	if (-1 == m_top)
		return false;
	e = m_data[m_top];
	return true;
}
bool CStack::empty() {
	return m_top == -1 ? true : false;
}