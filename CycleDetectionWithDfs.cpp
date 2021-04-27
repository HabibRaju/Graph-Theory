#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
bool vis[1000];
bool dfs(int node, int parent){
    vis[node] = true;
    for(int i=0; i<graph[node].size(); i++){
        if(vis[graph[node][i]]==0){
            if(dfs(graph[node][i],node)==true){
                return true;
            }
        }
        else if(parent!=graph[node][i]){
            return true;
        }
    }
    return false;
}
int main(){
    int n;cin>>n;
    for(int i=0; i<n; i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool flag = dfs(1,-1);

    if(flag)cout<<"Cycle"<<endl;
    else cout<<"Not Cycle"<<endl;
}
