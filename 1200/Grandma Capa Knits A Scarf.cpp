#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
bool isPalindrome(string s){
    string tp=s;
    reverse(tp.begin(),tp.end());
    return tp==s;
}
ll minop(string s,char todelete, ll n){
    ll i=0,j=n-1;
    ll ans=0;
    while(i<j){
        if(s[i]==s[j]){
            //cout<<"equal "<<s[i]<<" "<<s[j]<<'\n';
            i++;
            j--;
            continue;
        }
        else{
            if(s[i]==todelete){
                //cout<<"i delete "<<s[i]<<" "<<s[j]<<'\n';
                i++;
                ans++;
                continue;
            }
            else if(s[j]==todelete){
                //cout<<"j delete "<<s[i]<<" "<<s[j]<<'\n';
                j--;
                ans++;
                continue;
            }
            else{
                //cout<<"invalid "<<s[i]<<" "<<s[j]<<'\n';
                ans=1e6;
                break;
            }
        }
    }
    return ans;
}
void solve(ll t){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    if(isPalindrome(s)){
        cout<<0<<'\n';
        return;
    }
    ll i=0,j=n-1;
    char ele1,ele2;
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            ele1=s[i];
            ele2=s[j];
            break;
        }
    }
    //cout<<ele1<<" "<<ele2<<'\n';
    ll ans1=minop(s,ele1,n);
    ll ans2=minop(s,ele2,n);
    ll valid=min(ans1,ans2);
    if(valid==1e6){
        valid=-1;
    }
    cout<<valid<<'\n';
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
