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

ll n, k;

long long gcd(long long a, long long b){return (b == 0)? a : gcd(b, a % b);}

long long powmod(long long a, long long x){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2);
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;

    map<ll, ll> mp[n + 1];
    mp[n][1] = 1;

    rrep(i, n, 1){
        rep(j, 1, i){
            ll res = 1;
            zep(pi, 0, j - 1){res *= i - pi - 1; res %= MOD;} // juzu

            for(auto it = mp[i].begin(); it != mp[i].end(); it++){
                ll s = (*it).first;
                ll ns = j * (s / gcd(j, s));

                if(mp[i - j].find(ns) == mp[i - j].end())mp[i - j][ns] = 0;
                mp[i - j][ns] += res * (*it).second % MOD;
                mp[i - j][ns] %= MOD;
            }
        }
    }

    ll ans = 0;
    for(auto it = mp[0].begin(); it != mp[0].end(); it++){
        ans += powmod((*it).first, k) * (*it).second % MOD;
        ans %= MOD;
    }
    print(ans)

    return 0;
}