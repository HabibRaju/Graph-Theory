#include <bits/stdc++.h>
using namespace std;

vector <int> graph[100007];
bool vis[100007];
int SubSiz[100007];

int dfs(int node){
    vis[node] = true;
    int current = 1;

    for(int child : graph[node]){

        if(vis[child] == false){
            current+=dfs(child);
        }
    }
    ///cout<<node<<" "<<current<<endl;
    SubSiz[node] = current;
    return current;
}


int main(){
    int node,edge;cin>>node;
    edge = node - 1;
    for(int i=0; i<edge; i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    for(int i=1; i<=node; i++)cout<<i<<" th Size is = "<<SubSiz[i]<<endl;

}

