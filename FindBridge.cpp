#include <bits/stdc++.h>
using namespace std;
vector<int>graph[1000];
int in[1000],low[1000],vis[1000];
int tme=0;
void dfs(int node, int par){
    vis[node] = 1;
    in[node] = low[node] = tme;
    ++tme;

    for(int child : graph[node]){
        if(child==par)continue;
        if(vis[child]==1){
            low[node] = min(low[node],in[child]);
        }
        else {
            dfs(child,node);
            if(low[child]>in[par])cout<<node<<" - "<<child<<" is a Bridge"<<endl;
            low[node] = min(low[node],low[child]);
        }
    }


}


int main(){
    int n,e;cin>>n>>e;
    for(int i=0; i<e; i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,-1);

}
