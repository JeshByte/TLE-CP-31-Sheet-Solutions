#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,x;
    cin>>n>>x;
    vector<ll>v1;
    ll total=0;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        v1.push_back(input);
        total+=input;
    }
    sort(v1.begin(),v1.end());
    ll i=n-1;
    ll d=1,p=n,ans=0;
    while(i>=0){
        if(total<=x){
            ans+=(((x-total)/p)+1)*p;
            d+=((x-total)/p)+1;
            total+=(((x-total)/p)+1)*p;
        }
        else{
            while(total>x && i>=0){
                total-=(v1[i]+d-1);
                i--;
                p--;
            }
        }
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
