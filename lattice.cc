# include <iostream>
using namespace std;
struct edge
{
    int src;
    int dest;
    bool visited;
};


struct queue
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
        cout << "Can not empty";
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
    void print()
    {
        for(int i=front; i< rear; i++)
        {
            cout << arr[i] << ", ";
        }
    }
};

struct graph
{
    queue grph[1000];
    edge edges[1000];
    bool visited[1000];
    int no_of_edges;
    int vtx;
    graph()
    {
        no_of_edges=0;
        vtx =0;
    }
    void addedge(int src, int dest)
    {
        grph[src].push(dest);
        edge new_edge;
        new_edge.src = src;
        new_edge.dest = dest;
        edges[no_of_edges] = new_edge;
        no_of_edges++;
    }
    void print_graph()
    {
        for(int i=0;i<1000;i++)
        {
            if(grph[i].len()>0)
            {   cout << i << "--> ";
                grph[i].print();
                cout << "\n";
            }
        }
    }
    bool traverse(int picked,int &count )
    {   
    count++;
        edges[picked].visited = 1;
        int src[]={1,-1,0,0};
        int dest[]={0,0,1,-1};
        for(int i=0;i<4;i++)
        {
              edge new_edge;
              new_edge.src = edges[picked].src + src[i];
              new_edge.dest = edges[picked].dest + dest[i];
              new_edge.visited = 0;
              for(int i=0;i<no_of_edges;i++)
              {
                  if(edges[i].src == new_edge.src && edges[i].dest == new_edge.dest && edges[i].visited == new_edge.visited )
                  {
                      traverse(i, count);
                  }
              }    
        }
    }

  
    int no_of_clusters()
    {   int ncluster = 0;
        if(no_of_edges==0) return 0;
        for(int i=0;i<no_of_edges;i++)
        {   if(!edges[i].visited)
            {int picked = i;
            ncluster ++ ;
            int count =0;
            int ans[10]={0};
            traverse(picked,count);
            cout <<"cluster "<< ncluster << endl;
            cout << "no of sites " << count << endl << endl;
            }
        }
        return ncluster;}
};

int main()
{
    graph g;
    g.addedge(1,1);
    g.addedge(1,6);
    g.addedge(2,1);
    g.addedge(2,2);
    g.addedge(2,6);
    g.addedge(3,6);
    g.addedge(3,4);
    g.addedge(4,1);
    g.addedge(4,2);
    g.addedge(5,2);
    g.addedge(5,3);
    g.addedge(5,4);
    g.addedge(6,6);
    g.addedge(6,3);
    g.print_graph();
    cout << endl << "No of clusters";
    cout << g.no_of_clusters() << endl;
}