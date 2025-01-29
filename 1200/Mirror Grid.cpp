#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)

void solve(ll t){
    int n;
    cin >> n;

    vector<string>arr(n); 

    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    ll ans=0;
    for(int i=0;i<n/2;i++){
        for(int j=0;j<(n+1)/2;j++){
            ll val1=arr[i][j]-'0';
            ll val2=arr[j][n-1-i]-'0';
            ll val3=arr[n-1-i][n-1-j]-'0';
            ll val4=arr[n-1-j][i]-'0';
            ll freq_1=val1+val2+val3+val4;
            ll freq_0=4-freq_1;
            ll freq=max(freq_0,freq_1);
            ans+=(4-freq);
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i); 
    }
    return 0;
}
