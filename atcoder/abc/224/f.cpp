#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

long long powmod(long long a, long long x){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2);
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    string s; cin >> s;
    ll n = s.size();
    
    vector<ll> v(n);
    zep(i, 0, n)v[i] = s[n - 1 - i] - '0';
    
    ll sm = 0;
    zep(i, 0, n)sm += v[i];

    ll ans = 0, p = powmod(2, n - 1), q = 1;
    zep(i, 0, n){
        ans += v[i] * p % MOD * q % MOD;
        ans %= MOD;
        
        sm -= v[i];
        p *= (MOD + 1) / 2;
        p %= MOD;
        ans += sm * p % MOD * q % MOD;
        ans %= MOD;

        q *= 10;
        q %= MOD;
    }
    print(ans)

    return 0;
}