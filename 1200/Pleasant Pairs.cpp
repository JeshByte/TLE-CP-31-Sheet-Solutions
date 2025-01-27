#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>a;
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        a.push_back(input);
        mp[input]=i+1;
    }
    ll ans=0;
    for(int i=1;i<=2*n;i++){
      if(mp[i]>0){
        for(int j=i;j<=2*n;j+=i){
          if(mp[j/i]>0 && (mp[i]+mp[j/i]==j) && mp[i]!=mp[j/i]){
            ans++;
          }
        }
      }
    }
    cout<<ans/2<<'\n';
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
