#include<bits/stdc++.h>
using namespace std;

vector<int>graph[5000];
map<string,int>mp;
map<int,string>out;
int n,e,s,d,cnt=0,inDeg[5000];
bool del[5000];
queue<string>ans;

void init(){
    cin>>n>>e;
    for(int i=0; i<e; i++){
        string u,v;
        cin>>u>>v;
        if(mp[u]==0){
            s=mp[u]=++cnt;
            out[cnt]=u;
        }
        else s=mp[u];

        if(mp[v]==0){
            d=mp[v]=++cnt;
            out[cnt]=v;
        }
        else d=mp[v];
        graph[s].push_back(d);
        inDeg[d]++;
    }
}

void topoSort(){
    int u;
    queue<int>q;
    for(int i=1; i<=n; i++){
        if(inDeg[i]==0)q.push(i);
    }
    while(!q.empty()){
        u=q.front();
        q.pop();//cout<<out[u]<<" ";
        ans.push(out[u]);
        for(int i=0; i<graph[u].size(); i++){
            int v=graph[u][i];
            if(!del[v]){
                inDeg[v]--;
                q.push(v);
                del[v]=1;
                //if(inDeg[v]==0)q.push(v);
            }
            //if(inDeg[graph[u][i]]==0)q.push(graph[u][i]);
        }
    }


}


int main(){
    init();
    topoSort();
    return 0;
}
