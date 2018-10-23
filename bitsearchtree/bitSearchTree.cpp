#include "bitSearchTree.h"
#include <cstdio>
//���нӿڣ�����˽�з���ʵ��.
PNODE CBitSTree::insert(int nVal) {
	return insert(m_root, nVal);
}
PNODE CBitSTree::insert(PNODE& node, int nVal) {
	//1.����ýڵ�Ϊ��,����ýڵ㸳ֵ
	if (!node)
	{
		node = new NODE{ nVal, nullptr, nullptr };
		if (!node)return nullptr;
	}


	//2.�����Ϊ�գ���nVal > �ýڵ�����ֵʱ������������
	else if (nVal > node->data)
	{
		insert(node->rChild, nVal);
	}


	//3.�����Ϊ�գ���nVal < �ýڵ�����ֵʱ������������
	else if (nVal < node->data)
	{
		insert(node->lChild, nVal);
	}


	//4.���������������
	return node;
}
int CBitSTree::leftMax(PNODE node)
{
	while (node->rChild)
		node = node->rChild;
	return node->data;
}
int CBitSTree::rightMin(PNODE node)
{
	while (node->lChild)
		node = node->lChild;
	return node->data;
}
int CBitSTree::getHigh(PNODE node)
{
	if (!node)return 0;
	int leftHigh = getHigh(node->lChild);
	int rightHigh = getHigh(node->rChild);
	return leftHigh > rightHigh ? leftHigh + 1 : rightHigh + 1;
}
PNODE CBitSTree::erase(int nVal) {
	return erase(m_root, nVal);
}
PNODE CBitSTree::erase(PNODE& node, int nVal) {
	//���ȴ�node��ʼѰ����Ҫɾ���Ľڵ�
	//********************************
	//1.�ýڵ�Ϊ�գ���û�ҵ�Ҫɾ���Ľڵ㣬���ؿ�
	if (!node)return nullptr;
	//2.���nVal����node�����ݣ���ȥ������Ѱ��Ҫɾ���Ľڵ�
	else if (nVal > node->data)
	{
		erase(node->rChild, nVal);
	}
	//3.���nValС��node�����ݣ���ȥ������Ѱ��Ҫɾ���Ľڵ�
	else if (nVal < node->data)
	{
		erase(node->lChild, nVal);
	}
	//4.���nVal����node�����ݣ����ҵ���Ҫɾ���Ľڵ���
	else
	{
		//1.����ýڵ�û����������ֱ��ɾ���ýڵ�
		if (!node->lChild && !node->rChild)
		{
			delete node;
			node = nullptr;
		}
		//2.����ýڵ�����������Ƚ���������������
		//1)����������ߣ����ҵ����������ֵ��ֵ���ýڵ㣬��ɾ�����������ֵ�ڵ�
		//2)����������ߣ����ҵ���������Сֵ��ֵ���ýڵ㣬��ɾ����������Сֵ�ڵ�
		else
		{
			//�����߱��ұ߸�
			if (getHigh(node->lChild) > getHigh(node->rChild))
			{
				node->data = leftMax(node->lChild);
				erase(node->lChild, node->data);
			}
			//����ұ߱���߸�
			else
			{
				node->data = rightMin(node->rChild);
				erase(node->rChild, node->data);
			}
		}
	}
	return node;
}
void CBitSTree::show(PNODE Node, int w, char c)
{
	if (Node != nullptr)
	{
		show(Node->rChild, w + 4, '/');
		printf("%*s%c%02d\n", w, " ", c, Node->data);
		show(Node->lChild, w + 4, '\\');
	}
}
void CBitSTree::show()
{
	show(m_root, 0, '*');
	printf("-----------------------------------\n");
}
void CBitSTree::preTraval(PNODE node) {
	if (!node)return;
	printf("%d ", node->data);
	preTraval(node->lChild);
	preTraval(node->rChild);
}
void CBitSTree::midTraval(PNODE node) {
	if (!node)return;
	midTraval(node->lChild);
	printf("%d ", node->data);
	midTraval(node->rChild);
}
void CBitSTree::backTraval(PNODE node) {
	if (!node)return;
	backTraval(node->lChild);
	backTraval(node->rChild);
	printf("%d ", node->data);
}