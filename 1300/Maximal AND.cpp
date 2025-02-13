#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,k;
    cin>>n>>k;
    vector<ll>arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    vector<ll>set_bits(32,0);
    for(int i=0;i<n;i++){
        ll num=arr[i];
        ll ind=0;
        while(num>0){
            ll bit=num&1;
            if(bit){
                set_bits[ind]++;
            }
            num=num>>1;
            ind++;
        }
    }
    for(int i=30;i>=0;i--){
        ll unset=n-set_bits[i];
        if(unset>k){
            continue;
        }
        else{
            set_bits[i]=n;
            k-=unset;
            if(k<=0){
                break;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<32;i++){
        if(set_bits[i]==n){
            ans+=(1ll<<i);
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
