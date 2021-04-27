#include <bits/stdc++.h>
using namespace std;
vector <int> graph[10004];
int low[10004],in[10004],tme=0;
bool vis[10004];
set <int> s;

void dfs(int node, int par){

    vis[node] = true;
    in[node] = low[node] = ++tme;
    int children=0;

    for(int child : graph[node]){
        if(child == par)continue;
        else if(vis[child]){
            low[node] = min(low[node],in[child]);
        }
        else {
            dfs(child,node);
            low[node] = min(low[node],low[child]);
            if(low[child]>=in[node] && par!=-1){
                ///cout<<child<<" "<<low[child]<<endl<<node<<" "<<in[node]<<endl<<endl;
                s.insert(node);
            }
            ++children;
        }
    }
    if(par==-1 && children>1){
        s.insert(node);
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
    cout<<s.size()<<endl;

    for(auto it : s){
        cout<<it<<endl;
    }
}
