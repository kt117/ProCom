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

const long long MAX = 2e5+100;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll n, k, a[200008], pa[310][200008], ax[310], tr[310];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    COMinit();

    cin >> n >> k;
    zep(i, 0, n)cin >> a[i];
    zep(i, 0, n)pa[0][i] = 1;

    zep(i, 0, n){
        rep(j, 1, k){
            pa[j][i] = pa[j - 1][i] * a[i] % MOD;
        }
    }

    rep(x, 0, k){
        zep(i, 0, n){
            ax[x] += pa[x][i];
            ax[x] %= MOD;
        }
        ax[x] *= finv[x];
        ax[x] %= MOD;
    }

    zep(i, 0, n){
        rep(j, 1, k){
            pa[j][i] = pa[j - 1][i] * 2 * a[i] % MOD;
        }
    }

    rep(x, 1, k){
        zep(i, 0, n){
            tr[x] += pa[x][i];
            tr[x] %= MOD;
        }
    }

    rep(x, 1, k){
        ll ans = 0;
        
        rep(xx, 0, x){
            ans += ax[xx] * ax[x - xx] % MOD;
            ans %= MOD;
        }
        ans *= fac[x];
        ans %= MOD;
        ans += MOD - tr[x];
        ans %= MOD;
        ans *= (MOD + 1) / 2;
        ans %= MOD;
        print(ans)
    }
    
    return 0;
}