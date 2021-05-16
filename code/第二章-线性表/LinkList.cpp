#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{   // ���嵥����ڵ�����
    int data;           // ������
    struct LNode *next; // ָ����
}LNode, *LinkList;

bool InitList(LinkList &L); // �����ʼ��
bool DestroyList(LinkList &L);
bool ClearList(LinkList &L);
bool ListEmpty(LinkList L);
int ListLength(LinkList L);
LNode *GetElem(LinkList L, int i);              // ���ﰴ������
LNode *LocateElem(LinkList L, int e);           // ���ﰴ������
bool ListInsert(LinkList &L, int i, int e);
bool ListDelete(LinkList &L, int i, int &e);
void ListTraverse(LinkList L);
LinkList List_HeadInsert(LinkList &L);          // ���ﰴ������
LinkList List_TailInsert(LinkList &L);          // ���ﰴ������

bool InsertNextNode(LNode *p, int e);           // �α���ûҪ��
bool InsertPriorNode(LNode *p, int e);          // �α���ûҪ��
bool DeleteNode(LNode *p);                      // �α�ûҪ��

int main()
{
    LinkList L;
    // if(InitList(L)) printf("��ʼ���ɹ���");
    // else printf("��ʼ��ʧ�ܣ�");

    // List_HeadInsert(L);ListTraverse(L); // ͷ�巨
    List_TailInsert(L);ListTraverse(L); // β�巨

    // if(DestroyList(L)) printf("���ٳɹ���\n");
    // else printf("����ʧ�ܣ�\n");
    // ListTraverse(L);

    // if(ClearList(L)) printf("����ɹ���\n");
    // else printf("���ʧ�ܣ�\n");
    // ListTraverse(L);

    // if(ListEmpty(L)) printf("����Ϊ�գ�\n");
    // else printf("����Ϊ�գ�\n");

    printf("������ĵ�ǰ����Ϊ��%d\n", ListLength(L));

    LNode *target_node1, *target_node2;
    target_node1 = GetElem(L, 3);printf("��3��Ԫ��Ϊ��%d\n", target_node1->data);
    target_node2 = LocateElem(L, 51);printf("����%d�ɹ���\n", target_node2->data);

    if(ListInsert(L, 5, 666)) ListTraverse(L);
    else printf("����ʧ�ܣ�\n");

    int e;
    if(ListDelete(L, 7, e)) ListTraverse(L);
    else printf("ɾ��ʧ�ܣ�\n");

    return 0;
}

bool InitList(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));
    if(L == NULL) return false;
    L->next = NULL;
    return true;
}
bool DestroyList(LinkList &L){      // ���ͷ�ڵ�
    if(L == NULL) return false;
    LinkList p;
    p = L;
    while(p != NULL){
        p = L->next;
        free(L);
        L = p;
    }
    return true;
}
bool ClearList(LinkList &L){        // �����ͷ�ڵ�
    if(L == NULL) return false;
    LinkList pre, p;
    p = L->next;
    while(p != NULL){
        pre = p;
        p = p->next;
        free(pre);
    }
    L->next = NULL;
    return true;
}
bool ListEmpty(LinkList L){
    if(L != NULL && L->next == NULL) return true;
    else return false;
}
int ListLength(LinkList L){
    if(L == NULL || L->next == NULL) return 0;
    int i = 0;
    LinkList p = L->next;
    while(p != NULL){
        i++;
        p = p->next;
    }
    return i;
}
LNode *GetElem(LinkList L, int i){              // ��Ҫ�ι�����
    if(i < 1) return NULL;
    LinkList p = L;
    int j = 0;
    while(p != NULL && j < i){
        j++;
        p = p->next;
    }
    return p;
}
LNode *LocateElem(LinkList L, int e){
    if(L == NULL && L->next == NULL) return NULL;
    LinkList p = L->next;
    while(p != NULL && p->data != e) 
        p = p->next;
    return p;
}
bool ListInsert(LinkList &L, int i, int e){     // ˼·���ҵ���i-1���ڵ㣬�ڴ����½ڵ����
    if(L == NULL || i < 1) return false;
    LinkList p, s;
    int j = 0;
    p = L;
    while(p != NULL && j < i-1){
        j++;
        p = p->next;
    }
    if(p == NULL || j > i-1) return false;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool ListDelete(LinkList &L, int i, int &e){        // ���ҵ���i-1���ڵ㣬Ȼ��ɾ��i�ڵ�
    if(L == NULL || i < 1) return false;
    LinkList p = L, s;
    int j = 0;
    while(p->next != NULL && j < i-1){
        j++;
        p = p->next;
    }
    if(p->next == NULL || j > i-1) return false;
    s = p->next;
    e = s->data;
    p->next = s->next;
    free(s);
    return true;
}
// ��������
void ListTraverse(LinkList L){
    if(L == NULL || L->next == NULL) return;
    LinkList p;
    p = L->next;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
// ���ﰴ������ͷ�巨�ķ�������������
LinkList List_HeadInsert(LinkList &L){       // ������������
    LNode *p;
    int n = 10;     // Ĭ�ϲ���10��Ԫ��
    L = (LinkList)malloc(sizeof(LNode));     // ����ͷ�ڵ�
    L->next = NULL;
    for(int i=0; i<10; i++){
        p = (LinkList)malloc(sizeof(LNode)); // �����²���Ľڵ�
        p->data = i * i + 1;
        p->next = L->next;
        L->next = p;
    }
    return L;
}
// ���ﰴ������β�巨�ķ�������������
LinkList List_TailInsert(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));     // �����½ڵ�
    L->next = NULL;
    LNode *p, *q;
    int n = 10;                              // Ĭ�ϲ���10��Ԫ��
    q = L;                                   // *qΪ����ָ��
    for(int i=0; i<10; i++){
        p = (LinkList)malloc(sizeof(LNode)); // �����²���Ľڵ�
        p->data = i * i + 2;
        q->next = p;
        q = q->next;
    }
    p->next = NULL;
    return L;
}
bool InsertNextNode(LNode *p, int e){        // �ڵ���
    if(p == NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL) return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool InsertPriorNode(LNode *p, int e){      // ����ǰ�壬ʵ�ʺ��Ȼ�󽻻�Ԫ��
    if(p == NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    int temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}
bool DeleteNode(LNode *p){                  // ����ɾ��p�ڵ㣬ʵ����p�ĺ�̽ڵ㽻�����ݣ�ɾ��p�ĺ��
    if(p == NULL ) return false;
    LNode *s = p->next;
    p->data = s->data;
    p->next = s->next;
    free(s);
    return true;
}