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

    ll dp[n + 1][k + 10][4]; memset(dp, 0, sizeof(dp));

    dp[1][1][0] += 1;
    dp[1][2][1] += 1;
    dp[1][2][2] += 1;
    dp[1][1][3] += 1;
    
    vector<vector<ll>> dc = {{0, 1, 1, 1}, {0, 0, 2, 0}, {0, 2, 0, 0}, {1, 1, 1, 0}};

    rep(i, 2, n){
        rep(j, 0, k){
            zep(si, 0, 4){
                zep(sj, 0, 4){
                    dp[i][j + dc[si][sj]][sj] += dp[i - 1][j][si];
                    dp[i][j + dc[si][sj]][sj] %= MOD;
                }
            }
        }
    }
    
    ll ans = 0;
    zep(s, 0, 4){
        ans += dp[n][k][s];
        ans %= MOD;
    }

    print(ans)

    return 0;
}