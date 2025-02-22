#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    ll dots,lines;
    if(n&1){
        dots=1;
        lines=0;
        for(int i=1;i<=n;i+=2){
            dots++;
            lines++;
        }
        lines*=2;
    }
    else{
        dots=1;
        lines=1;
        for(int i=2;i<=n;i+=2){
            dots++;
            lines++;
        }
    }
    ll ans=dots*lines;
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
}
