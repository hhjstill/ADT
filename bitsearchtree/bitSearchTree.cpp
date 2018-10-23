#include "bitSearchTree.h"
#include <cstdio>
//公有接口，调用私有方法实现.
PNODE CBitSTree::insert(int nVal) {
	return insert(m_root, nVal);
}
PNODE CBitSTree::insert(PNODE& node, int nVal) {
	//1.如果该节点为空,则给该节点赋值
	if (!node)
	{
		node = new NODE{ nVal, nullptr, nullptr };
		if (!node)return nullptr;
	}


	//2.如果不为空，当nVal > 该节点数据值时，插入右子树
	else if (nVal > node->data)
	{
		insert(node->rChild, nVal);
	}


	//3.如果不为空，当nVal < 该节点数据值时，插入左子树
	else if (nVal < node->data)
	{
		insert(node->lChild, nVal);
	}


	//4.其他情况不做处理
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
	//首先从node开始寻找需要删除的节点
	//********************************
	//1.该节点为空，则没找到要删除的节点，返回空
	if (!node)return nullptr;
	//2.如果nVal大于node的数据，则去右子树寻找要删除的节点
	else if (nVal > node->data)
	{
		erase(node->rChild, nVal);
	}
	//3.如果nVal小于node的数据，则去左子树寻找要删除的节点
	else if (nVal < node->data)
	{
		erase(node->lChild, nVal);
	}
	//4.如果nVal等于node的数据，则找到需要删除的节点了
	else
	{
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