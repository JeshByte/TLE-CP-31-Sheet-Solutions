#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>v1;
    map<ll,ll>mp;
    map<ll,ll>ind;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        v1.push_back(input);
        mp[input]++;
        ind[input]=i+1;
    }
    if(count(v1.begin(),v1.end(),v1[0])==n){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    bool isUnique=false;
    ll uniq_ind=-1;
    for(auto it:mp){
        if(it.second==1){
            isUnique=true;
            uniq_ind=ind[it.first];
            break;
        }
    }
    if(isUnique){
        for(int i=1;i<=n;i++){
            if(i!=uniq_ind){
                cout<<i<<" "<<uniq_ind<<'\n';
            }
        }
    }
    else{
        ll dup=v1[0],req_ind=-1;
        for(int i=0;i<n;i++){
            if(v1[i]!=dup){
                req_ind=i+1;
                break;
            }
        }
        for(int i=1;i<n;i++){
            if(v1[i]==dup){
                cout<<i+1<<" "<<req_ind<<'\n';
            }
            else{
                cout<<1<<" "<<i+1<<'\n';
            }
        }
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
