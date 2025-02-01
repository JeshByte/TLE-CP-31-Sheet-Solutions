#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>glasses;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        glasses.push_back(input);
    }
    vector<ll>odd(n+1,0);
    vector<ll>even(n+1,0);
    for(int i=1;i<=n;i++){
        if(i&1){
            odd[i]+=odd[i-1]+glasses[i-1];
            even[i]+=even[i-1];
        }
        else{
            odd[i]+=odd[i-1];
            even[i]+=even[i-1]+glasses[i-1];
        }
    }
    // for(int i=0;i<n+1;i++){
    //     cout<<even[i]<<" ";
    // }
    // cout<<'\n';
    map<ll,ll>diff;
    diff[0]++;
    for(int i=1;i<=n;i++){
        ll d=odd[i]-even[i];
        if(diff.find(d)!=diff.end()){
            cout<<"YES\n";
            return;
        }
        diff[d]++;
    }
    cout<<"NO\n";
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
