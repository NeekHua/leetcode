#define maxsize 100
//˳��ջ����
typedef struct {
	int data[maxsize];
	int top;
}Sqstack;
//��ջ����
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode;
//˳����ж���
typedef struct {
	int data[maxsize];
	int head;
	int tail;
}SqQueue;
//��ʽ����
//�����
typedef struct QNode {
	int data;
	struct QNode *next;
}QNode;
//��ʽ����
typedef struct {
	QNode *front;
	QNode *rear;
}LiQueue;