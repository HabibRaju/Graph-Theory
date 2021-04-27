///________________BFS________________________________________
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

    bfs(1);

    for(int i=1; i<=node; i++){
        cout<<i<<" level -> "<<level[i]<<endl;
    }
}
///________________DFS________________________________________

#include <bits/stdc++.h>
using namespace std;

vector <int> graph[5000];
int visit[1000];
int level[1000];
int End[500];
int dis[500];
int tme=0;
queue <int>q;

void init(int n, int e){
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int u){
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

    init(n,e);
    dfs(1);
    for(int i=1; i<=n; i++){
        cout<<i<<"->"<<"Discover Time : "<<dis[i] <<"  "<< "End Time : " <<End[i]<<endl;
    }
    return 0;
}

///________________Kruskal________________________________________

#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<int,ii>

int node,edge,total=0;
int parent[3000007];
vector <iii> graph;

void init(){
    for(int i=0; i<edge; i++){
        int u,v,w;
        cin>>u>>v>>w;
        total+=w;
        graph.push_back(iii(w,ii(u,v)));
    }
}

int findParent(int r){
    if(parent[r]==r)return r;
    return findParent(parent[r]);
}

int kruskal(){
    int n=node,cost=0,edgeCnt=0;
    int len=graph.size();
    sort (graph.begin(),graph.end());

    for(int i=0; i<node; i++)parent[i]=i;

    for(int i=0; i<len; i++){
        int u = findParent(graph[i].second.first);
        int v = findParent(graph[i].second.second);

        if(v!=u){

            parent[v] = parent[u];
            cost+=graph[i].first;
            edgeCnt++;

        }
        if(edgeCnt==n-1)break;
    }
    return cost;
}

int main(){

    cin>>node>>edge;
    init();

    cout<<kruskal();

}


/*
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11


ans -> 39
final_ans = 90-39 = 51;
*/

///________________Dijestra________________________________________

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
        graph[v].pb(ii(u,w));
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
///________________topo_sort________________________________________

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

///_____________________Bellman__________________________________________
#include <bits/stdc++.h>
#define ii pair <long long int,long long int>
#define iii pair <long long int,ii>
#define inf 1000000000000000000
using namespace std;

vector <iii> graph;
//queue <int> q;

long long int dis[10000007];
long long int node,edge, root;

void BellmanFord(){

    for(long long int i=0; i<=node; i++) dis[i]=inf;
    dis[root]=0;

    long long int len=graph.size();
    for(long long int i=1; i<node; i++){
        for(long long int j=0; j<len; j++){
            iii a=graph[j];

            long long int u=a.second.first;
            long long int v=a.second.second;
            long long int w=a.first;

            //cout<<u<<" "<<v<<" "<<w<<endl;

            if(dis[u]+w < dis[v]){
                dis[v]=dis[u]+w;
            }
        }

        //for(int i=0; i<node; i++)cout<<dis[i]<<endl;
        //cout<<endl;
    }



    bool flag=1;
    for(long long int j=0; j<len; j++){
        iii a=graph[j];

        long long int u=a.second.first;
        long long int v=a.second.second;
        long long int w=a.first;

        if(dis[u]+w < dis[v] && dis[v]<=99999){
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }
    for(long long int i=0; i<node; i++){
        if(dis[i]>=100000)cout<<"INF"<<endl;
        else cout<<dis[i]<<endl;
    }

}


 int main(){
    cin>>node>>edge>>root;

    for(long long int i=1; i<=edge; i++){
        long long int u,v,w;
        cin>>u>>v>>w;

        graph.push_back(iii(w,ii(u,v)));

    }

    BellmanFord();
}


//4 5 0
//0 1 2
//0 2 3
//1 2 -5
//1 3 1
//2 3 2
//0
//2
//-3
//-1

//4 6 0
//0 1 2
//0 2 3
//1 2 -5
//1 3 1
//2 3 2
//3 1 0
//Negative Cycle

}



