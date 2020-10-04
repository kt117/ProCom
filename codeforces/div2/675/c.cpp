#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    string s; cin >> s;
    ll n = s.size();
    vector<ll> v(n); zep(i, 0, n)v[i] = s[i] - '0';
    reverse(v.begin(), v.end());

    ll t[n + 10]; t[0] = 1;
    rep(i, 1, n)t[i] = 10 * t[i - 1] % MOD;  
    
    ll ans = 0;
    ll r = 0;

    zep(i, 0, n){
        if(i > 0){
            r += i * t[i - 1] % MOD;
            r %= MOD;

            ans += v[i] * r;
            ans %= MOD;
        }

        ans += (n - i) * (n - i - 1) % MOD * ((MOD + 1) / 2) % MOD * t[i] % MOD * v[i] % MOD;
        ans %= MOD;
        //print(ans)
    }

    print(ans)

    return 0;
}