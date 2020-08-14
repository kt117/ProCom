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
    
    ll R, G, B; cin >> R >> G >> B;
    ll r[R], g[G], b[B];

    zep(i, 0, R)cin >> r[i];
    zep(i, 0, G)cin >> g[i];
    zep(i, 0, B)cin >> b[i];

    sort(r, r + R, greater<>());
    sort(g, g + G, greater<>());
    sort(b, b + B, greater<>());
    
    ll dp[R + 1][G + 1][B + 1]; memset(dp, 0, sizeof(dp));

    ll ans = 0;
    rep(i, 0, R){
        rep(j, 0, G){
            rep(k, 0, B){
                if(i < R && j < G){
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + r[i] * g[j]);
                    ans = max(ans, dp[i + 1][j + 1][k]);
                }

                if(j < G && k < B){
                    dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + g[j] * b[k]);
                    ans = max(ans, dp[i][j + 1][k + 1]);
                }

                if(k < B && i < R){
                    dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + b[k] * r[i]);    
                    ans = max(ans, dp[i + 1][j][k + 1]);
                }
            }
        }
    }
    print(ans)

    return 0;
}