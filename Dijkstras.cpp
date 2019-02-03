#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

/*
Example graph to check it out:

8 11
0 7 5
7 4 3
7 1 20
1 4 8
4 2 6
2 1 1
2 3 18
3 1 5
1 5 10
5 3 9
5 6 2

*/
struct Edge
{
    int index;
    int shor;

    bool operator <(Edge other)const
    {
        return shor>other.shor;
    }

};

const int Max_N=100000;
int n,m;

int shortest_path [Max_N];
vector < pair<int,int> > graph [Max_N];
priority_queue <Edge> queuem;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int counter=0; counter<m; counter++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        pair<int,int> d;
        d.first=b;
        d.second=c;
        graph [a].push_back(d);
    }
    shortest_path [0]=0;
    for(int counter=1; counter<n; counter++)
    {
        shortest_path [counter]=-1;
    }
    Edge ed;
    ed.index=0;
    ed.shor=0;
    queuem.push(ed);
    while(!queuem.empty())
    {
        Edge current_edge=queuem.top();
        queuem.pop();
        for(int counter=0; counter<graph [current_edge.index].size(); counter++)
        {
            pair <int,int> current_rebro;
            current_rebro = graph [current_edge.index] [counter];
            if(shortest_path [current_rebro.first]==-1)
            {
                shortest_path [current_rebro.first]=current_edge.shor+current_rebro.second;
                Edge adding_edge;
                adding_edge.index=current_rebro.first;
                adding_edge.shor=current_edge.shor+current_rebro.second;
                queuem.push(adding_edge);
            }
            else
            {
                if(current_edge.shor+current_rebro.second<shortest_path [current_rebro.first])
                {
                    shortest_path [current_rebro.first]=current_edge.shor+current_rebro.second;
                    Edge adding_edge;
                    adding_edge.index=current_rebro.first;
                    adding_edge.shor=current_edge.shor+current_rebro.second;
                    queuem.push(adding_edge);
                }

            }
        }
    }

    for(int counter=0; counter<n; counter++)
    {
        cout<<shortest_path [counter]<<endl;
    }


    return 0;
}
