#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>v1;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        v1.push_back(input);
    }
    map<ll,ll>mp;
    ll i=0,j=n-1;
    ll mi=1,ma=n;
    while(i+1<=j){
      mp[v1[i]]++;
      mp[v1[j]]++;
      if(!mp[mi] && !mp[ma]){
        cout<<i+1<<" "<<j+1<<'\n';
        return;
      }
      else if((v1[i]==mi || v1[i]==ma) && (v1[j]==mi || v1[j]==ma)){
        mi++;
        ma--;
        i++;
        j--;
      }
      else if(v1[i]==mi || v1[i]==ma){
        if(v1[i]==mi){
          mi++;
        }
        else{
          ma--;
        }
        i++;
      }
      else{
        if(v1[j]==mi){
          mi++;
        }
        else{
          ma--;
        }
        j--;
      }
    }
    cout<<-1<<'\n';
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
