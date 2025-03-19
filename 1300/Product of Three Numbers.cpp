#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    set<ll>s;
    for(int i=2;i<=sqrtl(n);i++){
        if(n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    vector<ll>factors;
    for(auto it:s){
        factors.push_back(it);
    }
    ll req=n;
    set<ll>ans;
    ll cnt=0;
    for(int i=0;i<factors.size();i++){
        if(req%factors[i]==0){
            ans.insert(factors[i]);
            req=req/factors[i];
            cnt++;
            if(cnt==2){
                ans.insert(req);
                break;
            }
        }
    }
    bool flag=true;
    for(auto it:ans){
        if(it<2){
            flag=false;
            break;
        }
    }
    if(ans.size()==3 && flag){
        cout<<"YES\n";
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<'\n';
    }
    else{
        cout<<"NO\n";
    }
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
