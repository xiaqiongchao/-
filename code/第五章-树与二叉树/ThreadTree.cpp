#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXLEN 100
#define NLAYER 4

typedef struct ThreadNode {
    char data;
    struct ThreadNode *lchild, *rchild;     // ���Һ���ָ��
    int LTag, RTag;                       // ����������־
}ThreadNode, *ThreadTree;

bool InitThreadTree(ThreadTree &T);
void CreateThreadTree(ThreadTree &T);
void Visit(ThreadTree T);
void TranslevelPrint(ThreadTree bt);                       // ͼ����ʾ

void InThread(ThreadTree &p, ThreadTree &pre);  // ����������
void CreateInThread(ThreadTree &T);              

void InOrder(ThreadTree T);                    // �������
ThreadNode *FirstNode(ThreadNode *p);
ThreadNode *NextNode(ThreadNode *p); 

void InOrder1(ThreadTree T){
    if(T){
        InOrder1(T->lchild);
        Visit(T);
        InOrder1(T->rchild);
    }
}

int main()
{
    ThreadTree T; 
    InitThreadTree(T);
    CreateThreadTree(T); TranslevelPrint(T); printf("\n");  // ABD##E##CFH###G##

    printf("�����������ʽ������"); InOrder1(T); printf("\n");
    printf("������������ʽ������");
    CreateInThread(T);   
    InOrder(T);         


}
bool InitThreadTree(ThreadTree &T){
    if(T == NULL) return false;
    T = NULL; return true;
}
// ����ݹ鴴����ʽ
void CreateThreadTree(ThreadTree &T){
    char ch;
    scanf("%c", &ch);
    if(ch=='#') T = NULL;
    else {
        T = (ThreadTree)malloc(sizeof(ThreadNode));
        T->data = ch;
        T->LTag = 0;
        T->RTag = 0;
        CreateThreadTree(T->lchild);
        CreateThreadTree(T->rchild);
    }
}
void Visit(ThreadTree T){
    printf("%c ", T->data);
}

void CreateInThread(ThreadTree &T){
    ThreadTree pre = NULL;
    if(T != NULL){
        InThread(T, pre);           // ������
        pre->rchild = NULL;         // �������һ���ڵ�
        pre->RTag = 1;
    }
}
void InThread(ThreadTree &p, ThreadTree &pre){
    if(p != NULL){
        InThread(p->lchild, pre);               // �ݹ飬������������
        if(p->lchild==NULL){                    // ������Ϊ�գ�����ǰ������
            p->lchild = pre;
            p->LTag = 1;
        }
        if(pre!=NULL && pre->rchild==NULL){     // ������Ϊ�գ������������
            pre->rchild = p;
            pre->RTag = 1;
        }
        pre = p;                                // ��ǵ�ǰ�ڵ��Ϊ�ոշ��ʹ��Ľڵ�
        InThread(p->rchild, pre);               // �ݹ飬������������
    }
}
void InOrder(ThreadTree T){
    for(ThreadNode *p=FirstNode(T); p!=NULL; p=NextNode(p))
        Visit(p);
}
ThreadNode *FirstNode(ThreadNode *p){
    while(p->LTag==0)   p=p->lchild;            // Ѱ�������µĽڵ㣨��һ����Ҷ�ڵ㣩���ܻ�Ҫ�Һ���
    return p;
}
ThreadNode *NextNode(ThreadNode *p){
    if(p->RTag==0)  return FirstNode(p->rchild); // ���Һ��ӣ��򷵻��Һ��������������½ڵ�
    else return p->rchild;                       // û���Һ��ӣ�����ָ��Ϊ����
}










/**���δ�ӡ������**/
void TranslevelPrint(ThreadTree bt){
	struct node{							//�������� 
		ThreadTree	vec[MAXLEN];
		int layer[MAXLEN];					//������ڵĲ�
		int locate[MAXLEN]; 				//��ӡ������ڵ�λ��
		int front, rear; 
	}Q;										//�������Q
	int i, j=1, k=0, nLocate;
	Q.front=0;	Q.rear=0;					//��ʼ������Q��ͷ����β 
	printf(" ");
	Q.vec[Q.rear]=bt;						//�����������ڵ������ 
	Q.layer[Q.rear]=1;
	Q.locate[Q.rear]=20;
	Q.rear=Q.rear+1;
	while(Q.front<Q.rear)
	{
		bt=Q.vec[Q.front];
		i=Q.layer[Q.front];
		nLocate=Q.locate[Q.front];
		if(j<i)								//�����ӡʱ���� 
		{
			printf("\n");	printf("\n");
			j=j+1;	k=0;
			while(k<nLocate)
			{
				printf(" ");	k++;
			}/*endwhile*/ 
		}/*endif*/
		while(k<(nLocate-1))				//���ý����ȿ��ƽ��λ�� 
		{
			printf(" ");	k++;	
		}/*endwhile*/
		printf("%c", bt->data);
		Q.front=Q.front+1;
		if(bt->lchild!=NULL)				//�����������������������ڵ������ 
		{
			Q.vec[Q.rear]=bt->lchild;
			Q.layer[Q.rear]=i+1;
			Q.locate[Q.rear]=(int)(nLocate-pow(2, NLAYER-i-1));
			Q.rear=Q.rear+1;
		}/*endif*/
		if(bt->rchild!=NULL)				//���������������������������� 
		{
			Q.vec[Q.rear]=bt->rchild;
			Q.layer[Q.rear]=i+1;
			Q.locate[Q.rear]=(int)(nLocate+pow(2, NLAYER-i-1));
			Q.rear=Q.rear+1;
		}/*endif*/		 
	}/*endwhile*/ 
} 
