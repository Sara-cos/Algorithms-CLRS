//*BFS*//
//*Prasansha Satpathy*//
//*02- C2*//

#include <stdio.h>

int rear = 0 , front = -1;
int queue[100];
int color[100], dist[100], graph[100][100];
int nodes, edges;

int WHITE = 0;
int GRAY = 1;
int BLACK = 2;

void enqueue(int root_node)
{
	queue[rear] = root_node;
    rear = rear + 1;
}

int empty()
{
	if(front == rear-1)
	     return 0;
    else
	     return 1;
}

int dequeue()
{
    front = front + 1;
	return queue[front];
	    
}

void bfs()
{
	int x, y, i, t, j,src;
	
	for(i=1 ; i<= nodes; i++){
    	for(j=1 ; j<=nodes ; j++){
    		graph[i][j] == 0;
		}
   	}
   	
   	printf("Enter the src:");
    scanf("%d", &src);
	
    for (i = 0; i < edges; i++) {
    	
        printf("Edge %d: ", i);
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    
    for(i=0; i< nodes ; i++){
         for(j=0; j<nodes ;j++){
         	printf("%d\t", graph[i][j]);
		 }
		 printf("\n");
	}
	
    enqueue(src);
    
    color[src] = GRAY;
    dist[src] = 0;
   
   do {
        int u = dequeue();
        for (i = 0; i < nodes; i++) { 
            if ((graph[u][i] == 1) && (color[i] == WHITE)) {
                enqueue(i);
                color[i] = GRAY;
                dist[i] = dist[u] + 1;
            }
        }
        color[u] = BLACK;
        
    }while(empty());
	
}

void main() {
	
	int i;
    printf("Nodes, edges\n");
    scanf("%d %d", &nodes, &edges);
    
	for(i=0;i<nodes;i++)
       color[i] = WHITE;
	     
    bfs();
    
    for(i =0 ; i< nodes; i++){
    	printf("\n The distance of node %d : %d",i, dist[i]);
	}
         
}
