#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 100
#define NLAYER 4

typedef struct BSNode{
    int key;
    struct BSNode *lchild, *rchild;
}BSTNode, *BSTree;

void CreateBST(BSTree &T, int data[], int n);

BSTNode *SearchBST(BSTree T, int key);
int InsertBST(BSTree &T, int k);
bool DeleteBST(BSTree &T, int key);

void InOrder(BSTree T);
void TranslevelPrint(BSTree bt);

int main()
{
    int data[20]; 
    for(int i=0; i<20; i++) data[i] = rand()%100 + 1;
    BSTree T; CreateBST(T, data, 10); 
    printf("������������"); InOrder(T); printf("\n");
    TranslevelPrint(T); printf("\n");

    int x; printf("���������Ԫ�أ�"); scanf("%d", &x);
    BSTNode *t = SearchBST(T, x);
    if(t) printf("���ҳɹ����ýڵ�Ϊ��%d\n", t->key);

    if(DeleteBST(T, 63)){
        printf("ɾ���ɹ���\n"); TranslevelPrint(T);
    }
    else printf("ɾ��ʧ��\n");

}

void CreateBST(BSTree &T, int data[], int n){
    T = NULL;
    int i = 0;
    while(i < n){
        InsertBST(T, data[i]);
        i++;
    }
}
int InsertBST(BSTree &T, int k){
    if(T == NULL){
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    else if(k==T->key) return 0;
    else if(k<T->key) return InsertBST(T->lchild, k);
    else return InsertBST(T->rchild, k);
}
void InOrder(BSTree T){
    if(T){
        InOrder(T->lchild);
        printf("%d ", T->key);
        InOrder(T->rchild);
    }
}

BSTNode *SearchBST(BSTree T, int key){
    while(T!=NULL && key!=T->key){
        if(key<T->key) T = T->lchild;
        else T = T->rchild;
    }
    return T;
}
bool DeleteBST(BSTree &T, int key){
    BSTree x, y;
	x = T; y = NULL;
	int flag = -1;
	while(x->key != key){
		if(key > x->key){
			y = x;    //��¼���ڵ�
			x = x->rchild; 
			flag = 1;
		}else{
			y=x;
			x=x->lchild;
			flag=0;
		}	
	}
	if(x->key != key){
		x = NULL; y = NULL; 
		printf("�����ڴ�Ԫ�أ�\n");
		return false;
	}
	if(x != NULL){
		if(x->lchild != NULL && x->rchild != NULL){
	     	BSTree t = x;
			y = x; x = x->lchild;//������һ��
			while(x->rchild != NULL){
				y = x;
				x = x->rchild;//�����ߵ�ͷ 
			} 
			t->key = x->key;
			if(x->lchild != NULL) y->rchild = x->lchild;
			else y->rchild = NULL;
			free(x); 
			return true;	
		}else if(x->rchild != NULL && x->lchild == NULL){
		       if(y->lchild == x) y->lchild == x->rchild;	
		       else if(y->rchild == x) y->rchild = x->rchild;
		       free(x);
		       return true;
		}else if(x->lchild != NULL && x->rchild == NULL){
		    if(y->lchild == x) y->lchild = x->lchild;	
		    else if(y->rchild == x) y->rchild = x->lchild;
		    free(x);
		    return true;
		}
		else if(x->lchild == NULL && x->rchild == NULL){
			if(y->lchild == x) y->lchild = NULL;	
		    else if(y->rchild == x) y->rchild = NULL;
		    free(x);
		    return true;
		}
	}
}


void TranslevelPrint(BSTree bt){
	struct node{							//�������� 
		BSTree	vec[MAXLEN];
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
		printf("%d", bt->key);
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