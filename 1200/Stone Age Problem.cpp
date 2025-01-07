#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,q;
    cin>>n>>q;
    vector<ll>a;
    ll total=0;
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        a.push_back(input);
        total+=input;
        mp[i+1]=input;
    }
    //cout<<total<<'\n';
    vector<ll>ans;
    for(int i=0;i<q;i++){
        ll type;
        cin>>type;
        if(type==1){
            ll ind,value;
            cin>>ind>>value;
            if(mp.find(-1)!=mp.end()){
                if(mp.find(ind)!=mp.end()){
                total-=mp[ind];
                total+=value;
                mp[ind]=value;
                ans.push_back(total);
                }
                else{
                total-=mp[-1];
                total+=value;
                mp[ind]=value;
                ans.push_back(total); 
                }
                continue;
            }
            total-=mp[ind];
            total+=value;
            mp[ind]=value;
            ans.push_back(total);
        }
        else{
            ll value;
            cin>>value;
            mp.clear();
            mp[-1]=value;
            total=n*value;
            //a.clear();
            //a.assign(n,value);
            ans.push_back(total);
        }
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<'\n';
    }
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
