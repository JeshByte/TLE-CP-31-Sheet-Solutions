#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,w;
    cin>>n>>w;
    multiset<ll>arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.insert(input);
    }
    ll ans=1;
    ll avail=w;
    while (!arr.empty()) {
        auto it = arr.upper_bound(avail);  
        if (it == arr.begin()) {
            ans++;
            avail = w;
        } else {
            --it;
            avail -= *it;
            arr.erase(it);
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
