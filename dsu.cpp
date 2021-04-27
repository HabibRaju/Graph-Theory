#include <bits/stdc++.h>
using namespace std;

int parent[10000007];
int findParent(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = findParent(parent[v]);
}

void makeFriend(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b)
        parent[b] = a;
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=1; i<=n; i++)parent[i]=i;

    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
       makeFriend(x,y);
    }
    for(int i=1; i<=n; i++)findParent(i);
    for(int i=1; i<=n; i++)cout<<"Parent "<<i<<" -> "<<parent[i]<<endl;
    //cout<<rep[6]<<"--";
}

/*
6 5
1 2
2 3
3 4
5 6
3 5
cycle define
*/
