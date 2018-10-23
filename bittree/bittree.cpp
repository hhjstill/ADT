#include "bittree.h"
#include <string.h>
#include <stdio.h>
void creatPreTree(NODE*& T) {
	char c = getchar();
	if ('\n' == c)
		return;
	if ('#' == c)
		T = nullptr;
	else
	{
		T = new NODE;
		T->data = c;
		creatPreTree(T->lChild);
		creatPreTree(T->rChild);
	}
}
void eraseAll(NODE*& T) {
	if (!T)return;
	eraseAll(T->lChild);
	eraseAll(T->rChild);
	delete T;
	T = nullptr;
}
