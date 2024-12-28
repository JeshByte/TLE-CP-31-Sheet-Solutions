#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,x,y;
    cin>>n>>x>>y;
    ll mul_x=n/x;
    ll mul_y=n/y;
    ll lcm=(x*y)/__gcd(x,y);
    ll mul_com=n/lcm;
    mul_x-=mul_com;
    mul_y-=mul_com;
    ll sum_y=(mul_y*(mul_y+1))/2;
    ll sum_x=(mul_x*(2*n-mul_x+1))/2;
    cout<<sum_x-sum_y<<'\n';
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
