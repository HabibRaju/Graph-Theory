#include <bits/stdc++.h>
using namespace std;
vector <int> graph[1000];
int visit[1000];
int level[1000];
queue <int> lst;
void bfs(int s){
    visit[s]=1;
    level[s]=0;
    lst.push(s);
    while(!lst.empty()){
        int u=lst.front();
        lst.pop();
        for(int i=0; i<graph[u].size(); i++){
            if(visit[graph[u][i]]!=1){
                visit[graph[u][i]]=1;
                level[graph[u][i]]=level[u]+1;
                lst.push(graph[u][i]);
            }
        }
    }
}

int main(){
    int node,edge;
    cin>>node>>edge;
    for(int i=0; i<edge; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(0);
    for(int i=0; i<=node; i++){
        cout<<i<<" level -> "<<level[i]<<endl;
    }
}
