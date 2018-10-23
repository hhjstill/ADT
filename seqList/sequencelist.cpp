#include "sequencelist.h"
void CSeqList::initList() {
	memset(m_data, 0, sizeof(int) * m_maxSize);
}
bool CSeqList::reNew() {
	int* p = new int[m_maxSize + 10];
	if (!p)return false;
	memset(p, 0, sizeof(int) * (m_maxSize + 10));
	memcpy(p, m_data, sizeof(int) * m_curSize);
	delete[] m_data;
	m_data = p;
	p = nullptr;
	m_maxSize += 10;
	return true;
}
bool CSeqList::insert(int pos, int num) {
	if (m_curSize == m_maxSize) {
		if (!reNew())
			return false;
	}

	if (pos < 1 || pos > m_curSize + 1)
		return false;
	
	if (pos <= m_curSize)
	{
		for (int i = m_curSize; i >= pos; i--)
			m_data[i] = m_data[i - 1];
	}
	m_data[pos - 1] = num;
	m_curSize++;
	return true;
}
bool CSeqList::insertTail(int num) {
	if (m_curSize == m_maxSize) {
		if (!reNew())
			return false;
	}
	m_data[m_curSize] = num;
	m_curSize++;
	return true;
}
bool CSeqList::insertHead(int num) {
	if (m_curSize == m_maxSize) {
		if (!reNew())
			return false;
	}
	for (int i = m_curSize; i > 0; i--)
	{
		m_data[i] = m_data[i - 1];
	}
	m_data[0] = num;
	m_curSize++;
	return true;
}
bool CSeqList::popback() {
	if (m_curSize == 0)
		return false;
	m_curSize--;
	return true;
}
int CSeqList::getLenth() {
	return m_curSize;
}
int& CSeqList::operator[](int index) {
	return m_data[index];
}

