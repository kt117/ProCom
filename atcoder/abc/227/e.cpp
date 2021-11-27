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

ll dp[50][50][100];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll h, w, k; cin >> h >> w >> k;
    ll a[h][w]; zep(i, 0, h)zep(j, 0, w)cin >> a[i][j];
    
    // zep(i, 0, h)zep(j, 0, w)rep(l, 0, k)dp[i][j][l] = INF;
    // dp[0][0][0] = 0;
    // dp[0][0][1] = a[0][0];

    // zep(i, 0, h){
    //     zep(j, 0, w){
    //         rrep(l, k, 0){
    //             dp[i + 1][j][l] = min(dp[i + 1][j][l], dp[i][j][l]);
    //             dp[i][j + 1][l] = min(dp[i][j + 1][l], dp[i][j][l]);
    //             dp[i + 1][j][l + 1] = min(dp[i + 1][j][l + 1], dp[i][j][l] + a[i + 1][j]);
    //             dp[i][j + 1][l + 1] = min(dp[i][j + 1][l + 1], dp[i][j][l] + a[i][j + 1]);
    //         }
    //     }
    // }

    // print(dp[h - 1][w - 1][k])

    return 0;
}