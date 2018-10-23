#include "stack.h"
#include <stdio.h>
#include <ctype.h>
int main()
{
	CStack stack1, stack2;
	//˫ջʵ���沨��������

	//1.�û�������׺���ʽ
	printf("������׺���ʽ��");
	//2.��׺���ʽת��׺���ʽ
	char c = getchar();
	int e = 0;
	while (c != '\n')
	{
		if (isdigit(c))//�����֣���ջ2
			stack2.push(c);
		else
		{
			switch (c)
			{
			case '(':
				stack1.push(c);
				break;
			case ')':
				stack1.pop(e);
				while (e != '(')
				{
					stack2.push(e);
					stack1.pop(e);
				}
				break;
			case '+':case '-':
				while (stack1.getTopElem(e) && e != '(')
				{
					stack1.pop(e);
					stack2.push(e);
				}
				stack1.push(c);
				break;
			case '*':case '/':
				while (stack1.getTopElem(e) && e != '(' && e != '+' && e != '-')
				{
					stack1.pop(e);
					stack2.push(e);
				}
				stack1.push(c);
				break;
			default:
				break;
			}
		}

		c = getchar();
	}
	while (!stack1.empty())
	{
		stack1.pop(e);
		stack2.push(e);
	}
	
	//5 * (1 + 2) == 512 + *
	//1 + 3 * (4 + 5) - 6 / 2 == 1345+*+62/-
	//3 * ��6 + 8 * 2 - 5��- 2 * ��6 - 1�� - 3 == 3682*+5-*261-*-3-

	//����:

	//1.��������֣���ѹ��ջ2���������������ѹ��ջ1
	//2.�������������������γ�ջ��ѹ��ջ2�����Ų�ѹջ��ֱ������������Ϊֹ��������ҲҪ��ջ��
	//3.�����+ - * /��Ƚ�����ջ�����ŵ����ȼ��������ջ���������ȼ�������ջ������ջ�����ų�ջ���Լ���ջ
	//4.ֱ�����ʽ������ջ1ʣ���Ԫ�����γ�ջֱ����ջ

	//��stack2��Ԫ�����ε���ѹ��stack1,����
	while (!stack2.empty())
	{
		stack2.pop(e);
		stack1.push(e);
	}
	//3.�����׺���ʽ���
	int result = 0;
	while (!stack1.empty())
	{
		stack1.pop(e);
		if (isdigit(e))
			stack2.push(e);
		else
		{
			switch (e)
			{
			case '+':
				stack2.pop(result);
				stack2.pop(e);
				stack2.push((e - 48) + (result - 48) + 48);
				break;
			case '-':
				stack2.pop(result);
				stack2.pop(e);
				stack2.push(e - result + 48);
				break;
			case '*':
				stack2.pop(result);
				stack2.pop(e);
				stack2.push((e - 48) * (result - 48) + 48);
				break;
			case '/':
				stack2.pop(result);
				stack2.pop(e);
				stack2.push((e - 48) /(result - 48) + 48);
				break;
			}
		}
	}
	stack2.pop(result);
	printf("%d\n", result - 48);
	return 0;
	
}