#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
std::vector<int> simpleSieve(int limit) {
    std::vector<bool> isPrime(limit + 1, true);
    std::vector<int> primes;
 
    isPrime[0] = isPrime[1] = false;
 
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
 
    return primes;
}
 
vector<ll> segmentedSieve(int L, int R) {
    int limit = std::sqrt(R);
    std::vector<int> primes = simpleSieve(limit);
 
    std::vector<bool> isPrime(R - L + 1, true);
 
    if (L == 1) {
        isPrime[0] = false;
    }
 
    for (int prime : primes) {
        int start = std::max(prime * prime, (L + prime - 1) / prime * prime);
 
        for (int j = start; j <= R; j += prime) {
            isPrime[j - L] = false;
        }
    }
    vector<ll>ans;
    for (int i = 0; i <= R - L; ++i) {
        if (isPrime[i]) {
            ans.push_back(L+i);
        }
    }
    //std::cout << std::endl;
    return ans;
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    if(count(arr.begin(),arr.end(),arr[0])==n){
        cout<<"YES\n";
        return;
    }
    //cout<<"hi\n";
    ll ma=*max_element(arr.begin(),arr.end());
    vector<ll>primes=segmentedSieve(1,sqrt(ma)+1);
    map<ll,ll>cnt;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            continue;
        }
        ll ind=0;
        ll num=arr[i];
        while(num>1 && ind<primes.size()){
            if(num%primes[ind]==0){
                num=num/primes[ind];
                cnt[primes[ind]]++;
            }
            else{
                ind++;
            }
        }
        if(num>1){
            cnt[num]++;
        }
    }
    for(auto it:cnt){
        if(it.second%n!=0){
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
