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
    // if(t==166){
    //     cout<<n<<'\n';
    //     for(int i=0;i<n;i++){
    //         cout<<arr[i]<<" ";
    //     }
    //     cout<<'\n';
    // }
    if(count(arr.begin(),arr.end(),arr[0])==n){
        cout<<1<<'\n';
        return;
    }
    vector<ll>tp1,tp2;
    tp1=tp2=arr;
    sort(tp1.begin(),tp1.end());
    sort(tp2.rbegin(),tp2.rend());
    if(arr==tp1 || arr==tp2){
        cout<<2<<'\n';
        return;
    }
    vector<ll>arr2;
    for(int i=0;i<n;i++){
        if(i!=n-1){
            if(arr[i]==arr[i+1]){
                continue;
            }
        }
        arr2.push_back(arr[i]);
    }
    ll start = 0;
    bool isAscending = arr2[0]<=arr2[1];
    n=arr2.size();
    //bool isDescending = arr[0]>=arr[1];
    vector<pair<ll,ll>>result;
    for (int i = 1; i <= n; ++i) {
        if (i == n || (arr2[i] < arr2[i - 1] && isAscending) || (arr2[i] > arr2[i - 1] && !isAscending)) {
            result.push_back({start, i - 1});
            start = i-1;
            if (i < n) {
                isAscending = arr2[i] >= arr2[i - 1];
                //isDescending = arr[i]<=arr[i-1];
            }
        }
    }
    set<ll>ans;
    for(auto it:result){
        //cout<<it.first<<" "<<it.second<<'\n';
        ans.insert(it.first);
        ans.insert(it.second);
    }
    cout<<ans.size()<<'\n';
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
