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
    if(n==2){
        cout<<2<<'\n';
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    map<ll,bool>mp;
    mp[0]=true;
    mp[n-1]=true;
    for(int i=0;i<n;i++){
        if(i+2>=n){
            break;
        }
        if(arr[i+1]>=min(arr[i],arr[i+2]) && arr[i+1]<=max(arr[i],arr[i+2])){
            mp[i+1]=false;
        }
        else{
            mp[i+1]=true;
        }
    }
    vector<ll>ans;
    for(int i=0;i<n;i++){
        if(mp[i]){
            ans.push_back(arr[i]);
        }
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
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
