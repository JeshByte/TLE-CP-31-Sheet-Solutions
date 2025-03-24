#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    string s;
    cin>>s;
    ll n=s.size();
    vector<ll>pre(n,0);
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(i!=0 && s[i]==s[i-1] && s[i]=='v'){
            cnt++;
        }
        pre[i]=cnt;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='o'){
            ll tp=pre[i]*(pre[n-1]-pre[i]);
            ans+=tp;
        }
    }
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
