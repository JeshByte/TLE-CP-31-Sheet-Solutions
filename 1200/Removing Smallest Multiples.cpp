#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
 
    vector<bool> to_delete(n + 1, false);
    vector<bool> to_save(n + 1, false);
    vector<ll> tp;
    ll zero_count = 0;
 
 
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            to_save[i + 1] = true;
        } else {
            to_delete[i + 1] = true;
            tp.push_back(i + 1);
            zero_count++;
        }
    }
 
    if (zero_count == 0) {
        cout << 0 << '\n';
        return;
    }
    if (zero_count == n) {
        cout << n << '\n';
        return;
    }
 
    ll ans = 0;
 
    for (ll mul : tp) {
        for (ll j = mul; j <= n; j += mul) {
            if (to_delete[j]) {
                ans += mul;
                to_delete[j] = false;
                zero_count--;
                if (zero_count == 0) {
                    cout << ans << '\n';
                    return;
                }
            } else if (to_save[j]) {
                break;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
