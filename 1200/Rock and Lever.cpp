#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll findBits(ll n){
    int cnt=0;
    while(n>0){
        n=n>>1;
        cnt++;
    }
    return cnt;
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>arr;
    vector<ll>cnt(32,0);
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    for(int i=0;i<n;i++){
        int tp=findBits(arr[i]);
        cnt[tp]++;
    }
    ll ans=0;
    for(int i=0;i<32;i++){
        ans+=(cnt[i]*(cnt[i]-1))/2;
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
