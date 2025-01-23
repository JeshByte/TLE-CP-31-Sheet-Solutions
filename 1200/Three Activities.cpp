#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<pair<ll,ll>>a,b,c;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        a.push_back({input,i});
    }    
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        b.push_back({input,i});
    } 
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        c.push_back({input,i});
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());
    vector<pair<ll,ll>>ans1,ans2,ans3;
    ans1={a[0],a[1],a[2]};
    ans2={b[0],b[1],b[2]};
    ans3={c[0],c[1],c[2]};
    ll ans=-1;
    for(int i=0;i<3;i++){
        ll temp=ans1[i].first;
        for(int j=0;j<3;j++){
            if(ans2[j].second!=ans1[i].second){
                temp+=ans2[j].first;
                for(int k=0;k<3;k++){
                    if(ans3[k].second!=ans2[j].second && ans3[k].second!=ans1[i].second){
                        temp+=ans3[k].first;
                        //cout<<temp<<'\n';
                        //cout<<ans1[i].first<<" "<<ans2[j].first<<" "<<ans3[k].first<<'\n';
                        ans=max(ans,temp);
                        temp-=ans3[k].first;
                    }
                }
                temp-=ans2[j].first;
            }            
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
