#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    string ans="a";
    vector<ll>ind={0,1,2};
    ll check=1;
    while(1){
      if(s.find(ans)!=string::npos){
        if(check==1){
          if(ans[0]=='z'){
            ans="aa";
            check=2;
          }
          else{
            ans[0]++;
          }
        }
        else if(check==2){
          if(ans[1]=='z'){
            if(ans[0]=='z'){
              ans="aaa";
              check=3;
            }
            else{
              ans[0]++;
              ans[1]='a';
            }
          }
          else{
            ans[1]++;
          }
        }
        else{
          if(ans[2]=='z'){
            if(ans[1]=='z'){
              if(ans[0]=='z'){
                break;
              }
              else{
                ans[0]++;
                ans[1]='a';
                ans[2]='a';
              }
            }
            else{
              ans[1]++;
              ans[2]='a';
            }
          }
          else{
            ans[2]++;
          }
        }
      }
      else{
        break;
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
