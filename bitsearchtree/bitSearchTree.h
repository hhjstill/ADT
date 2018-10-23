#pragma once
typedef struct NODE
{
	int data;
	struct NODE* lChild;
	struct NODE* rChild;
}NODE, *PNODE;

class CBitSTree
{
public:
	CBitSTree():m_root(nullptr){}
	virtual ~CBitSTree(){}
	PNODE insert(int nVal);
	PNODE erase(int nVal);
	int leftMax(PNODE node);
	int rightMin(PNODE node);
	int getHigh(PNODE node);
	void show();
	void preTraval(PNODE node);
	void midTraval(PNODE node);
	void backTraval(PNODE node);
	
private:
	//给定一个节点，并给一个需要插入的值，从该节点开始向下寻找，
	//在正确的位置插入该值，并返回原来的节点。
	PNODE insert(PNODE& node, int nVal);
	//给定一个节点，并给一个需要删除的值，从该节点开始向下寻找，
	//在正确的位置删除该值，并返回原来的节点。
	PNODE erase(PNODE& node, int nVal);
	void show(PNODE Node, int w, char c);
private:
	PNODE m_root;
};