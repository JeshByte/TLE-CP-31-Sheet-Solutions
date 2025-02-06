#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>a,b;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        a.push_back(input);
    }
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        b.push_back(input);
    }
    //vector<list<ll>>adj;
    vector<pair<ll,ll>>comp;
    for(int i=0;i<n;i++){
        comp.push_back({a[i]-b[i],i});
    }
    sort(comp.rbegin(),comp.rend());
    vector<ll>res;
    ll temp=comp[0].first;
    for(int i=0;i<n;i++){
        if(temp==comp[i].first){
            res.push_back(comp[i].second+1);
        }
    }
    cout<<res.size()<<'\n';
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
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
