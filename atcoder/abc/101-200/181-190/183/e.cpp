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
    
    ll h, w; cin >> h >> w;
    string s[h]; zep(i, 0, h)cin >> s[i];
    
    ll dp[h + 10][w + 10][4]; memset(dp, 0, sizeof(dp));
    dp[1][1][0] = 1;

    rep(i, 1, h){
        rep(j, 1, w){
            if(s[i - 1][j - 1] == '.'){
                dp[i][j][1] += dp[i - 1][j][0];
                dp[i][j][2] += dp[i][j - 1][0];
                dp[i][j][3] += dp[i - 1][j - 1][0];

                dp[i][j][1] += dp[i - 1][j][1];
                dp[i][j][2] += dp[i][j - 1][2];
                dp[i][j][3] += dp[i - 1][j - 1][3];

                dp[i][j][0] += dp[i][j][1];
                dp[i][j][0] += dp[i][j][2];
                dp[i][j][0] += dp[i][j][3];
                
                zep(k, 0, 4)dp[i][j][k] %= MOD;
            }
        }
    }

    print(dp[h][w][0])

    return 0;
}