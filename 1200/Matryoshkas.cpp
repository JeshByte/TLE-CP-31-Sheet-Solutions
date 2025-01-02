#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>v1;
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        v1.push_back(input);
        mp[input]++;
    }
    sort(v1.begin(),v1.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        if(mp[v1[i]]){
            mp[v1[i]]--;
            ll j=1;
            while(mp.find(v1[i]+j)!=mp.end() && mp[v1[i]+j]){
                mp[v1[i]+j]--;
                j++;
            }
            ans++;
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
