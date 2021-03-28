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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m, k; cin >> n >> m >> k;
    ll a[n][m]; zep(i, 0, n)zep(j, 0, m)cin >> a[i][j];

    ll dp[n + 1][m + 1][m / 2 + 1][k]; memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 0;

    zep(i, 0, n){
        zep(j, 0, m){
            rep(jj, 0, m / 2){
                zep(kk, 0, k){
                    if(dp[i][j][jj][kk] != -1){
                        dp[i][j + 1][jj][kk] = max(dp[i][j + 1][jj][kk], dp[i][j][jj][kk]);
                        if(jj < m / 2){
                            dp[i][j + 1][jj + 1][(kk + a[i][j]) % k] = max(dp[i][j + 1][jj + 1][(kk + a[i][j]) % k], dp[i][j][jj][kk] + a[i][j]);
                        }
                    }
                }
            }
        }

        
        zep(kk, 0, k){
            rep(jj, 0, m / 2){
                dp[i + 1][0][0][kk] = max(dp[i + 1][0][0][kk], dp[i][m][jj][kk]);
            }
        }
    }

    print(dp[n][0][0][0])

    return 0;
}