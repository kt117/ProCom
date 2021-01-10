#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll MOD;

long long powmod(long long a, long long x){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2);
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    MOD = m;

    ll ans = 0;
    ll res = 1;
    map<P, ll> use;
    bool sh = false;
    for(ll i = n; i >= 0; i--){
        ll p = powmod(10, i);
        ans += (res / m) * p;
        ans %= MOD;
        res %= m;
        res *= 10;

        if(!sh && use.find(P(res, p)) != use.end()){
            sh = true;
            i %= n - i + 1 - use[P(res, p)];
            i++;
        }else{
            use[P(res, p)] = n - i + 1;
        }
    }

    print(ans)
    
    return 0;
}