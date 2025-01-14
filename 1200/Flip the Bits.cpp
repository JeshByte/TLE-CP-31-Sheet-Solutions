#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"YES\n";
        return;
    }
    ll i=0;
    while(i<n){
        ll oc=0,zc=0;
        while(i<n && a[i]==b[i]){
            if(a[i]=='0'){
                zc++;
            }
            else{
                oc++;
            }
            i++;
        }
        ll oi=0,zi=0;
        while(i<n && a[i]!=b[i]){
            if(a[i]=='0'){
                zi++;
            }
            else{
                oi++;
            }
            i++;
        }
        ll tz=zi+zc;
        ll to=oi+oc;
        if(zi==0 && oi==0){
            break;
        }
        if(tz==to && zc==oc){
            continue;
        }
        else{
            //cout<<i<<" "<<zc<<" "<<oc<<" "<<zi<<" "<<oi<<'\n';
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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
