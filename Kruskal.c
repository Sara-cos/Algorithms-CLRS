//Kruskal algorithm
//01 & C2 Prasansha Satpathy

#include<stdio.h>
#define MAX 30

int Graph[MAX][MAX], n;

struct Edge{
  int u, v, w;
} temp;

struct edge_list {
  struct Edge data[MAX];
  int n;
}EL, spanlist;

void Union(int[], int, int);
void sort(); 

void kruskal()
{
    int belongs[MAX], i, j, c1, c2;
  
    EL.n = 1;
    spanlist.n = 1;
  
    for (i = 1; i <= n; i++){
    	for (j = 1; j <= n; j++) {
        	printf("%d\t",Graph[i][j]);
		}
		printf("\n");
	}
        

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
    	
            if (Graph[i][j] != 0) {
      	
                EL.data[EL.n].u = i;
                EL.data[EL.n].v = j;
                EL.data[EL.n].w = Graph[i][j];
        
            EL.n++;
      }
    }
    


    sort();

    for (i = 1; i <= n; i++)
        belongs[i] = i;

    for (i = 1; i <= EL.n-1; i++) {
    	
        c1 = find(belongs, EL.data[i].u);
        c2 = find(belongs, EL.data[i].v);
        
        if (c1 != c2) {
        spanlist.data[spanlist.n] = EL.data[i];
        spanlist.n++;
        
        Union(belongs, c1, c2);
    }
  }
}


int find(int belongs[], int vertexno) {

  return (belongs[vertexno]);
  
}


void Union(int belongs[], int c1, int c2) 
{
    int i;
    for (i = 1; i <= n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}


void sort() 
{
  
  int i, j;

    for (i = 1; i <= EL.n; i++) {
  	    for (j = 1; j <=EL.n - 1; j++){
  	    	if (EL.data[j].w > EL.data[j + 1].w) {
        
	         	temp = EL.data[j];
                EL.data[j] = EL.data[j + 1];
                EL.data[j + 1] = temp;
      
	        }
	   }
    }	
  
}

void print() 
{
	
  int i, cost = 1;

  for (i = 1; i <= spanlist.n-1; i++) {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
}

void main()
{

   int i, j, ne, x, y, z;
   
   printf("nodes, edges\n");
   scanf("%d%d", &n, &ne);
   
    
    for (i = 1; i <= ne; i++) {
    	
        printf("Edge %d: ", i);
        scanf("%d %d %d", &x, &y, &z);
        Graph[x][y] = z;
        Graph[y][x] = z;
    }

    kruskal();
    print();
}
