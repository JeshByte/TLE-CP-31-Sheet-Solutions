#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll bin(vector<pair<ll,ll>>&req,ll start,ll end,ll comp){
    if(start>=req.size()){
        return -1;
    }
    ll high=end;
    ll low=start;
    ll ans=-1;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(comp<req[mid].first){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }   
    vector<pair<ll,ll>>req;
    for(int i=0;i<n;i++){
        if(arr[i]<i+1){
            req.push_back({arr[i],i+1});
        }
    }
    sort(req.begin(),req.end());
    // for(auto it:req){
    //     cout<<it.first<<" "<<it.second<<'\n';
    // }
    // cout<<'\n';
    ll ans=0;
    for(int i=0;i<req.size();i++){
        ll ind=bin(req,i+1,req.size()-1,req[i].second);
        if(ind==-1){
            //cout<<i<<" "<<ind<<'\n';
            continue;
        }
        //cout<<i<<" "<<ind<<'\n';
        ans+=(req.size()-ind);
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
