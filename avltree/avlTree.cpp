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
	//1.如果node为空，则找到正确位置，插入nVal
	if (!node)
	{
		node = new NODE{ nVal, nullptr, nullptr };
		if (!node)return nullptr;
	}
	//2.如果nVal > node->data,则去右子树寻找正确的位置
	else if (nVal > node->data)
	{
		node->rChild = insert(node->rChild, nVal);
		//如果不平衡：
		if (getHigh(node->rChild) - getHigh(node->lChild) == 2)
		{
			//1)如果树没歪
			if (node->rChild->rChild)
			{
				node = leftTurn(node);
			}
			//2)如果树歪了
			else
			{
				node = rightLeftTurn(node);
			}
		}
	}
	//3.如果nVal < node->data,则去左子树寻找正确的位置
	else if (nVal < node->data)
	{
		node->lChild = insert(node->lChild, nVal);
		//如果不平衡：
		if (getHigh(node->lChild) - getHigh(node->rChild) == 2)
		{
			//1)如果树没歪
			if (node->lChild->lChild)
			{
				node = rightTurn(node);
			}
			//2)如果树歪了
			else
			{
				node = leftRightTurn(node);
			}
		}
	}

	return node;
	//====以上为节点的插入工作====
	//----------------------------
}
PNODE CAvlTree::erase(PNODE& node, int nVal) {
	//首先寻找该节点是否存在
	//1.如果为空，则没找到该节点
	if (!node)return nullptr;

	//2.如果nVal > node->data,则去右子树寻找
	else if (nVal > node->data)
	{
		erase(node->rChild, nVal);
		//如果不平衡
		if (getHigh(node->lChild) - getHigh(node->rChild) == 2)
		{
			//树没歪
			if (node->lChild->lChild)
			{
				node = rightTurn(node);
			}
			//树歪了
			else
			{
				node = leftRightTurn(node);
			}
		}
	}

	//3.如果nVal < node->data,则去左子树寻找
	else if (nVal < node->data)
	{
		erase(node->lChild, nVal);
		//如果不平衡
		if (getHigh(node->rChild) - getHigh(node->lChild) == 2)
		{
			//树没歪
			if (node->rChild->rChild)
			{
				node = leftTurn(node);
			}
			//树歪了
			else
			{
				node = rightLeftTurn(node);
			}
		}
	}

	//4.如果nVal == node->data,则找到该节点
	else if (nVal == node->data)
	{
		//判断
		//1.如果该节点没有子树，则直接删除该节点
		if (!node->lChild && !node->rChild)
		{
			delete node;
			node = nullptr;
		}
		//2.如果该节点有子树，则比较左右子树的树高
		//1)如果左子树高，则找到左子树最大值赋值给该节点，并删除左子树最大值节点
		//2)如果右子树高，则找到右子树最小值赋值给该节点，并删除右子树最小值节点
		else
		{
			//如果左边比右边高
			if (getHigh(node->lChild) > getHigh(node->rChild))
			{
				node->data = leftMax(node->lChild);
				erase(node->lChild, node->data);
			}
			//如果右边比左边高
			else
			{
				node->data = rightMin(node->rChild);
				erase(node->rChild, node->data);
			}
		}
	}
	return node;
}



