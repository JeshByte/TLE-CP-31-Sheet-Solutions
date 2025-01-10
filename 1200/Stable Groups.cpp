#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,k,x;
    cin>>n>>k>>x;
    vector<ll>students;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        students.push_back(input);
    }
    sort(students.begin(),students.end());
    int ans=0;
    vector<ll>diff;
    for(int i=0;i<n-1;i++){
        if(students[i+1]-students[i]>x){
            diff.push_back(students[i+1]-students[i]);
        }
    }
    sort(diff.begin(),diff.end());
    for(int i=0;i<diff.size();i++){
            if(k>0){
                if(Ceil(diff[i],(k+1))<=x){
                    k-=(Ceil(diff[i],x)-1);
                    //cout<<k<<'\n';
                }
                else{
                    ans++;
                }
            }
            else{
                ans++;
            }

    }
    cout<<ans+1<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
} 
