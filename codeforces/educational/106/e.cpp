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
    
    string x, y; cin >> x >> y;
    ll n = x.size(), m = y.size();

    ll dp2[n]; memset(dp2, 0, sizeof(dp2));
    zep(i, 0, n){
        if(i > 0 && x[i] != x[i - 1]){
            dp2[i] += dp2[i - 1]; dp2[i] %= MOD;
        }
        dp2[i]++; dp2[i] %= MOD;
    }

    ll dp3[m]; memset(dp3, 0, sizeof(dp3));
    zep(j, 0, m){
        if(j > 0 && y[j] != y[j - 1]){
            dp3[j] += dp3[j - 1]; dp3[j] %= MOD;
        }
        dp3[j]++; dp3[j] %= MOD;
    }

    ll dp[n][m][2]; memset(dp, 0, sizeof(dp));
    zep(i, 0, n){
        zep(j, 0, m){
            if(i > 0){
                if(x[i] != x[i - 1]){
                    dp[i][j][0] += dp[i - 1][j][0];
                    dp[i][j][0] %= MOD;
                }

                if(x[i] != y[j]){
                    dp[i][j][0] += dp[i - 1][j][1];
                    dp[i][j][0] %= MOD;
                }
            }

            if(j > 0){
                if(y[j] != y[j - 1]){
                    dp[i][j][1] += dp[i][j - 1][1];
                    dp[i][j][1] %= MOD;
                }

                if(y[j] != x[i]){
                    dp[i][j][1] += dp[i][j - 1][0];
                    dp[i][j][1] %= MOD;
                }
            }

            if(x[i] != y[j]){
                dp[i][j][0] += dp3[j]; dp[i][j][0] %= MOD;
                dp[i][j][1] += dp2[i]; dp[i][j][1] %= MOD;
            }
        }
    }
    
    ll ans = 0;
    zep(i, 0, n){
        zep(j, 0, m){
            ans += dp[i][j][0]; ans %= MOD;
            ans += dp[i][j][1]; ans %= MOD;
        }
    }
    print(ans)
    
    return 0;
}