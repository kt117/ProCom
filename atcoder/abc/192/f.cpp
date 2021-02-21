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

ll dp[101][101][100]; 

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, x; cin >> n >> x;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll ans = INF;

    rep(k, 1, n){
        memset(dp, -1, sizeof(dp));
        dp[0][0][0] = 0;

        zep(i, 0, n){
            rep(j, 0, k){
                zep(r, 0, k){
                    dp[i + 1][j][r] = dp[i][j][r];
                }
            }

            rep(j, 0, k){
                zep(r, 0, k){
                    if(dp[i][j][r] != -1){
                        dp[i + 1][j + 1][(r + a[i]) % k] = max(dp[i + 1][j + 1][(r + a[i]) % k], dp[i][j][r] + a[i]);
                    }
                }
            }
        }

        if(dp[n][k][x % k] != -1)ans = min(ans, (x - dp[n][k][x % k]) / k);
    }

    print(ans)
    
    return 0;
}