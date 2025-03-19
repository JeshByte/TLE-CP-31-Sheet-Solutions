#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll maxSubarraySum(vector<ll> &arr,ll l,ll r) {
    ll res = arr[l];
    ll maxEnding = arr[l];
 
    for (int i = l+1; i <= r; i++) {
 
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
 
        res = max(res, maxEnding);
    }
    return res;
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>arr;
    ll s=0;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
        s+=input;
    }
    ll ans1=maxSubarraySum(arr,0,n-2);
    ll ans2=maxSubarraySum(arr,1,n-1);
    //cout<<ans1<<" "<<ans2<<'\n';
    ll res=max(ans1,ans2);
    //cout<<res<<" "<<s<<'\n';
    if(s>res){
        cout<<"YES\n";
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
