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

ll n, k;
string s, t;
ll dp[225][225][225];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k >> s >> t;

    rep(i, 0, n)rep(x, 0, n)rep(y, 0, n)dp[i][x][y] = -INF;
    dp[0][0][0] = 0;

    zep(i, 0, n){
        rep(x, 0, i){// t[0]
            rep(y, 0, k){
                if(t[0] == t[1]){
                    if(s[i] == t[0]){
                        dp[i + 1][x + 1][y] = max(dp[i + 1][x + 1][y], dp[i][x][y] + x);
                    }else{
                        dp[i + 1][x][y] = max(dp[i + 1][x][y], dp[i][x][y]);
                        dp[i + 1][x + 1][y + 1] = max(dp[i + 1][x + 1][y + 1], dp[i][x][y] + x);
                    }
                }else{
                    if(s[i] == t[0]){
                        dp[i + 1][x + 1][y] = max(dp[i + 1][x + 1][y], dp[i][x][y]);
                        dp[i + 1][x][y + 1] = max(dp[i + 1][x][y + 1], dp[i][x][y] + x);
                    }else if(s[i] == t[1]){
                        dp[i + 1][x + 1][y + 1] = max(dp[i + 1][x + 1][y + 1], dp[i][x][y]);
                        dp[i + 1][x][y] = max(dp[i + 1][x][y], dp[i][x][y] + x);
                    }else{
                        dp[i + 1][x][y] = max(dp[i + 1][x][y], dp[i][x][y]);
                        dp[i + 1][x + 1][y + 1] = max(dp[i + 1][x + 1][y + 1], dp[i][x][y]);
                        dp[i + 1][x][y + 1] = max(dp[i + 1][x][y + 1], dp[i][x][y] + x);
                    }
                }
            }
        }
    }
    
    ll ans = 0;
    rep(x, 0, n)rep(y, 0, k)ans = max(ans, dp[n][x][y]);
    print(ans)

    return 0;
}