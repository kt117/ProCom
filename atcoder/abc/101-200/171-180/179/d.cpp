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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    ll l[k], r[k]; zep(i, 0, k)cin >> l[i] >> r[i];

    ll dp[2 * n + 1]; memset(dp, 0, sizeof(dp));
    ll dp2[2 * n + 1]; memset(dp2, 0, sizeof(dp2));
    dp[1] = 1;

    rep(i, 1, n - 1){
        zep(j, 0, k){
            dp2[i + l[j]] += dp[i]; dp2[i + l[j]] %= MOD;
            dp2[i + r[j] + 1] += MOD - dp[i]; dp2[i + r[j] + 1] %= MOD;
        }

        dp2[i + 1] += dp2[i]; dp2[i + 1] %= MOD;
        dp[i + 1] = dp2[i + 1];
    }

    print(dp[n])

    return 0;
}