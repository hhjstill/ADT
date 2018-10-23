#pragma once

struct NODE
{
	int data;
	NODE* lChild, *rChild;
};
void creatPreTree(NODE*& T);
void eraseAll(NODE*& T);

