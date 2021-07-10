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

ll n, h[5000], dp[5000][5000];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    rep(i, 1, n)cin >> h[i];

    dp[1][1] = 1;
    rep(i, 2, n){
        rep(j, 1, i){
            if(h[i] < h[i - 1]){
                dp[i][j] = (dp[i - 1][i - 1] + MOD - dp[i - 1][j - 1]) % MOD;
            }else if(h[i] == h[i - 1]){
                dp[i][j] = dp[i - 1][i - 1];
            }else{
                dp[i][j] = dp[i - 1][j - 1];
            }
        }

        rep(j, 1, i){
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    print(dp[n][n])
    
    return 0;
}