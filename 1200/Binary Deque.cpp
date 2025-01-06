#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,s;
    cin>>n>>s;
    vector<ll>v1;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        v1.push_back(input);
    }
    ll cur=count(v1.begin(),v1.end(),1);
    if(cur==s){
        cout<<0<<'\n';
        return;
    }
    if(cur<s){
        cout<<-1<<'\n';
        return;
    }
    vector<pair<ll,pair<ll,ll>>>comp;
    for(int i=0;i<n;i++){
        if(v1[i]==1){
            comp.push_back({i,{-1,-1}});
        }
    }
    for(int i=0;i<comp.size();i++){
        if(i==0){
        comp[i].second.first=comp[i].first+1;
        comp[i].second.second=comp[i+1].first-comp[i].first;
        continue;
        }
        if(i==comp.size()-1){
            comp[i].second.first=comp[i].first-comp[i-1].first;
            comp[i].second.second=n-comp[i].first;
            continue;
        }
        comp[i].second.first=comp[i].first-comp[i-1].first;
        comp[i].second.second=comp[i+1].first-comp[i].first;
    }
    vector<ll>suf(comp.size()+1,0),pre(comp.size()+1,0);
    for(int i=1;i<=comp.size();i++){
        pre[i]=pre[i-1]+comp[i-1].second.first;
    }
    for(int i=comp.size()-1;i>=0;i--){
        suf[i]=suf[i+1]+comp[i].second.second;
    }
    ll req=cur-s;
    // for(int i=0;i<comp.size()+1;i++){
    //     cout<<pre[i]<<" "<<suf[i]<<'\n';
    // }
    ll ans=1e6,tp=0;
    //cout<<req<<'\n';
    for(int i=0;i<=req;i++){
        ll f=i;
        tp=0;
        tp+=pre[f];
        ll need=req;
        need-=f;
        tp+=suf[comp.size()-need];
        //cout<<tp<<" "<<f<<" "<<need<<'\n';
        ans=min(ans,tp);
    }
    cout<<ans<<'\n';
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
