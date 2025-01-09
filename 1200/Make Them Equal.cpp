#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    char c;
    cin>>n>>c;
    string s;
    cin>>s;
    // if(t==71){
    //     cout<<n<<" "<<c<<" "<<s<<'\n';
    // }
    if(count(s.begin(),s.end(),c)==n){
        cout<<0<<'\n';
        return;
    }
    vector<ll>to_delete;
    for(int i=0;i<n;i++){
        if(s[i]!=c){
            to_delete.push_back(i+1);
        }
    }
    ll len=to_delete.size();
    ll ans=-1;
    for(int i=(n/2)+1;i<=n;i++){
        if(s[i-1]==c){
            ans=i;
            break;
        }
    }
    if(ans!=-1){
        cout<<1<<'\n';
        cout<<ans<<'\n';
    }
    else{
        ll ma=to_delete[len-1];
        ll ans=0;
        if(ma&1){
            ans=2;
        }
        else{
            if(ma==2){
                ans=3;
            }
            else{
            ans=ma-1;
            }
        }
        cout<<2<<'\n';
        cout<<ma<<" "<<ans<<'\n';
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
