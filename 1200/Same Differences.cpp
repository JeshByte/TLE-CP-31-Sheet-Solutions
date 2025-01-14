#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>nums;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        nums.push_back(input);
    }
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        mp[nums[i]-(i+1)]++;
    }
    ll ans=0;
    for(auto it:mp){
        ll temp=it.second;
        ans+=(temp*(temp-1))/2;
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
