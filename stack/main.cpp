#include "stack.h"
#include <stdio.h>
#include <ctype.h>
int main()
{
	CStack stack1, stack2;
	//双栈实现逆波兰计算器

	//1.用户输入中缀表达式
	printf("输入中缀表达式：");
	//2.中缀表达式转后缀表达式
	char c = getchar();
	int e = 0;
	while (c != '\n')
	{
		if (isdigit(c))//是数字，入栈2
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
	//3 * （6 + 8 * 2 - 5）- 2 * （6 - 1） - 3 == 3682*+5-*261-*-3-

	//规则:

	//1.如果是数字，则压入栈2，如果是左括号则压入栈1
	//2.如果是右括号则符号依次出栈并压入栈2（括号不压栈）直到遇见左括号为止（左括号也要出栈）
	//3.如果是+ - * /则比较其与栈顶符号的优先级，如果比栈顶符号优先级高则入栈，否则栈顶符号出栈，自己入栈
	//4.直到表达式结束，栈1剩余的元素依次出栈直至空栈

	//把stack2的元素依次弹出压入stack1,逆序。
	while (!stack2.empty())
	{
		stack2.pop(e);
		stack1.push(e);
	}
	//3.计算后缀表达式结果
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