//* Dijkstra Algorithm in implementation*//
//* By -01 & C2 - Prasansha Satpathy *//

#include<stdio.h>
#include<stdlib.h>
#define max 100

#define INF 9999

struct vertex{
	int d, pi, val;
}V[max];

int node, edges, q[max], S[max], c = 0, heapsize = -1;
int w[max][max];

void min_heapify(int);

void initialise_single_source(int s)
{
	int i;
	for(i = 1; i <= node; i++) 
		{
			
			V[i].d = INF;
		    V[i].pi = 0;
			
		}
	V[s].d = 0;
}


void insert_min_heap(int size, int p)
{
	int t;
	
	while(size > 0 && p >= 0 && V[q[size]].d < V[q[p]].d)
	{
		t = q[size];
		q[size] = q[p];
	    q[p] = t;
	    
		size = p;
	    p = (size - 1)/2;
    }	
		
}


int extract_min()
{
	int min;
	
	min = q[0];
	q[0] = q[heapsize];
	q[heapsize] = min;
	
	heapsize -= 1;
	min_heapify(0);
	
	return min;
}


void min_heapify(int n)
{
	int l, r, t;
	int smallest = n;
	
	l = 2 * n + 1;
	r = 2 * n + 2;
	
	if(l <= heapsize && V[q[l]].d < V[q[smallest]].d)
		smallest = l;
	if(r <= heapsize && V[q[r]].d < V[q[smallest]].d)
		smallest = r;
	
	if(smallest != n)
	{
		t = q[n];
		q[n] = q[smallest];
		q[smallest] = t;
		
		min_heapify(smallest);
	}
}


void relax(int u, int v, int w)
{
	int i, p, t;
	
	if(V[v].d > V[u].d + w)
	{
		V[v].d = V[u].d + w;
		
		V[v].pi = u;
		
		for(i = 0; i <= heapsize; i++)
			if(q[i] == v)
				break;
				
		p = (i - 1)/2;
		
		insert_min_heap(i, p);	
	}
}


int main()
{
	int i, j, g[max][max],s,d,size,p,u;
	
	printf("Nodes and edges:\n");
	scanf("%d%d",&node, &edges);
	
	for(i = 1; i <= node; i++)
		for(j = 1; j <= node; j++)
			g[i][j] = 0;
			
	
	printf("\n Source, Destined node, Weight for each edge:- \n");
	
	for(i = 0; i < edges; i++)
	{
		printf("Edge %d :-", i);
		scanf("%d %d %d",&s, &d, &j);
		g[s][d] = j;
	}
	
	printf("\nGraph:-\n");
	for(i = 1; i <=node; i++)
	{
		for(j = 1; j <= node; j++)
			printf("%d  ", g[i][j]);
		printf("\n");
	}
	
	printf("\nsource : ");
	scanf("%d", &s);
	
	initialise_single_source(s);
	
	for(i = 1; i <= node; i++){
		
		q[++heapsize] = i;
	    size = heapsize - 1;

	    p = (size-1)/2;
	    
	    insert_min_heap(size, p);
	}
	

	
	while(heapsize != -1)
	{
		u = extract_min();
		S[c++] = u;
		
		for(j = 1; j <= node; j++)
			if(g[u][j] > 0)
				relax(u, j, g[u][j]);
	}
	
	
	for(i = 1; i <= node; i++)
		printf("%d \t %d \n", i, V[i].d);
		
	
	printf("\n the path is: \n");
	
	for(i = 0; i < c; i++)
		printf("%d   ", S[i]);
	return 0;
}
