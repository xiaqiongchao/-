#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#define MAX_VERTEX_NUM 100

typedef char VertexNum;
typedef int  EdgeType;

bool visited[MAX_VERTEX_NUM];               // ���ʱ�־������

// �ڽӾ���
typedef struct {
    VertexNum Vex[MAX_VERTEX_NUM];                     // �����
    EdgeType  Edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    // �߱�
    int VertexNum, EdgeNum;                            // ��¼��ǰ�������ͱ���
}AMGraph; 

// �ڽӱ�
typedef struct EdgeNode {       // �߱�
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;
typedef struct VertexNode {     // �����
    VertexNum data;
    EdgeNode *firstedge;        // ���ָ��
}VertexNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
    AdjList adjList;
    int VertexNum, EdgeNum;
}ALGraph, *AdjListGraph;          // adjacent list

void CreateAMGraph(AMGraph &AM);
void CreateALGraph(ALGraph &G, AMGraph AM);

void DFS(ALGraph G, int v);
void DFSTraverse(ALGraph G);
void BFS(ALGraph G, SqQueue &Q);
void BFSTraverse(ALGraph G);

int main()
{
    AMGraph AM; CreateAMGraph(AM);
    ALGraph G;  CreateALGraph(G, AM);

    printf("��ʼ������ȱ�����"); DFSTraverse(G); printf("\n");
    printf("��ʼ������ȱ�����"); BFSTraverse(G); printf("\n");

    return 0;
}


void CreateAMGraph(AMGraph &AM){
    int i, j;
    AM.VertexNum = 9;
    AM.EdgeNum = 15;
    
    for(i=0; i<AM.VertexNum; i++) AM.Vex[i] = 'A' + i;          // ��ʼ������
    // for(i=0; i<AM.VertexNum; i++) printf("%c ", AM.Vex[i]);   printf("\n");

    for(i=0; i<AM.VertexNum; i++){
        for(j=0; j<AM.VertexNum; j++) 
            AM.Edge[i][j] = 0;   // ��ʼ���߱�
    }
    // ����ͼ��Ϣ
    AM.Edge[0][1]=1;
    AM.Edge[0][5]=1;
    
    AM.Edge[1][2]=1;
    AM.Edge[1][8]=1;
    AM.Edge[1][6]=1;
    
    AM.Edge[2][3]=1;
    AM.Edge[2][8]=1;
    
    AM.Edge[3][4]=1;
    AM.Edge[3][7]=1;
    AM.Edge[3][6]=1;
    AM.Edge[3][8]=1;
    
    AM.Edge[4][5]=1;
    AM.Edge[4][7]=1;
    
    AM.Edge[5][6]=1;
    
    AM.Edge[6][7]=1;

    //��������ͼ�ĶԳ��Թ��ɾ���
    for(i=0; i<AM.VertexNum; i++){
        for(j=i; j<AM.VertexNum; j++) 
            AM.Edge[j][i] = AM.Edge[i][j];
    }
}
void CreateALGraph(ALGraph &G, AMGraph AM){
    G.VertexNum = AM.VertexNum;
    G.EdgeNum = AM.EdgeNum;

    // ���������
    for(int i=0; i<AM.VertexNum; i++){
        G.adjList[i].data = AM.Vex[i];
        G.adjList[i].firstedge = NULL;
    }
    // �����߱�
    EdgeNode *e;
    for(int i=0; i<AM.VertexNum; i++){
        for(int j=0; j<AM.VertexNum; j++)
            if(AM.Edge[i][j] == 1){
                e = (EdgeNode *)malloc(sizeof(EdgeNode));
                e->adjvex = j;
                e->next = G.adjList[i].firstedge;
                G.adjList[i].firstedge = e;
            }
    }
}

void Visit(VertexNum v){
    printf("%c ", v);
}

void DFS(ALGraph G, int v)
{
    Visit(G.adjList[v].data);
    visited[v] = true;

    EdgeNode *p; p = G.adjList[v].firstedge;    
    while (p) {
        if(!visited[p->adjvex]) DFS(G, p->adjvex);
        p = p->next;
    }
}
void DFSTraverse(ALGraph G){
    for(int i=0; i<G.VertexNum; i++) visited[i] = false;
    for(int v=0; v<G.VertexNum; v++)
        if(!visited[v]) DFS(G, v);
}

void BFS(ALGraph G, SqQueue &Q, int v){
    Visit(G.adjList[v].data);
    visited[v] = true;
    EnQueue(Q, G.adjList[v].data);
    EdgeNode *p;
    while(!QueueEmpty(Q)){
        DeQueue(Q, v);
        p = G.adjList[v].firstedge;
        while(p){
            if(!visited[p->adjvex]){
                visited[p->adjvex] = true;
                Visit(G.adjList[p->adjvex].data);
                EnQueue(Q, p->adjvex);
            }
            p = p->next;
        }
    }
}
void BFSTraverse(ALGraph G){
    for(int i=0; i<G.VertexNum; i++) visited[i] = false;
    SqQueue Q; InitQueue(Q); 
    for(int v=0; v<G.VertexNum; v++)
        if(!visited[v]) BFS(G, Q, v);
}   
