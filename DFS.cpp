#include <bits/stdc++.h>
using namespace std;

vector <int> graph[5000];
int visit[1000];
int level[1000];
int End[500];
int dis[500];
int tme=0;
queue <int>q;

void init(int e){
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        ///graph[v].push_back(u);
    }
}

void dfs(int u){
    cout<<u<<endl;
    visit[u]=1;
    dis[u]=++tme;
    int len=graph[u].size();
    for(int i=0; i<len; i++){
        int v=graph[u][i];
        if(visit[v]==0){
            dfs(v);
        }
    }
    End[u]=++tme;
}

int main(){
    int e,n;
    cin>>n>>e;
    init(e);
    for(int i=1; i<=n; i++){
        if(visit[i]==0)dfs(i);
    }
    for(int i=1; i<=n; i++){
        cout<<i<<"->"<<"Discover Time : "<<dis[i] <<"  "<< "End Time : " <<End[i]<<endl;
    }
    return 0;
}
