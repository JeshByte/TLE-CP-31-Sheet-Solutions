#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    ll q;
    cin>>q;
    vector<pair<ll,ll>>queries;
    for(int i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        queries.push_back({l,r});
    }
    vector<ll>unequal(n,-1);
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            unequal[i]=i-1;
        }
        else{
            unequal[i]=unequal[i-1];
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<unequal[i]<<" ";
    // }
    // cout<<'\n';
    for(int i=0;i<q;i++){
        ll tp=unequal[queries[i].second-1];
        if(tp!=(-1)){
            if(tp>=(queries[i].first-1)){
                cout<<tp+1<<" "<<queries[i].second<<'\n';
                continue;
            }
        }
        cout<<-1<<" "<<-1<<'\n';
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
