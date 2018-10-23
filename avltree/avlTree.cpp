#include "avlTree.h"
#include <cstdio>

int CAvlTree::leftMax(PNODE node)
{
	while (node->rChild)
		node = node->rChild;
	return node->data;
}
int CAvlTree::rightMin(PNODE node)
{
	while (node->lChild)
		node = node->lChild;
	return node->data;
}
void CAvlTree::show(PNODE Node, int w, char c)
{
	if (Node != nullptr)
	{
		show(Node->rChild, w + 4, '/');
		printf("%*s%c%02d\n", w, " ", c, Node->data);
		show(Node->lChild, w + 4, '\\');
	}
}
void CAvlTree::show()
{
	show(m_root, 0, '*');
	printf("-----------------------------------\n");
}
PNODE CAvlTree::erase(int nVal) {
	return erase(m_root, nVal);
}

PNODE CAvlTree::insert(int nVal) {
	return insert(m_root, nVal);
}
PNODE CAvlTree::leftTurn(PNODE node) {
	PNODE temp = node->rChild;
	node->rChild = temp->lChild;
	temp->lChild = node;
	return temp;
}
PNODE CAvlTree::rightTurn(PNODE node) {
	PNODE temp = node->lChild;
	node->lChild = temp->rChild;
	temp->rChild = node;
	return temp;
}
PNODE CAvlTree::leftRightTurn(PNODE node) {
	leftTurn(node->lChild);
	return rightTurn(node);	
}
PNODE CAvlTree::rightLeftTurn(PNODE node) {
	rightTurn(node->rChild);
	return leftTurn(node);
}
int CAvlTree::getHigh(PNODE node)
{
	if (!node)return 0;
	int leftHigh = getHigh(node->lChild);
	int rightHigh = getHigh(node->rChild);
	return leftHigh > rightHigh ? leftHigh + 1 : rightHigh + 1;
}
PNODE CAvlTree::insert(PNODE& node, int nVal) {
	//1.���nodeΪ�գ����ҵ���ȷλ�ã�����nVal
	if (!node)
	{
		node = new NODE{ nVal, nullptr, nullptr };
		if (!node)return nullptr;
	}
	//2.���nVal > node->data,��ȥ������Ѱ����ȷ��λ��
	else if (nVal > node->data)
	{
		node->rChild = insert(node->rChild, nVal);
		//�����ƽ�⣺
		if (getHigh(node->rChild) - getHigh(node->lChild) == 2)
		{
			//1)�����û��
			if (node->rChild->rChild)
			{
				node = leftTurn(node);
			}
			//2)���������
			else
			{
				node = rightLeftTurn(node);
			}
		}
	}
	//3.���nVal < node->data,��ȥ������Ѱ����ȷ��λ��
	else if (nVal < node->data)
	{
		node->lChild = insert(node->lChild, nVal);
		//�����ƽ�⣺
		if (getHigh(node->lChild) - getHigh(node->rChild) == 2)
		{
			//1)�����û��
			if (node->lChild->lChild)
			{
				node = rightTurn(node);
			}
			//2)���������
			else
			{
				node = leftRightTurn(node);
			}
		}
	}

	return node;
	//====����Ϊ�ڵ�Ĳ��빤��====
	//----------------------------
}
PNODE CAvlTree::erase(PNODE& node, int nVal) {
	//����Ѱ�Ҹýڵ��Ƿ����
	//1.���Ϊ�գ���û�ҵ��ýڵ�
	if (!node)return nullptr;

	//2.���nVal > node->data,��ȥ������Ѱ��
	else if (nVal > node->data)
	{
		erase(node->rChild, nVal);
		//�����ƽ��
		if (getHigh(node->lChild) - getHigh(node->rChild) == 2)
		{
			//��û��
			if (node->lChild->lChild)
			{
				node = rightTurn(node);
			}
			//������
			else
			{
				node = leftRightTurn(node);
			}
		}
	}

	//3.���nVal < node->data,��ȥ������Ѱ��
	else if (nVal < node->data)
	{
		erase(node->lChild, nVal);
		//�����ƽ��
		if (getHigh(node->rChild) - getHigh(node->lChild) == 2)
		{
			//��û��
			if (node->rChild->rChild)
			{
				node = leftTurn(node);
			}
			//������
			else
			{
				node = rightLeftTurn(node);
			}
		}
	}

	//4.���nVal == node->data,���ҵ��ýڵ�
	else if (nVal == node->data)
	{
		//�ж�
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



