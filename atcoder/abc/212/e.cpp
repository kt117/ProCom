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

ll dp[5050][5050];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m, k; cin >> n >> m >> k;
    ll u[m], v[m]; zep(i, 0, m){cin >> u[i] >> v[i]; u[i]--; v[i]--;}

    dp[0][0] = 1;

    zep(i, 0, k){
        ll sm = 0;
        zep(j, 0, n){
            sm += dp[i][j]; sm %= MOD;
        }

        zep(j, 0, n){
            dp[i + 1][j] = (sm + MOD - dp[i][j]) % MOD;
        }

        zep(j, 0, m){
            dp[i + 1][v[j]] += MOD - dp[i][u[j]]; dp[i + 1][v[j]] %= MOD;
            dp[i + 1][u[j]] += MOD - dp[i][v[j]]; dp[i + 1][u[j]] %= MOD;
        }
    }
    print(dp[k][0])

    return 0;
}