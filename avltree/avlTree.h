#pragma once
typedef struct NODE
{
	int data;
	struct NODE* lChild;
	struct NODE* rChild;
}NODE, *PNODE;
class CAvlTree
{
public:
	CAvlTree() = default;
	virtual ~CAvlTree(){}

	
	void show();
	int leftMax(PNODE node);
	int rightMin(PNODE node);
	PNODE insert(int nVal);
	PNODE erase(int nVal);
	int getHigh(PNODE node);
	PNODE leftTurn(PNODE node);
	PNODE rightTurn(PNODE node);
	PNODE leftRightTurn(PNODE node);
	PNODE rightLeftTurn(PNODE node);
	
private:
	//私有方法，供公有接口调用实现相应功能:
	//插入值为nVal的节点，从node节点开始向下寻找，找到正确的位置插入nVal，并使得二叉树平衡，返回原来的node节点.
	void show(PNODE Node, int w, char c);
	PNODE insert(PNODE& node, int nVal);
	PNODE erase(PNODE& node, int nVal);
private:
	PNODE m_root = nullptr;
};

