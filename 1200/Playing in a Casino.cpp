#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>v1;
    for(int i=0;i<n;i++){
        vector<ll>tp;
        for(int j=0;j<m;j++){
            ll input;
            cin>>input;
            tp.push_back(input);
        }
        v1.push_back(tp);
    }
    priority_queue<ll>pq;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            pq.push(v1[j][i]);
        }
        for(int j=0;j<n;j++){
            v1[j][i]=pq.top();
            pq.pop();
        }
    }
    vector<ll>s;
    ll total=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            total+=v1[i][j];
        }
        s.push_back(total);
        total=0;
    }
    ll ans=0;
    ll len=s.size();
    // for(int i=0;i<len;i++){
    //     cout<<s[i]<<" ";
    // }
    // cout<<'\n';
    ll mul=len-1;
    for(int i=0;i<len;i++){
        ans+=(mul*s[i]);
        mul-=2;
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
