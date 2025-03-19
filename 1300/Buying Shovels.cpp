#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,k;
    cin>>n>>k;
    set<ll>s;
    for(int i=1;i<=sqrtl(n);i++){
        if(n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    vector<ll>factors;
    for(auto it:s){
        factors.push_back(it);
    }
    reverse(factors.begin(),factors.end());
    ll ans;
    for(int i=0;i<factors.size();i++){
        if(factors[i]>=1 && factors[i]<=k){
            ans=n/factors[i];
            break;
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
