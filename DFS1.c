//*DFS*//
//*Prasansha Satpathy*//
//*02- C2*//

#include<stdio.h>
#include<stdlib.h>
# define max 30

struct vertex{
	int d, f, pi;
	char c;
}V[max];

int time = 0, nv, ar[max], p = 0, edges;

void print(int u)
{
	int i;
	printf("\n Order if source is %d :  ", u);
	for(i = 0; i < p; i++)
		printf("%d  ",ar[i]);
}


void dfs(int m[max][max])
{
	int v, u;
	for(u = 1; u <= nv; u++)
	{
		for(v = 1; v<=nv; v++)
		{
			V[v].c = 'w';
			V[v].pi = -1;
		}

		p = 0;
		for(v = u; v<=nv; v++)
			if(V[v].c == 'w')
				dfs_visit(v, m);
		print(u);
	}
}


void dfs_visit(int v, int m[max][max])
{
	int u;
	ar[p++] = v;
	V[v].c = 'g'; 
	time += 1;
	V[v].d = time;
	for(u = 1; u<=nv; u++)
		if(m[v][u] == 1)
			if(V[u].c == 'w')
			{
				V[u].pi = v;
				dfs_visit(u, m);
			}
	V[v].c = 'b';
	time += 1;
	V[v].f = time;
	
}


void main()
{
	int m[max][max], i, j,x,y;
	
	printf("nodes and edges: ");
	scanf("%d %d", &nv,&edges);
	
	for(i=1 ; i<= nv; i++){
    	for(j=1 ; j<= nv ; j++){
    		m[i][j] == 0;
		}
   	}
   	
   	for (i = 1; i <= edges; i++) {
    	
        printf("Edge %d: ", i);
        scanf("%d %d", &x, &y);
        m[x][y] = 1;
        m[y][x] = 1;
    }
	
	dfs(m);	
}

