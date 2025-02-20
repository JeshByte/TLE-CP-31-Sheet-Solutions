#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<pair<ll,vector<ll>>>arr;
    for(int i=0;i<n;i++){
        ll k;
        cin>>k;
        vector<ll>temp;
        ll req=-1;
        for(int j=0;j<k;j++){
            ll input;
            cin>>input;
            temp.push_back(input);
            ll tp=input+1-j;
            req=max(tp,req);
        }
        arr.push_back({req,temp});
    }
    sort(arr.begin(),arr.end());
    ll ans=-1,cnt=0;
    for(auto it:arr){
        vector<ll>v=it.second;
        for(int i=0;i<v.size();i++){
            ll tp=v[i]+1-cnt;
            ans=max(ans,tp);
            cnt++;
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
