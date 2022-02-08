#include<iostream>
using namespace std;

typedef struct BTNode {
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;
//�������
void preorder(BTNode *p) {
	if (p != nullptr) {
		p->data;
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
//���������
int getDepth(BTNode *p) {
	int pdeep, rdeep;
	if (p == nullptr) {
		return 0;
	}
	else {
		pdeep = getDepth(p->lchild);
		rdeep = getDepth(p->rchild);
		return (pdeep > rdeep ? pdeep : rdeep) + 1;
	}
}
//Ѱ�ҵ�k���ڵ�
//�������
void find(BTNode *b,int k) {
	int n = 0;
	if (b != nullptr) {
		++n;
		if (k == n) {
			cout << b->data << endl;
			return;
		}
		find(b->lchild, k);
		find(b->rchild, k);
	}
}
//�������
void find_middle(BTNode *b, int k) {
	int n = 0;
	if (b != nullptr) {
	find_middle(b->lchild,k);
		++n;
		if (k == n) {
			cout << b->data << endl;
			return;
		}
	find_middle(b->rchild, k);
	}
	
}
