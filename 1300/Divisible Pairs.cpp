#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll>v1;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        v1.push_back(input);
    }
    map<pair<ll,ll>,ll>mp;
    for(int i=0;i<n;i++){
        mp[{v1[i]%x,v1[i]%y}]++;
    }
    // for(auto it:mp){
    //     cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<'\n';
    // }
    // cout<<'\n';
    ll ans=0;
    for(int i=0;i<n;i++){
        ll req_x=x-(v1[i]%x);
        if(req_x==x){
            req_x=0;
        }
        ll req_y=v1[i]%y;
        //cout<<req_x<<" "<<req_y<<'\n';
        if(mp.find({req_x,req_y})!=mp.end() && mp[{req_x,req_y}]){
            //cout<<"hi"<<'\n';
            if(req_x==(v1[i]%x)){
                ans+=(mp[{req_x,req_y}]-1);
            }
            else{
            ans+=mp[{req_x,req_y}];
            }
            mp[{v1[i]%x,v1[i]%y}]--;
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
