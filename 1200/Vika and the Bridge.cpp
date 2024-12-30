#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,k;
    cin>>n>>k;
    vector<ll>v1;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        v1.push_back(input);
    }
    map<ll,ll>prev,dist,co,second_max;
    for(int i=0;i<n;i++){
        prev[v1[i]]=-1;
        dist[v1[i]]=-1;
        second_max[v1[i]]=-1;
        co[v1[i]]=1;
    }
    for(int i=0;i<n;i++){
        ll len=i-prev[v1[i]]-1;
        if(len>dist[v1[i]]){
            second_max[v1[i]]=max(second_max[v1[i]],dist[v1[i]]);
            dist[v1[i]]=len;
            co[v1[i]]=1;
        }
        else if(len==dist[v1[i]]){
            co[v1[i]]++;
        }
        else{
            second_max[v1[i]]=max(second_max[v1[i]],len);
        }
        prev[v1[i]]=i;
    }
    ll mi=1e6;
    for(auto it:dist){
        ll len=n-prev[it.first]-1;
        if(len>dist[it.first]){
            second_max[it.first]=max(second_max[it.first],dist[it.first]);
            dist[it.first]=len;
            co[it.first]=1;
        }
        else if(len==dist[it.first]){
            co[it.first]++;
        }
        else{
            second_max[it.first]=max(second_max[it.first],len);
        }
    }
    // for(auto it:dist){
    //     cout<<it.first<<" "<<it.second<<'\n';
    // }
    // for(auto it:co){
    //     cout<<it.first<<" "<<it.second<<'\n';
    // }
    // for(auto it:second_max){
    //     cout<<it.first<<" "<<it.second<<'\n';
    // }
    for(auto it:dist){
        if(co[it.first]==1){
            mi=min(mi,max(dist[it.first]/2,second_max[it.first]));
        }
        else{
            mi=min(mi,dist[it.first]);
        }
    }
    cout<<mi<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
}
