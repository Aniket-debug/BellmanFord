#include<bits/stdc++.h>
using namespace std;
vector<int> BellmanFord(vector<pair<int,pair<int,int>>> e,int sr,int n,int m){
    vector<int> d(n);
    for (int i=0;i<n;i++)d[i]=1e9;
    d[sr]=0;
    for (int i=1;i<n;i++)
        for (int j=0;j<m;j++)
            d[e[j].second.first]=min(d[e[j].first]+e[j].second.second,d[e[j].second.first]);
    for (int i=1;i<n;i++)
        for (int j=0;j<m;j++)
            if (d[e[j].second.first]>d[e[j].first]+e[j].second.second)
                return {};
    return d;
}
int main(){
    int n,m,sr;cin>>n>>m>>sr;
    vector<pair<int,pair<int,int>>>edg ;
    for (int i=0;i<m;i++){
        int v1,v2,w;cin>>v1>>v2>>w;
        edg.push_back({v1,{v2,w}});
    }
    vector<int> d=BellmanFord(edg,sr,n,m);
    if (d.size()==0)cout<<"negetive cycle";
    for (int i:d)cout<<i<<' ';
}
