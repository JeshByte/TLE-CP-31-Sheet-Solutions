#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define Ceil(a, b) ((a + b - 1) / b)
void solve(ll t) {
   ll n;
   cin>>n;
   vector<pair<ll,ll>>arr;
   for(int i=0;i<n;i++){
    ll input;
    cin>>input;
    arr.push_back({input,i});
   }
   sort(arr.begin(),arr.end());
   vector<ll>pre(n+1,0);
   for(int i=1;i<=n;i++){
    pre[i]=pre[i-1]+arr[i-1].first;
   }
   vector<ll>ans;
   for(int i=0;i<n;i++){
    if(i==n-1){
        ll s=pre[n-1];
        s-=arr[n-2].first;
        if(s==arr[n-2].first){
            ans.push_back(arr[i].second+1);
        }
        continue;
    }
    ll s=pre[n-1];
    s-=arr[i].first;
    if(s==arr[n-1].first){
        ans.push_back(arr[i].second+1);
    }
   }
   cout<<ans.size()<<'\n';
   for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
   }
   cout<<'\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve(t);
    }
    return 0;
}
