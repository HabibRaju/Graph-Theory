#include <bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <int,ii>
#define inf 10000000
using namespace std;

vector <iii> graph;
//queue <int> q;

int dis[507];
int node,edge, root;

void BellmanFord(){

    for(int i=0; i<=node; i++) dis[i]=inf;
    dis[root]=0;

    int len=graph.size();
    for(int i=1; i<node; i++){
        for(int j=0; j<len; j++){
            iii a=graph[j];

            int u=a.second.first;
            int v=a.second.second;
            int w=a.first;

            //cout<<u<<" "<<v<<" "<<w<<endl;

            if(dis[u]+w < dis[v]){
                dis[v]=dis[u]+w;
            }
        }

//        for(int i=0; i<node; i++){
//            cout<<i<<" "<<dis[i]<<endl;
//        }
//        cout<<endl;
    }


    bool flag=1;
    for(int j=0; j<len; j++){
        iii a=graph[j];

        int u=a.second.first;
        int v=a.second.second;
        int w=a.first;

        if(dis[u]+w < dis[v]){
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }
    for(int i=0; i<node; i++){
        if(dis[i]>=inf)cout<<"INF"<<endl;
        else cout<<dis[i]<<endl;
    }

}


int main(){
    cin>>node>>edge>>root;

    for(int i=1; i<=edge; i++){
        int u,v,w;
        cin>>u>>v>>w;

        graph.push_back(iii(w,ii(u,v)));

    }

    BellmanFord();


}

/*
5 6
1 2 1
1 3 3
2 3 2
3 4 1
3 5 3
4 5 1


4 6 0
0 1 2
0 2 3
1 2 -5
1 3 1
2 3 2
3 1 0

4 5 0
0 1 2
0 2 3
1 2 -5
1 3 1
2 3 2
*/
