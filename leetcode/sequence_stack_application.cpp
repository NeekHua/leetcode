#include <iostream>
using namespace std;
#define maxsize 100
//��д���������׺ʽ����ֵ
int op(int a, int b, char op) {//���a op b�ļ���
	if ( op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	if (op == '*')
		return a * b;
	else {
		if (b == 0)
		{
			cout<< "error" <<endl;
			return 0;
		}
		else
			return a / b;
	}
}
int com(char op[]) {//��׺ʽ���㺯��
	int i, a, b, c;
	int stack[maxsize]; int top = -1;

}