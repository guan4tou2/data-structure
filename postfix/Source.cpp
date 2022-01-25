#include <iostream>
#include "Stack.h"
#define MAX_SIZE 100
using namespace std;
typedef enum{lparen,rparen,pplus,mminus,mtimes,divide,mod,eos,operand}precedence;
char token_symbol[] = { '(',')','+','-','*','/','%','\0' };
static int isp[] = { 0,19,12,12,13,13,13,0 };
static int icp[] = { 20,19,12,12,13,13,13,0 };
char expr[MAX_SIZE] = { '\0' };
char postExpr[MAX_SIZE] = { '\0' };
int ptr = 0;

precedence nextToken(char*expression, char *symbol, int *n) {
	*symbol = expression[(*n)++];
	if (*symbol == '\n')*symbol = expression[(*n)++];
	switch (*symbol)
	{
	case '(':return lparen;
	case ')':return rparen;
	case '+':return pplus;
	case '-':return mminus;
	case '/':return divide;
	case '*':return mtimes;
	case '%':return mod;
	case '\0':return eos;
	default:return operand;
	}
}
void postfix() {
	char symbol;
	precedence token;
	int n = 0;

	Stack<precedence> stack(MAX_SIZE);
	stack.Push(eos);
	for (token = nextToken(expr, &symbol, &n); token != eos; token = nextToken(expr, &symbol, &n)) {
		if (token == operand) {
			postExpr[ptr++] = symbol;
		}
		else if (token == rparen) {
			for (; stack.Top() != lparen; stack.Pop())
				postExpr[ptr++] = token_symbol[stack.Top()];
			stack.Pop();
		}
		else {
			for (; isp[stack.Top()] >= icp[token]; stack.Pop())
				postExpr[ptr++] = token_symbol[stack.Top()];
			stack.Push(token);
		}
	}
	for (; stack.Top()!=eos; postExpr[ptr++] == token_symbol[stack.Top()], stack.Pop());
	postExpr[ptr++] = token_symbol[eos];

	for (int i = 0; i < ptr; i++)cout << postExpr[i];
		cout<<endl;
 }
int eval() {
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	Stack<int> stack(MAX_SIZE);

	token = nextToken(postExpr, &symbol, &n);
	while (token != eos) {
		if (token == operand)
			stack.Push(symbol-'0');
		else {
			op2 = stack.Top(); stack.Pop();
			op1 = stack.Top(); stack.Pop();
			switch (token)
			{
			case pplus:stack.Push(op1 + op2); break;
			case mminus:stack.Push(op1 - op2); break;
			case mtimes:stack.Push(op1 * op2); break;
			case divide:stack.Push(op1 / op2); break;
			case mod:stack.Push(op1 % op2); break;
			default:break;
			}
		}
		token = nextToken(postExpr, &symbol, &n);
	}
	return stack.Top();
}
int main() {
	int result;
	cout << "輸入算式";
	fgets(expr, MAX_SIZE, stdin);
	cout << "後置運算式";
	postfix();
	result = eval();
	cout << "結果=" << result<<endl;
	system("pause"); return 0;
}
