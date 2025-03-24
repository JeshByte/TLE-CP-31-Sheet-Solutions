#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>arr1;
    deque<ll>s;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr1.push_back(input);
    }
    for(int i=0;i<n;i++){
      ll input;
      cin>>input;
      s.push_back(input);
    }
    reverse(arr1.begin(),arr1.end());
    reverse(s.begin(),s.end());
    map<ll,bool>mark;
    ll ans=0;
    for(int i=0;i<n;i++){
      if(arr1[i]==s.front()){
        s.pop_front();
        while(mark[s.front()]){
          s.pop_front();
        }
      }
      else{
        ans++;
        mark[arr1[i]]=true;
      }
    }
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
} 
