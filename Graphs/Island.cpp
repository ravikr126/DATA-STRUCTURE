/*

Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 

*/
#include <bits/stdc++.h>
using namespace std;

void DFS(bool** graph, int v,bool* visited,int currentVertex){
    visited[currentVertex]=true;
    
    for(int i=0;i<v;++i)
    {
        if(graph[currentVertex][i] && !visited[i])
            DFS(graph,v,visited,i);
    }
    
}

int getislandgroups(bool** graph ,int v)
{
    bool* visited = new bool[v]();
    int groupcount =0;

      for(int i=0;i<v;++i)
    {
        if(!visited[i])
        {
            DFS(graph,v,visited,i);
            ++groupcount;
        }
    }
    return groupcount;
}

int main()
{
    int v,e;
    cin>>v>>e;
    bool** graph = new bool*[v];

    for(int i=0;i<v;i++)
    {
        graph[i]=new bool[v]();

    }

    for(int i=0,a,b;i<e;++i)
    {
        cin>>a>>b;
        graph[a][b]=true;
        graph[b][a]=true;
    }

    cout<<getislandgroups(graph,v);
    for(int i=0;i<v;++i)
    {
        delete[] graph[i];
    }

    delete[] graph;
}
