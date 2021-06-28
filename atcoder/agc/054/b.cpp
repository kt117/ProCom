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

ll n, w[101], ex[101], sm, dp[2][100 * 101][101];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)cin >> w[i];

    ex[0] = 1;
    rep(i, 1, n)ex[i] = i * ex[i - 1] % MOD;

    zep(i, 0, n)sm += w[i];
    if(sm % 2 == 1){print(0) return 0;}

    dp[0][0][0] = 1;
    zep(i, 0, n){
        memset(dp[(i + 1) % 2], 0, sizeof(dp[(i + 1) % 2]));

        rep(j, 0, sm / 2){
            rep(k, 0, i){
                dp[(i + 1) % 2][j][k] += dp[i % 2][j][k];
                dp[(i + 1) % 2][j][k] %= MOD;
                dp[(i + 1) % 2][j + w[i]][k + 1] += dp[i % 2][j][k];
                dp[(i + 1) % 2][j + w[i]][k + 1] %= MOD;
            }
        }
    }
    
    ll ans = 0;
    zep(k, 1, n){
        ans += dp[n % 2][sm / 2][k] * (ex[k] * ex[n - k] % MOD) % MOD;
        ans %= MOD;
    }
    print(ans)

    return 0;
}