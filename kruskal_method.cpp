//@kakovic
// Kruskal method for minimum spanning tree
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef long long int lli;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> pbds;
//defines
#define ll long long
#define pb push_back

vector<vector<int>> l;

void addEdge(int w,int u,int v){
    l.push_back({w,u,v});
}
// path compression optimization
int find_set(int i,vector<int> &parent){
    if(parent[i]==-1){
        return i;
    }
    parent[i]=find_set(parent[i],parent);
    return parent[i];
}
// union rank optimization
void union_set(int s1,int s2,vector<int> &parent,vector<int> &rank){
    /*int s1=find_set(i,parent);
    int s2=find_set(j,parent);*/
    if(s1!=s2){
        if(rank[s1]<rank[s2]){
            parent[s1]=s2;
            rank[s2]+=rank[s1];
        }
        else{
            parent[s2]=s1;
            rank[s1]+=rank[s2];
        }
    }
}

int kruskal(vector<int> &parent){
    sort(l.begin(),l.end()); // step I
    vector<int> rank(4);
    for(int i=0;i<4;i++)
        rank[i]=1;
    int ans=0;
    for(auto edge:l){
        int wt=edge[0];
        int x=edge[1];
        int y=edge[2];
        int s1=find_set(x,parent);
        int s2=find_set(y,parent);
        if(s1!=s2){
            union_set(s1,s2,parent,rank);
            ans+=wt;
        }
    }
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    addEdge(1,0,1);
    addEdge(3,1,3);
    addEdge(3,2,3);
    addEdge(2,2,0);
    addEdge(2,0,3);
    addEdge(2,1,2);
    vector<int> parent(4,-1);
    cout<<kruskal(parent);
}