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
    
    ll R, C, K; cin >> R >> C >> K;

    ll V[R][C]; memset(V, 0, sizeof(V));
    zep(i, 0, K){
        ll r, c, v; cin >> r >> c >> v;
        V[r - 1][c - 1] = v;
    }

    ll dp[R][C][4]; memset(dp, 0, sizeof(dp));
    
    zep(i, 0, R){
        zep(j, 0, C){
            rep(t, 0, 3){
                if(i + 1 < R)dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][t]);
                if(j + 1 < C)dp[i][j + 1][t] = max(dp[i][j + 1][t], dp[i][j][t]);
            }

            if(V[i][j] > 0){
                rep(t, 0, 2){
                    if(i + 1 < R)dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][t] + V[i][j]);
                    if(j + 1 < C)dp[i][j + 1][t + 1] = max(dp[i][j + 1][t + 1], dp[i][j][t] + V[i][j]);
                }
            }
        }
    }

    rep(t, 0, 2)dp[R - 1][C - 1][t] += V[R - 1][C - 1];

    ll ans = 0;
    rep(t, 0, 3)ans = max(ans, dp[R - 1][C - 1][t]);
    print(ans)
    
    return 0;
}