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
	//����һ���ڵ㣬����һ����Ҫ�����ֵ���Ӹýڵ㿪ʼ����Ѱ�ң�
	//����ȷ��λ�ò����ֵ��������ԭ���Ľڵ㡣
	PNODE insert(PNODE& node, int nVal);
	//����һ���ڵ㣬����һ����Ҫɾ����ֵ���Ӹýڵ㿪ʼ����Ѱ�ң�
	//����ȷ��λ��ɾ����ֵ��������ԭ���Ľڵ㡣
	PNODE erase(PNODE& node, int nVal);
	void show(PNODE Node, int w, char c);
private:
	PNODE m_root;
};