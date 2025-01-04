#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>x,y;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        x.push_back(input);
    }
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        y.push_back(input);
    }
    vector<pair<ll,ll>>zero,cost,budget;
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        mp[i]=1;
        if(x[i]>=y[i]){
            cost.push_back({x[i]-y[i],i});
            if(x[i]==y[i]){
            zero.push_back({x[i]-y[i],i});
            }
        }
        else{
            budget.push_back({y[i]-x[i],i});
        }
    }
    sort(cost.rbegin(),cost.rend());
    sort(budget.rbegin(),budget.rend());
    ll i=0,j=0,ans=0;
    while(i<budget.size() && j<cost.size()){
        if(budget[i].first>=cost[j].first){
            ans++;
            mp[budget[i].second]=0;
            mp[cost[j].second]=0;
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    ll co=0;
    for(int i=0;i<zero.size();i++){
        if(mp[zero[i].second]){
            co++;
        }
    }
    for(int i=0;i<budget.size();i++){
        if(mp[budget[i].second]){
            co++;
        }
    }
    //cout<<ans<<" "<<co<<'\n';
    ans+=co/2;
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
