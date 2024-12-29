#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>b;
    ll len=(n*(n-1))/2;
    for(int i=0;i<len;i++){
        ll input;
        cin>>input;
        b.push_back(input);
    }
    map<ll,ll>mp;
    for(int i=0;i<len;i++){
        mp[b[i]]++;
    }
    vector<ll>a(n);
    int i=0;
    for(auto it:mp){
        while(mp[it.first]>0){
            a[i]=it.first;
            mp[it.first]-=(n-i-1);
            i++;
        }
    }
    for(;i<n;i++){
        a[i]=1e9;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
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
