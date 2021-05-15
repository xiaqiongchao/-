#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef int ElemType;

typedef struct Stack{
    int data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S);     // ��ʼ��ջ
bool StackEmpty(SqStack S);     // �ж�ջ��
bool Push(SqStack &S, int x);   // ��ջ
bool Pop(SqStack &S, int &x);   // ��ջ
bool GetTop(SqStack S, int &x); // ȡ��
void ClearStack(SqStack &S);    // ���
void TraverseStack(SqStack S);  // ����

int main()
{
    SqStack S;
    InitStack(S);

    if(StackEmpty(S)) printf("��ǰΪ��ջ��\n");
    else printf("��ǰջ�ǿգ�\n");

    for(int i=0; i<10; i++) Push(S, i);
    TraverseStack(S);

    int x;
    if(Pop(S, x)) printf("��ջ�ɹ���\n");
    else printf("��ջʧ�ܣ�\n");
    TraverseStack(S);

    if(GetTop(S, x)) printf("ջ��Ԫ��Ϊ��%d\n", x);
    else printf("ջ�������ڣ�\n");

    ClearStack(S);
    if(StackEmpty(S)) printf("��ǰΪ��ջ��\n");
    else printf("��ǰջ�ǿգ�\n");

    return 0;
}

void InitStack(SqStack &S){
    S.top = -1;
}
bool StackEmpty(SqStack S){
    if(S.top == -1) return true;
    else return false;
}
bool Push(SqStack &S, int x){
    if(S.top == MaxSize-1) return false;    // ��ǰջ��
    S.data[++S.top] = x;
    return true; 
}
bool Pop(SqStack &S, int &x){
    if(S.top == -1) return false;           // ջ�ձ���
    x = S.data[S.top--];
    return true;
}
bool GetTop(SqStack S, int &x){
    if(S.top == -1) return false;           // ջ�ձ���
    x = S.data[S.top];
    return true;
}
void ClearStack(SqStack &S){
    S.top = -1;
}
void TraverseStack(SqStack S){
    int p = S.top;
    while(p != -1) printf("%d ", S.data[p--]);
    printf("\n");
}