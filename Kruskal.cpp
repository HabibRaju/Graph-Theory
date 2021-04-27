#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<int,ii>

int node,edge,total=0;
int parent[3000007];
vector <iii> graph;

void init(){
    for(int i=0; i<edge; i++){
        int u,v,w;
        cin>>u>>v>>w;
        total+=w;
        graph.push_back(iii(w,ii(u,v)));
    }
}

int findParent(int r){
    if(parent[r]==r)return r;
    ///cout<<"find parent  "<<findParent(parent[r])<<endl;
    return findParent(parent[r]);
}

int kruskal(){
    int n=node,cost=0,edgeCnt=0;
    int len=graph.size();
    sort (graph.begin(),graph.end());

    for(int i=0; i<node; i++)parent[i]=i;

    for(int i=0; i<len; i++){
        int u = findParent(graph[i].second.first);
        int v = findParent(graph[i].second.second);

        if(v!=u){
            parent[v] = parent[u];
            cost+=graph[i].first;
            edgeCnt++;
        }
        if(edgeCnt==n-1)break;
    }
    return cost;
}

int main(){

    cin>>node>>edge;
    init();

    cout<<kruskal();

}


/*
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11


ans -> 39
final_ans = 90-39 = 51;
*/
