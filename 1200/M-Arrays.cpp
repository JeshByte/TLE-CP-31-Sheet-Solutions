#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,m;
    cin>>n>>m;
    vector<ll>arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        arr[i]=arr[i]%m;
        mp[arr[i]]++;
    }
    ll ans=0;
    for(auto it:mp){
        if(it.first==0){
            ans++;
            continue;
        }
        if(it.second>0){
        ll req=m-it.first;
        if(mp.find(req)!=mp.end()){
            if(mp[req]>0){
                if(abs(it.second-mp[req])<=1){
                    ans++;
                    mp[it.first]=0;
                    mp[req]=0;
                }
                else{
                    ans+=abs(it.second-mp[req]);
                    mp[it.first]=0;
                    mp[req]=0;
                }
            }
        }
        else{
            ans+=it.second;
        }
        }
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
