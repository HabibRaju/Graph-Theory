#include <bits/stdc++.h>
using namespace std;
vector <int> graph[10007];
bool vis[10007];
int color[10007];
bool dfs(int node, int c){
    vis[node] = true;
    color[node] = c;

    for(int child : graph[node]){
        if(vis[child]==false){
            if(dfs(child,c^1)==false)return false;
        }

        else if(color[node] == color[child])return false;
    }
    return true;
}

int main(){
    int node,edge;
    cin>>node>>edge;

    for(int i=0; i<edge; i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool flag = dfs(1,0);
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
