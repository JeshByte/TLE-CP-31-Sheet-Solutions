#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,q;
    cin>>n>>q;
    vector<ll>v1,v2;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        v1.push_back(input);
    }
    set<ll>s;
    for(int i=0;i<q;i++){
        ll input;
        cin>>input;
        v2.push_back(input);
        s.insert(input);
    }
    vector<ll>tp;
    for(auto it:s){
        tp.push_back(it);
    }
    map<ll,ll>mp;
    ll total=0;
    ll i=0,j=0;
    while(i<n && j<tp.size()){
        if(v1[i]<=tp[j]){
            total+=v1[i];
            i++;
        }
        else{
            mp[tp[j]]=total;
            j++;
        }
    }
    while(j<tp.size()){
        mp[tp[j]]=total;
        j++;
    }
    for(int i=0;i<q;i++){
        cout<<mp[v2[i]]<<" ";
    }
    cout<<'\n';
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
