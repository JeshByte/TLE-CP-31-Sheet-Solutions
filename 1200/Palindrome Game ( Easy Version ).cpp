#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1){
        cout<<"BOB\n";
        return;
    }
    ll freq=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            freq++;
        }
    }
    if(n&1){
        if(s[n/2]=='0' && freq>1){
        cout<<"ALICE\n";
        return;
        }
        else{
            cout<<"BOB\n";
            return;
        }
    }
    else{
        cout<<"BOB\n";
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
