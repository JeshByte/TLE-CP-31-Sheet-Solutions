#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
vector<pair<ll, ll>> findSegments(vector<ll> &arr,ll m) {
    vector<pair<ll,ll>>seg;
    ll n=arr.size();
    ll l=0;
    for(int i=0;i<n-1;i++){
      if(arr[i]+1==arr[i+1]){
        continue;
      }
      else{
        seg.push_back({arr[l],arr[i]});
        l=i+1;
      }
    }
    seg.push_back({arr[l],arr[n-1]});
    if(seg.size()>1 && seg[0].first==1 && seg[seg.size()-1].second==m){
      seg.insert(seg.begin(),{seg[seg.size()-1].first,seg[0].second});
      seg.erase(seg.begin()+1);
      seg.erase(seg.begin()+seg.size()-1);
    }
    return seg;
}
void solve(ll t){
    ll n,m;
    cin>>n>>m;
    vector<ll>v1;
    for(int i=0;i<m;i++){
        ll input;
        cin>>input;
        v1.push_back(input);
    }
    sort(v1.begin(),v1.end());
    vector<pair<ll,ll>>seg;
    seg=findSegments(v1,n);
    // for(int i=0;i<seg.size();i++){
    //   cout<<seg[i].first<<" "<<seg[i].second<<'\n';
    // }
    // cout<<'\n';
    vector<pair<ll,pair<ll,ll>>>seg2;
    for(int i=0;i<seg.size()-1;i++){
      ll l=seg[i].second+1;
      ll r=seg[i+1].first-1;
      seg2.push_back({r-l+1,{l,r}});
    }
    ll l=seg[seg.size()-1].second+1;
    ll r=seg[0].first-1;
    if(r<l){
      r+=n;
    }
    seg2.push_back({r-l+1,{l,r}});
    sort(seg2.rbegin(),seg2.rend());
    // for(int i=0;i<seg2.size();i++){
    //   cout<<seg2[i].first<<" "<<seg2[i].second.first<<" "<<seg2[i].second.second<<'\n';
    // }
    ll turns=0;
    ll saved=0;
    for(int i=0;i<seg2.size();i++){
      ll safe=seg2[i].first-turns*2;
      if(safe<=0){
        continue;
      }
      else{
        if(safe<=2){
          saved++;
          turns++;
        }
        else{
          turns+=2;
          saved+=(safe-1);
        }
      }
    }
    cout<<n-saved<<'\n';
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
