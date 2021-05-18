#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];  // ����
    int front;          // ��ͷ
    int rear;           // ��β
} SqQueue;

void InitQueue(SqQueue &Q);         // ��ʼ��
void ClearQueue(SqQueue &Q);        // ���
bool QueueEmpty(SqQueue Q);         // �жϷǿ�
int QueueLength(SqQueue Q);         // ���г��� ��Q.rear - Q.front + MaxSize) % MaxSize
bool GetHead(SqQueue Q, int &x);    // ��ͷ
bool EnQueue(SqQueue &Q, int x);    // ���
bool DeQueue(SqQueue &Q, int &x);   // ����
void QueueTraverse(SqQueue Q);      // ����

int main()
{
    SqQueue Q;
    InitQueue(Q);

    if(QueueEmpty(Q)) printf("����Ϊ�գ�\n");
    else printf("���зǿգ�\n");

    for(int i=0; i<10; i++) EnQueue(Q, i);
    QueueTraverse(Q);

    printf("��ǰ���г���Ϊ��%d\n", QueueLength(Q));    

    int x;
    if(GetHead(Q, x)) printf("��ͷԪ��Ϊ��%d\n", x);
    else printf("����Ϊ�գ�\n");

    if(DeQueue(Q, x)) printf("����Ԫ��Ϊ��%d\n", x);
    else printf("����Ϊ�գ�\n");
}

void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}
void ClearQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}
bool QueueEmpty(SqQueue Q){
    if(Q.rear == Q.front) return true;
    else return false;
}
int QueueLength(SqQueue Q){
    if(Q.rear == Q.front) return 0;
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}
bool GetHead(SqQueue Q, int &x){
    if(Q.rear != Q.front){
        x = Q.data[Q.front];
        return true;
    } else return false;
}
bool EnQueue(SqQueue &Q, int x){
    if((Q.rear+1) % MaxSize == Q.front) return false;   // �����������������ַ����ж϶������˷�һ���洢�ռ�
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1) % MaxSize;
    return true;
}
bool DeQueue(SqQueue &Q, int &x){
    if(Q.rear == Q.front) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize;
    return true;
}
void QueueTraverse(SqQueue Q){
    for(int i=Q.front; i != Q.rear; i=(i+1) % MaxSize)
        printf("%d ", Q.data[i]);
    printf("\n");
}
