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
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll dp[n + 1][n + 1];
    rep(i, 0, n)rep(j, 0, n)dp[i][j] = INF;
    dp[0][0] = 0;

    ll b = 0;
    zep(i, 0, n){
        if(a[i] == 1){
            b++;
            zep(j, 0, n){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + abs(j - b));
            }
        }else{
            zep(j, 0, n){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + abs(j - b));
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(j + 1 - b));
            }
        }
    }

    print(dp[n][b])

    return 0;
}