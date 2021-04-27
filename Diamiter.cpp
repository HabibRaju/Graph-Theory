#include <bits/stdc++.h>
using namespace std;

vector <int> graph[100007];
bool vis[100007];int lev[100007];

void bfs(int node){
    vis[node] = true;
    lev[node] = 0;
    queue <int> q;
    q.push(node);
    while(!q.empty()){
        node = q.front();
        q.pop();
        for(int child : graph[node]){
            if(vis[child] == false){
                vis[child] = true;
                lev[child] = lev[node] +1;
                q.push(child);
            }
        }
    }

}

int main(){
    int t;cin>>t;
    while(t--){
        int node,edge;cin>>node>>edge;
        for(int i=0; i<edge; i++){
            int u,v;cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bfs(1);
        cout<<lev[node]<<endl;
        memset(vis,0,sizeof(vis));
        memset(lev,0,sizeof(lev));
    }

}


