#include <bits/stdc++.h>
#define ii pair <int,int>
#define ff first
#define ss second
#define pb push_back
#define pf printf
#define inf 10000000
using namespace std;

vector <ii> graph[502];
int dis[502];

void diajkstra(int source){
    dis[source]=0;
    queue <int> q;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int siz = graph[u].size();
        for(int i=0; i<siz; i++){
            int v = graph[u][i].ff;
            int w = graph[u][i].ss;
            if(dis[u]+w < dis[v]){
                dis[v] = dis[u]+w;
                q.push(v);
            }
        }
    }
}

int main(){

    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].pb(ii(v,w));
        //graph[v].pb(ii(u,w));
    }
    for(int i=0; i<502; i++) dis[i]=inf;
    cout << "Enter source: ";
    int source; cin >> source;
    diajkstra(source);
    int d;
    while(1){
        cout << "Enter destination: ";
        cin>>d;
        cout << "distance: " << dis[d] << endl;
    }

    return 0;
}
