#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20
#define INIT_SIZE 10
#define INCR_SIZE 10

typedef int ElemType;

// ��̬����
typedef struct {
    int data[MAX_SIZE];
    int length;
}SqList;
//��̬����
typedef struct {
    int *data;
    int MaxSize;
    int length;
}D_SqList;

bool InitList(SqList &L);                       // ��̬��ʼ��
bool D_InitList(D_SqList &L);                   // ��̬��ʼ��
bool DestroyList(SqList &L);                    // ���ٱ�
bool ClearList(SqList &L);                      // ��ձ�
bool ListEmpty(SqList L);                       // �жϷǿ�
int ListLength(SqList L);                       // ���
int GetElem(SqList L, int i);                   // ��λ����
int LocateElem(SqList L, int e);                // ��ֵ����
bool PriorElem(SqList L, int e, int &pre_e);    // ����ǰ��
bool NextElem(SqList L, int e, int &next_e);    // ���غ��
bool ListInsert(SqList &L, int i, int e);       // ����Ԫ��
bool ListDelete(SqList &L, int i, int &e);      // ɾ��Ԫ��
void TraverseList(SqList L);                    // ��ӡ���

void BasicFunTest();                            // ���ڲ��Ի������ܺ���

///�����κ�ϰ�����ʵ��  p19
bool Del_Min(SqList &L, int &value);            // ɾ����СԪ��
void Reverse(SqList &L);                        // ˳�������
void Del_x(SqList &L, int x);                   // ɾ�����е���x��Ԫ��
bool Del_s_t(SqList &L, int s, int t);          // ɾ������s-t֮���Ԫ��
bool Delete_same(SqList &L);                    // ɾ�����������ظ���Ԫ��
bool Merge(SqList A, SqList B, D_SqList &C);    // ˳���ĺϲ�����Ҫ�ι�����
void SearchChangeInsert(SqList &L, int x);      // �����Ķ�������+����+����

int main()
{
    // BasicFunTest();

    // SqList OrderlyList;
    // InitList(OrderlyList);
    // for(int i=0; i<10; i++){
    //     OrderlyList.data[i] = i*i + 1;
    //     OrderlyList.length++;
    // }
    // TraverseList(OrderlyList);

    // Reverse(OrderlyList);

    // int value;
    // Del_Min(OrderlyList, value);
    // TraverseList(OrderlyList);

    // Del_x(OrderlyList, 26);
    // TraverseList(OrderlyList);

    // Del_s_t(OrderlyList, 10, 50);
    // TraverseList(OrderlyList);

    // OrderlyList.length = 0;
    // for(int i=0; i<10; i++){
    //     OrderlyList.data[i] = 3;
    //     OrderlyList.length++;
    // }
    // TraverseList(OrderlyList);
    // Delete_same(OrderlyList);
    // TraverseList(OrderlyList);
    
    // // �ϲ�����
    // SqList A, B;
    // D_SqList C;
    // InitList(A);
    // InitList(B);
    // D_InitList(C);
    // for(int i=0; i<10; i++){
    //     A.data[i] = i + 1;
    //     A.length++;
    // }
    // for(int i=0; i<10; i++){
    //     B.data[i] = (i + 1)*3;
    //     B.length++;
    // }
    // TraverseList(A);printf("\n");
    // TraverseList(B);printf("\n");

    // Merge(A, B, C);
    // for(int i=0; i<C.length; i++)
    //     printf("%d ", C.data[i]);
    // printf("\n�ϲ���C�ĳ���Ϊ��%d\n", C.length);

    // SqList A;
    // InitList(A);
    // for(int i=0; i<9; i++){
    //     A.data[i] = i*i+1;
    //     A.length++;
    // }
    // TraverseList(A);
    // SearchChangeInsert(A, 26);
    // TraverseList(A);

}

void BasicFunTest(){
        SqList TestList;
    if(InitList(TestList)) printf("��̬�����ʼ���ɹ���\n");
    else printf("��̬�����ʼ��ʧ�ܣ�\n");

    for(int i = 0; i < 10; i++){
        TestList.data[i] = i*i+3;
        TestList.length++;
    }
    TraverseList(TestList);

    D_SqList D_TestList;
    if(D_InitList(D_TestList)) printf("��̬�����ʼ���ɹ���\n");
    else printf("��̬�����ʼ��ʧ�ܣ�\n");

    if(ListEmpty(TestList)) printf("�˱�Ϊ�ձ�\n");
    else printf("�˱�Ϊ�ձ�\n");

    printf("��ǰ��Ϊ��%d\n", ListLength(TestList));
    // if(GetElem(TestList, 100)) printf("���ҳɹ���\n");
    // else printf("����ʧ�ܣ�\n");
    printf("��3��Ԫ��Ϊ��%d\n", GetElem(TestList, 3));

    printf("52����λ��%d\n", LocateElem(TestList, 52));

    int b = 666;
    if(ListInsert(TestList, 7, b)){
        printf("����ɹ��������Ԫ��Ϊ��%d\n", b);
        TraverseList(TestList);
    } else printf("����ʧ�ܣ�\n");

    int a;
    if(ListDelete(TestList, 8, a)){
        printf("ɾ���ɹ���ɾ����Ԫ��Ϊ��%d\n", a);
        TraverseList(TestList);
    } else printf("ɾ��ʧ��\n");
}

// ��̬�����ʼ��
bool InitList(SqList &L){
    for(int i=0; i<MAX_SIZE; i++)
        L.data[i]=0;
    L.length=0;
    return true;
}
// ��̬�����ʼ��
bool D_InitList(D_SqList &L){
    L.data = (int *)malloc(INIT_SIZE*sizeof(int)*10);
    if(L.data == NULL) return false;
    L.length = 0;
    L.MaxSize = INIT_SIZE*10;
    return true;
}
// ��Զ�̬���������ٷ�ʽ
bool DestroyList(D_SqList &L){
    if(L.data == NULL) return false;
    free(L.data);
    L.data = NULL;
    L.length = 0;
    L.MaxSize = 0;
    return true;
}
// �������տռ�
bool ClearList(SqList &L){
    L.length = 0;
    return true;
}
// �жϱ��Ƿ�Ϊ��
bool ListEmpty(SqList L){
    return L.length == 0 ? true : false;
}
// ���ر�
int ListLength(SqList L){
    return L.length;
}
// ��λ���� ����i�ķ�ΧΪ[1, length]���ҵ��򷵻ض�Ӧ��ֵ
int GetElem(SqList L, int i){
    if(i < 1 || i > L.length) return -1;
    return L.data[i - 1];
}
// ��ֵ���ң��ҵ��򷵻�λ��
int LocateElem(SqList L, int e){
    for(int i = 0; i < L.length; i++)
        if(L.data[i] == e)  return i+1;
    return -1;
}
// ����Ԫ�أ������λ����[i, length]֮��
bool ListInsert(SqList &L, int i, int e){
    if(i < 1 || i > L.length+1) return false;   // ����λ�ò��Ϸ�
    if(L.length >= MAX_SIZE)    return false;   // ��ǰ������
    for(int j=L.length; j>=i; j--)
        L.data[j] = L.data[j-1];                // Ԫ�����κ���
    L.data[i-1] = e;
    L.length++;
    return true;
}
// ɾ��Ԫ�أ�ɾ����λ����[i, length]֮��
bool ListDelete(SqList &L, int i, int &e){
    if(i < 1 || i > L.length+1) return false;
    e = L.data[i - 1];
    for(int j=i; j<L.length; j++)
        L.data[j-1] = L.data[j];
    L.length--;
    return true;    
}
// ��������ñ�
void TraverseList(SqList L){
    for(int i = 0; i < L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
}


/******�����κ�ϰ���е�����******/
// ��1��ɾ����Сֵ���ճ���λ����ĩβԪ���
bool Del_Min(SqList &L, int &value){
    if(L.length == 0) return false;
    value = L.data[0];      // �����һ����С
    int pos = 0;
    for(int i=1; i<L.length; i++){
        if(L.data[i] < value){
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length-1];
    L.length--;
    return true;
}

// ��2��˳��������
void Reverse(SqList &L){
    int temp, i = 0, j = L.length-1;
    for(; i < j;){
        temp = L.data[i]=0;
        L.data[i++] = L.data[j];
        L.data[j--] = temp;
    }
}

// ��3��ɾ�����е���x��Ԫ��
void Del_x(SqList &L, int x){
    int k=0, i=0;
    while(i < L.length){
        if (L.data[i] == x) k++;
        else L.data[i-k] = L.data[i];
        i++;
    }
    L.length = L.length - k;
}

// ��5��ɾ��˳���������s-t֮���Ԫ��
bool Del_s_t(SqList &L, int s, int t){
    if(L.length == 0 || s >= t) return false;
    int k = 0, i = 0;
    for(; i < L.length; i++){
        if(L.data[i] >= s && L.data[i] <= t)  k++;
        else L.data[i-k] = L.data[i];
    }
    L.length = L.length - k;
    return true;
}
// ��6��ɾ�����������ظ���Ԫ��
bool Delete_same(SqList &L){
    if(L.length == 0)   return false;
    int i, j;
    for(i=0, j=1; i<L.length; j++)      // i�洢��һ������ͬ��Ԫ�أ�jΪ����ָ��
        if(L.data[i] != L.data[j])      // ������һ������һ������ͬ��Ԫ��
            L.data[++i] = L.data[j];    // �ҵ���Ԫ��ǰ��
    L.length = i + 1;
    return true;
}
// ��7�������ĺϲ�
bool Merge(SqList A, SqList B, D_SqList &C){
    if(A.length + B.length > C.MaxSize) return false;
    int i=0, j=0, k=0;
    while(i < A.length && j < B.length){
        if(A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else 
            C.data[k++] = B.data[j++];
    }
    while(i < A.length) C.data[k++] = A.data[i++];
    while(j < B.length) C.data[k++] = B.data[j++];
    C.length = k;
    return true;
}
// ��9�������Ķ�������+����+����
void SearchChangeInsert(SqList &L, int x){
    int low=0, high=L.length-1, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(L.data[mid] == x) break;
        else if(L.data[mid] < x) low = mid + 1;
        else high = mid - 1; 
    }

    if(L.data[mid] == x && mid != L.length-1){
        int temp = L.data[mid];
        L.data[mid] = L.data[mid+1];
        L.data[mid+1] = temp;
    }

    if(low > high){
        int i;
        for(i=L.length-1; i>high; i--)
            L.data[i+1] = L.data[i];        // ��κ���Ԫ��
        L.data[i+1] = x;
        L.length++;
    }
}
