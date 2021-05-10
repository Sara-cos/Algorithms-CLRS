//Prim algorithm
//01 & C2 Prasansha Satpathy

#include<stdio.h>
#define MAX 15
struct vertex
{
	int no,key,pi,pres,qp;
}ver[MAX];

int n,heapsize;


void MST_PRIM(int w[MAX][MAX],int r)
{
	struct vertex Q[MAX];
	int i,u,v;
	for(i=0;i<n;i++)
	{
		ver[i].no=i;
		ver[i].key=1000;
		ver[i].pi=-1;
		ver[i].pres=1;
	}
	ver[r].key=0;
	for(i=0;i<n;i++)
	{
		ver[i].qp=i;
		Q[i].key=ver[i].key;
		Q[i].no=ver[i].no;
	}
	BUILD_MIN_HEAP(Q);
	while(heapsize>0)
	{
		u=HEAP_EXTRACT_MIN(Q);
		for(v=0;v<n;v++)
		{
			if(w[u][v]!=0)
			{
				if(ver[v].pres==1 && w[u][v]<ver[v].key)
				{
					ver[v].pi=u;
					ver[v].key=w[u][v];
					
					HEAP_DECREASE_KEY(Q,ver[v].qp,w[u][v]);
				}
			}
		}
	}
}
void BUILD_MIN_HEAP(struct vertex Q[])
{
	int i;
	heapsize=n;
	for(i=n/2 - 1;i>=0;i--)
		MIN_HEAPIFY(Q,i);
}
void MIN_HEAPIFY(struct vertex Q[],int i)
{
	int l,r,smallest;
	l=LEFT(i);
	r=RIGHT(i);
	if (l<=heapsize-1 && Q[l].key < Q[i].key)
		smallest=l;
	else
		smallest=i;
	if(r<=heapsize-1 && Q[r].key < Q[smallest].key)
		smallest=r;
	if(smallest!=i)
	{
		swap(Q,i,smallest);
		MIN_HEAPIFY(Q,smallest);
	}
}
int HEAP_EXTRACT_MIN(struct vertex Q[])
{
	int min;
	if(heapsize<1)
		return -1;
	min=Q[0].no;
	ver[min].pres=0;
	swap(Q,0,heapsize-1);
	heapsize--;
	MIN_HEAPIFY(Q,0);
	return min;
}
void HEAP_DECREASE_KEY(struct vertex Q[],int i,int k)
{
	if(k>Q[i].key)
		return;
		
	Q[i].key=k;
	while(i>0 && Q[PARENT(i)].key > Q[i].key)
	{
		swap(Q,i,PARENT(i));
		i=PARENT(i);
	}
}

int LEFT(int i)
{
	return 2*i+1;
}
int RIGHT(int i)
{
	return 2*i+2;
}
int PARENT(int i)
{
	return (i-1)/2;
}

void swap(struct vertex Q[],int i,int j)
{
	struct vertex temp;
	temp.key=Q[i].key;
	temp.no=Q[i].no;

	Q[i].key=Q[j].key;
	Q[i].no=Q[j].no;

	Q[j].key=temp.key;
	Q[j].no=temp.no;

	ver[Q[i].no].qp=i;
	ver[Q[j].no].qp=j;
}

main()
{
	int i,j,w[MAX][MAX],root,totweight=0;
	int z,x,y, edges;
	
	printf("nodes , edges");
	scanf("%d%d",&n,&edges);
	
	for (i = 1; i <= edges; i++) {
    	
        printf("Edge %d: ", i);
        scanf("%d %d %d", &x, &y, &z);
        w[x][y] = z;
        w[y][x] = z;
    }
    
    printf("\nsource : ");
	scanf("%d", &root);
	
	MST_PRIM(w,root);
	printf("The edges of the spanning tree are:\n");
	printf("EDGE\tCOST\n");
	for(i=0;i<n;i++)
	{
		if(i==root)
			continue;
		printf("%d---%d\t%d\n",ver[i].pi,ver[i].no,ver[i].key);
		totweight+=ver[i].key;
	}
	printf("\nTotal weight of the spanning tree=%d",totweight);

}
