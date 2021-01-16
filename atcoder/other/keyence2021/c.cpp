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

ll dp[5000][5000]; 
char c[5000][5000];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll h, w, k; cin >> h >> w >> k;
    ll H[k], W[k];
    char C[k];
    zep(i, 0, k)cin >> H[i] >> W[i] >> C[i];

    zep(i, 0, h)zep(j, 0, w)c[i][j] = 'N';
    zep(i, 0, k)c[H[i] - 1][W[i] - 1] = C[i];

    dp[0][0] = 1;
    zep(i, 0, h * w - k){
        dp[0][0] *= 3;
        dp[0][0] %= MOD;
    }
    
    ll t = (MOD + 1) / 3;
    zep(i, 0, h){
        zep(j, 0, w){
            if(c[i][j] == 'R' && j + 1 < w){
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }
            if(c[i][j] == 'D' && i + 1 < h){
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
            }
            if(c[i][j] == 'X'){
                if(i + 1 < h){
                    dp[i + 1][j] += dp[i][j];
                    dp[i + 1][j] %= MOD;
                }
                if(j + 1 < w){
                    dp[i][j + 1] += dp[i][j];
                    dp[i][j + 1] %= MOD;
                }
            }
            if(c[i][j] == 'N'){
                if(i + 1 < h){
                    dp[i + 1][j] += dp[i][j] * 2 % MOD * t % MOD;
                    dp[i + 1][j] %= MOD;
                }
                if(j + 1 < w){
                    dp[i][j + 1] += dp[i][j] * 2 % MOD * t % MOD;
                    dp[i][j + 1] %= MOD;
                }
            }
            //cout << dp[i][j];
        }
        //cout << endl;
    }

    print(dp[h - 1][w - 1])
    
    return 0;
}