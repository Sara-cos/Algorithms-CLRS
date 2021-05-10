//* Bellman-Ford Algorithm in implementation*//
//* By -01 & C2 - Prasansha Satpathy *//

#include<stdio.h>
#include<stdlib.h>
#define max 100

#define INF 9999

struct vertex{
	int d, pi, val;
}V[max];

struct Edge{
  int u, v, w;
};

struct edge_list {
  struct Edge data[max];
  int n;
}EL;

void relax();

int nodes, edges, Graph[max][max], S[max];

void initialise_single_source(int s)
{
	int i;
	for(i = 1; i <= nodes; i++) 
		{
			
			V[i].d = INF;
		    V[i].pi = -1;
			
		}
	V[s].d = 0;
}

int Bellman_ford(int s)
{
	int i, j, u, v, w;
	
	initialise_single_source(s);
	
	for(i=1;i<= nodes-1 ;i++)
	{
		for(i=1;i< edges;i++)
		{
			relax();
		}
	}
	
	for (i = 1; i <= nodes - 1; i++) {
         for (j = 1; j <= edges; j++) {
            u = EL.data[j].u;
            v = EL.data[j].v;
            w = EL.data[j].w;
            
            if(V[u].d != INF && V[v].d > V[u].d + w)
            {
            	
                return 0;
			}
                
			else
			    return 1;
        }
            
        
    }
    
    
}

void relax()
{
	int i , j, u, v, w;
	
	for (i = 1; i <= nodes; i++) {
		
         for (j = 1; j <= edges; j++) {
            u = EL.data[j].u;
            v = EL.data[j].v;
            w = EL.data[j].w;
            
            if(V[u].d != INF && V[v].d > (V[u].d + w))
            {
      	        S[j] = v;
      	        S[i] = u;
				V[v].d = V[u].d + w;
      	        V[v].pi = u;
      	        
      	    }
	        
	    }

    }
    
    
}

void main()
{

   int i, j, x, y, z, s;
   
   printf("nodes, edges\n");
   scanf("%d%d", &nodes, &edges);
   
   for(i = 1; i <= nodes; i++)
		for(j = 0; j < nodes; j++)
			Graph[i][j] = 0;
    
    for (i = 1; i <= edges; i++) {
    	
        printf("Edge %d: ", i);
        scanf("%d %d %d", &x, &y, &z);
        Graph[x][y] = z;
    }
    
    printf("\nGraph:-\n");
	for(i = 1; i <= nodes; i++)
	{
		for(j = 1; j <= nodes; j++)
			printf("%d  ", Graph[i][j]);
		printf("\n");
	}
	
	printf("\nsource : ");
	scanf("%d", &s);
	
	EL.n = 0;
	
	for (i = 1; i <= edges; i++)
        for (j = 1; j <= edges; j++) {
    	
            if (Graph[i][j] != 0) {
      	
                EL.data[EL.n].u = i;
                EL.data[EL.n].v = j;
                EL.data[EL.n].w = Graph[i][j];
        
            EL.n++;
      }
    }
	
	int bool_value = Bellman_ford(s);
	
	if(bool_value == 0)
	     printf("\nNegetive Cycle Detected!\n");
    else
    {
    	printf("distances:-\n");
    	for(i = 1; i <= nodes; i++)
		    printf("%d \t %d \n", i, V[i].d);
		    
		printf("\nPath:-\n");
		for(i=1; i<nodes ; i++)
		    printf("%d\t", S[i]);
		        
	}
    
}
