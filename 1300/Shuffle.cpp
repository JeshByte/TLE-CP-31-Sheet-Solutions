#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,x,m;
    cin>>n>>x>>m;
    vector<pair<ll,ll>>op;
    for(int i=0;i<m;i++){
        ll l,r;
        cin>>l>>r;
        op.push_back({l,r});
    }
    ll left=x,right=x;
    for(int i=0;i<m;i++){
        ll l=op[i].first;
        ll r=op[i].second;
        if(l<=left && left<=r){
            left=min(left,l);
        }
        if(l<=right && right<=r){
            right=max(right,r);
        }
    }
    //cout<<left<<" "<<right<<'\n';
    ll ans=(right-left)+1;
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
