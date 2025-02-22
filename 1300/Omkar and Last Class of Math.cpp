#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    if(n&1){
        set<ll>factors;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                factors.insert(i);
                factors.insert(n/i);
            }
        }
        ll lcm=n-1,a=-1,b=-1;
        for(auto it:factors){
            //cout<<factors[i]<<'\n';
            ll num1=it;
            ll num2=n-num1;
            ll req=(num1*num2)/(__gcd(num1,num2));
            if(req<=lcm && num1!=0 && num2!=0){
                a=num1;
                b=num2;
            }
        }
        cout<<a<<" "<<b<<'\n';
    }
    else{
        cout<<n/2<<" "<<n/2<<'\n';
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
