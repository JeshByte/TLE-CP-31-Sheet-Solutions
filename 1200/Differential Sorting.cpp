#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>a;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        a.push_back(input);
    }
    vector<ll>tp=a;
    sort(tp.begin(),tp.end());
    if(tp==a){
        cout<<0<<'\n';
        return;
    }
    ll ind=-1;
    for(int i=n-2;i>=0;i--){
        if(a[i]<=a[i+1]){
            ind=i;
        }
        else{
            break;
        }
    }
    if(ind==-1){
        cout<<-1<<'\n';
        return;
    }
    if(a[ind]<0 && a[n-1]<0){
        cout<<-1<<'\n';
    }
    else{
        cout<<ind<<'\n';
        for(int i=0;i<ind;i++){
            cout<<i+1<<" "<<ind+1<<" "<<n<<'\n';
        }
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
