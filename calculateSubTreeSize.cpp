#include <bits/stdc++.h>
using namespace std;

vector <int> graph[100];
int n,e;
int vis[100],sub[100];

int dfs(int node){
    vis[node] = true;
    int current=1;
    for(int i=0; i<graph[node].size(); i++){
        if(vis[graph[node][i]]==false){
            current+= dfs(graph[node][i]);
        }
    }
    sub[node] = current;
    return current;
}

int main(){
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
    }
    dfs(1);
    for(int i=1; i<=n; i++)cout<<i<<" "<<sub[i]<<endl;

}
