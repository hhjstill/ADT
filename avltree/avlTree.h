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
	//˽�з����������нӿڵ���ʵ����Ӧ����:
	//����ֵΪnVal�Ľڵ㣬��node�ڵ㿪ʼ����Ѱ�ң��ҵ���ȷ��λ�ò���nVal����ʹ�ö�����ƽ�⣬����ԭ����node�ڵ�.
	void show(PNODE Node, int w, char c);
	PNODE insert(PNODE& node, int nVal);
	PNODE erase(PNODE& node, int nVal);
private:
	PNODE m_root = nullptr;
};

