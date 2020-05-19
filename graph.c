// Author - TG1999 <tushar.goel.dav@gmail.com>

# include <stdio.h>

typedef struct edge
{
    int src;
    int dest;
    int wt;
};

typedef struct queue
{
    int arr[1000];
    int front;
    int rear;
    queue()
    {
        front = 0;
        rear = 0;
        arr[0]=0;
    }
    void push(int ele)
    {
        arr[rear] = ele;
        rear++;
    }
    void pop()
    {   if(!empty())
        front++;
        else
        printf("Can not empty");
    }
    int top()
    {
        return arr[front];
    }
    bool empty()
    {
        return front==rear;
    }
    int len()
    {
        return rear - front;
    }
};

typedef struct graph
{
queue grph[1000];
edge edges[1000];
int en;
bool visited[1000] ;
bool used[1000];
graph()
    {
      en = 0;
    }
void addedge(int src,int dest,int wt,bool bidir)
{
grph[src].push(dest);
edge new_edge;
new_edge.src = src;
new_edge.dest = dest;
new_edge.wt = wt;
edges[en]=new_edge;
en++;
if(bidir)
{grph[dest].push(src);
edge new_edge;
new_edge.src = src;
new_edge.dest = dest;
new_edge.wt = wt; 
edges[en]=new_edge;
en++;
} 
}
void bfs(int src)
{
queue q;
q.push(src);
bool visited[1000] ;
visited[src] = true;
while(!q.empty())
{
    int ele= q.top();
    q.pop();
    printf("%d\n",ele);
    for(int i=0;i < grph[ele].len();i++)
    {   
        if(!visited[grph[ele].arr[i]])
        {
            q.push(grph[ele].arr[i]);
        }
    }
}
}

void dfs(int src)
{
printf("%d\n",src);
visited[src] = true;
 for(int i=0;i < grph[src].len();i++)
 {
     if(!visited[grph[src].arr[i]])
        dfs(grph[src].arr[i]);
 }
}

 
int cyclic_recursive(int vertex, int predecessor)
{
    int i;
    int cycle_found = 0;
    visited[vertex] = 1;
    for (i = 0; i < en && !cycle_found; i++) {
        if ((edges[i].src == vertex || edges[i].dest == vertex)&& used[i]) {
            /* Adjacent */
            const int neighbour = edges[i].src == vertex ?
                    edges[i].dest : edges[i].src;
            if (visited[neighbour] == 0 && used[neighbour]) {
                /* Not yet visited */
                cycle_found = cyclic_recursive(neighbour, vertex);
            }
            else if (neighbour != predecessor) {
                /* Found a cycle */
                cycle_found = 1;
            }
        }
    }
    return cycle_found;
}
 
int cyclic(int src)
{
    int cycle_found;
    cycle_found  = cyclic_recursive(src, src);

    return cycle_found;
} 

void kruskal()
{

int ele=0;
int wt=edges[0].wt;
int minwt = 0;
for(int j=0;j<en;j++){
    printf("%d",j);
    bool done = false;
while(!done){
for(int i=0;i<en;i++)
{
if(edges[i].wt < wt && minwt < edges[i].wt && !used[ele])
{wt = edges[ele].wt; ele=i;}
}
used[ele]= true;
printf("%d",ele);
if(1) done =1;
else {used[ele] = false; minwt= edges[ele].wt;}
}

}}
};





int main()
{
graph g1;
g1.addedge(0,1,2,0);
g1.addedge(1,2,3,0);
g1.kruskal();
}
