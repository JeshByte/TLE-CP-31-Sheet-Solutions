#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>child[n+1];
    for(int i=2;i<=n;i++){
        ll input;
        cin>>input;
        child[input].push_back(i);
    }
    string s;
    cin>>s;
    ll res=0;
    function<ll(ll)>dp=[&](ll v){
        ll bal;
        if(s[v-1]=='B'){
            bal=1;
        }
        else{
            bal=(-1);
        }
        if(child[v].empty()){
            return bal;
        }
        for(auto it:child[v]){
            bal+=dp(it);
        }
        if(bal==0){
            res++;
        }
        return bal;
    };
    dp(1);
    cout<<res<<'\n';
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
