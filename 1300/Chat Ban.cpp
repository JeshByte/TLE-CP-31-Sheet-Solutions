#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll k,x;
    cin>>k>>x;
    ll total=(((k)*(k+1))/2)+(((k)*(k-1))/2);
    if(total<=x){
        cout<<2*k-1<<'\n';
        return;
    }
    ll first_half=(((k)*(k+1))/2);
    if(first_half<x){
        x-=first_half;
        long double t1=(2*(k-1))+1;
        long double t2=sqrtl((t1*t1)-8*x);
        //cout<<t1<<" "<<t2<<'\n';
        t1-=t2;
        //cout<<t1<<'\n';
        ll ans=t1/2;
        if(ans*2!=t1){
            ans++;
        }
        cout<<ans+k<<'\n';
    }
    else if(first_half==x){
        cout<<k<<'\n';
        return;
    }
    else{
        long double term1=sqrtl(1+8*x);
        term1--;
        ll ans=term1/2;
        if(ans*2!=term1){
            ans++;
        }
        cout<<ans<<'\n';
        return;
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
