void dijkstra(AdjMatrix *G)
{
    int i,j;
    int min,minid;
    int tmp;
    int vs;
    int prev[MAX] = {0};
    int dist[MAX] = {0};
    int visited[MAX];      // visited[i]=1��ʾ"����vs"��"����i"�����·���ѳɹ���ȡ��

    // ��ʼ��
    printf("������Ҫ��ѯ�ĵ�Դ����");
    scanf("%d",&vs);
    vs-=1;
    for (i = 0; i < G->numV; i++)
    {
        visited[i] = 0;              // ����i�����·����û��ȡ����
        prev[i] = 0;              // ����i��ǰ������Ϊ0��
        dist[i] = G->Edge[vs][i];// ����i�����·��Ϊ"����vs"��"����i"��Ȩ��
    }
    // ��"����vs"���г�ʼ��
    visited[vs] = 1;//������vs�������·������Ӧ��visited[i]��Ϊ1 
    dist[vs] = 0;//���Լ���ȨΪ0 

    // ����G.vexnum-1�Σ�ÿ���ҳ�һ����������·����
    for (i = 1; i < G->numV; i++)
    {
        // Ѱ�ҵ�ǰ��С��·����
        // ������δ��ȡ���·���Ķ����У��ҵ���vs����Ķ���(minid)��
        min = INF;
        for (j = 0; j < G->numV; j++)
        {
            if (visited[j]==0 && dist[j]<min)
            {
                min = dist[j];
                minid = j;
            }
        }
        visited[minid] = 1;// ���"����minid"Ϊ�Ѿ���ȡ�����·��

        // ���µ�ǰ���·����ǰ������
        // �������Ѿ�"����minid�����·��"֮�󣬸���"δ��ȡ���·���Ķ�������·����ǰ������"��
        for (j = 0; j < G->numV; j++)
        {
            tmp = (G->Edge[minid][j]==INF ? INF : (min + G->Edge[minid][j]));// ��ֹ��� 

            if (visited[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = minid;
            }
        }
    }

    // ��ӡdijkstra���·���Ľ��
    printf("dijkstra(%c): \n", G->Vertices[vs]);
    for (i = 0; i < G->numV; i++)
        printf("  shortest(%c, %c)=%d\n", G->Vertices[vs], G->Vertices[i], dist[i]);
}
#include<stdio.h>
#include<stdlib.h>
#define MaxVertices 100 //�������100������
#define MaxWeight 32767 //���ڽ�ʱΪ32767�������ʱ�� "��"
#define MAX 100
#define INF         (~(0x1<<31)) 
typedef struct{ //����Ȩ���ڽӾ���ĵĶ���
    char Vertices[MaxVertices];  //������Ϣ������
    int Edge[MaxVertices][MaxVertices]; //�ߵ�Ȩ��Ϣ������
    int numV; //��ǰ�Ķ�����
    int numE; //��ǰ�ı���
}AdjMatrix;

void CreateGraph(AdjMatrix *G) //ͼ�����ɺ���
{ 
    int n,e,vi,vj,w,i,j;
    printf("������ͼ�Ķ������ͱ������Կո�ָ�����");
    scanf("%d%d",&n,&e);
    G->numV=n;G->numE=e;
    for(i=0;i<n;i++) //ͼ�ĳ�ʼ��
        for(j=0;j<n;j++)
            { 
            if(i==j)
                G->Edge[i][j]=0;
            else 
                G->Edge[i][j]=32767;
            }
    for(i=0;i<n;i++)
        for(i=0;i<G->numV;i++) //���������������
        { 
        printf("�������%d���������Ϣ(����):",i+1);  
      // G->adjlist[i].vertex=getchar(); 
        scanf(" %c",&G->Vertices[i]);
        }
    printf("\n");

    for(i=0;i<G->numE;i++)
    { 
        printf("������ߵ���Ϣi,j,w(�Կո�ָ�):");
        scanf("%d%d%d",&vi,&vj,&w); 
        //��Ϊ����Ȩֵ��ͼ����w����1
        //��Ϊ��Ȩֵ��ͼ����w�����ӦȨֵ

        G->Edge[vi-1][vj-1]=w;//��
        //G->Edge[vj-1][vi-1]=w;//��
        //����ͼ���жԳ��ԵĹ��ɣ�ͨ���٢�ʵ��
        //����ͼ���߱������ʣ�����ֻ��Ҫ��
    }
}
void DispGraph(AdjMatrix G) //����ڽӾ������Ϣ
{ 
    int i,j;
    printf("\n����������Ϣ�����ͣ�:\n");
    for(i=0;i<G.numV;i++)
        printf("%8c",G.Vertices[i]);

    printf("\n����ڽӾ���:\n");
    printf("\t");
    for(i=0;i<G.numV;i++)
        printf("%8c",G.Vertices[i]);

    for(i=0;i<G.numV;i++)
    { 
        printf("\n%8d",i+1);
        for(j=0;j<G.numV;j++)
        { 
        if(G.Edge[i][j]==32767) 
        //����֮��������ʱȨֵΪĬ�ϵ�32767�������ʱΪ�˷������ "��"
            printf("%8s", "��");
        else
            printf("%8d",G.Edge[i][j]);
        }
        printf("\n");   
    }
}
void dijkstra(AdjMatrix *G)
{
    int i,j;
    int min,minid;
    int tmp;
    int vs;
    int prev[MAX] = {0};
    int dist[MAX] = {0};
    int visited[MAX];      // visited[i]=1��ʾ"����vs"��"����i"�����·���ѳɹ���ȡ��

    // ��ʼ��
    printf("������Ҫ��ѯ�ĵ�Դ����");
    scanf("%d",&vs);
    vs-=1;
    for (i = 0; i < G->numV; i++)
    {
        visited[i] = 0;              // ����i�����·����û��ȡ����
        prev[i] = 0;              // ����i��ǰ������Ϊ0��
        dist[i] = G->Edge[vs][i];// ����i�����·��Ϊ"����vs"��"����i"��Ȩ��
    }
    // ��"����vs"���г�ʼ��
    visited[vs] = 1;//������vs�������·������Ӧ��visited[i]��Ϊ1 
    dist[vs] = 0;//���Լ���ȨΪ0 

    // ����G.vexnum-1�Σ�ÿ���ҳ�һ����������·����
    for (i = 1; i < G->numV; i++)
    {
        // Ѱ�ҵ�ǰ��С��·����
        // ������δ��ȡ���·���Ķ����У��ҵ���vs����Ķ���(minid)��
        min = INF;
        for (j = 0; j < G->numV; j++)
        {
            if (visited[j]==0 && dist[j]<min)
            {
                min = dist[j];
                minid = j;
            }
        }
        visited[minid] = 1;// ���"����minid"Ϊ�Ѿ���ȡ�����·��

        // ���µ�ǰ���·����ǰ������
        // �������Ѿ�"����minid�����·��"֮�󣬸���"δ��ȡ���·���Ķ�������·����ǰ������"��
        for (j = 0; j < G->numV; j++)
        {
            tmp = (G->Edge[minid][j]==INF ? INF : (min + G->Edge[minid][j]));// ��ֹ��� 

            if (visited[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = minid;
            }
        }
    }

    // ��ӡdijkstra���·���Ľ��
    printf("dijkstra(%c): \n", G->Vertices[vs]);
    for (i = 0; i < G->numV; i++)
        printf("  shortest(%c, %c)=%d\n", G->Vertices[vs], G->Vertices[i], dist[i]);
}
int main()
{ 
    AdjMatrix G;
    freopen("1.txt","r",stdin);
    CreateGraph(&G);
    dijkstra(&G);
    DispGraph(G);

}
��������������������������������
��Ȩ����������ΪCSDN������n.xuanrui����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/qq_39630587/article/details/77488550
