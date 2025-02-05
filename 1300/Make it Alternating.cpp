#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll con=998244353;
vector<ll>dp(1e6,-1);
ll fact(ll n){
    if(n<=1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=(n*fact(n-1))%con;
}
void solve(ll t){
    string s;
    cin>>s;
    ll n=s.size();
    ll cost=0,ways=1;
    ll i=0;
    while(i<n){
        char temp=s[i];
        ll cnt=0;
        while(s[i]==temp){
            i++;
            cnt++;
        }
        if(cnt>1){
            cost+=(cnt-1);
            ways=(ways*cnt)%con;
            //cout<<f<<" "<<ways<<'\n';
        }

    }
    ways=(ways*fact(cost))%con;
    cout<<cost<<" "<<ways<<'\n';
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
