#include <bits/stdc++.h>
using namespace std;


vector <int> graph[1000],Tree[1000];
bool vis[1000];
void dfs(int node){
    vis[node]=true;
    for(int i=0; i<graph[node].size(); i++){
        if(vis[graph[node][i]]==0){
            cout<<node<<" "<<graph[node][i]<<endl;
            Tree[node].push_back(graph[node][i]);
            Tree[graph[node][i]].push_back(node);
            dfs(graph[node][i]);
        }
    }

}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);

}
