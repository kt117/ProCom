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

const long long MAX = 2e5+100;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

vector<vector<ll>> g;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    COMinit();

    ll t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;

        vector<ll> tmp(n);
        g.swap(tmp);        

        zep(i, 0, n - 1){
            ll u, v; cin >> u >> v; u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);    
        }

        if(k == 2){
            print(n * (n - 1) / 2)
            continue;
        }

        warshall_floid();

        ll ans = 0;
        zep(i, 0, n){
            ll cnt[n]; memset(cnt, 0, sizeof(cnt));

            zep(j, 0, n){
                if(j != i){
                    cnt[dst[i][j]]++;
                }
            }

            zep(j, 0, n){
                ans += COM(cnt[j], k);
                ans %= MOD;
            }
        }
        print(ans)
    }
    
    return 0;
}