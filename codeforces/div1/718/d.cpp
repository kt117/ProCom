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
    ll h[n][m - 1]; zep(i, 0, n)zep(j, 0, m - 1)cin >> h[i][j];
    ll v[n - 1][m]; zep(i, 0, n - 1)zep(j, 0, m)cin >> v[i][j];

    if(k % 2){
        zep(i, 0, n){zep(j, 0, m)cout << -1 << " "; cout << endl;}
        return 0;
    } 

    ll dp[k / 2 + 1][n][m]; memset(dp, 0, sizeof(dp));

    rep(t, 1, k / 2){
        zep(i, 0, n){
            zep(j, 0, m){
                ll r = INF;
                if(i > 0)r = min(r, dp[t - 1][i - 1][j] + v[i - 1][j]);
                if(i < n - 1)r = min(r, dp[t - 1][i + 1][j] + v[i][j]);
                if(j > 0)r = min(r, dp[t - 1][i][j - 1] + h[i][j - 1]);
                if(j < m - 1)r = min(r, dp[t - 1][i][j + 1] + h[i][j]);
                dp[t][i][j] = r;
            }
        }
    }

    zep(i, 0, n){
        zep(j, 0, m)cout << 2 * dp[k / 2][i][j] << " "; cout << endl;
    }

    return 0;
}