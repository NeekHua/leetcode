typedef struct DLNode {
	int data;
	struct DLNode *next;
	struct DLNode *piror;
}DLNode;
void CreateDlistR(DLNode *&L, int a[], int n) {
	DLNode *s, *r;
	int i;
	s = L;
	for (i = 0; i < n; ++i) {
		r->data = a[i];
		s->next = r;
		r->piror = s;
		s = r;
	}
	s->next = nullptr;
}
//����˫����ĳԪ��
DLNode *searchNode(DLNode *l, int x) {
	DLNode *p;
	p = l->next;
	while (p!=nullptr)
	{
		if (p->data = x) {
			break;
		}
		p = p->next;
	} 
	return p;
}
//����ĳԪ�ؽ���˫����
void insert_elem() {
	DLNode *p, *s;
	s->next = p->next;
	s->piror = p;
	p->next = s;
	s->next->piror = s;
}
//ɾ�����
void delete_elem_DLNode() {
	DLNode *p, *s;
	p->next = p->next->next;
	p->next->piror = p;
}