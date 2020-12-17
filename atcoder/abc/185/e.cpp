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
    
    ll n, m; cin >> n >> m;
    ll a[n]; zep(i, 0, n)cin >> a[i];
    ll b[m]; zep(j, 0, m)cin >> b[j];

    ll dp[n + 1][m + 1]; memset(dp, 0, sizeof(dp));

    rep(i, 1, n){
        rep(j, 1, m){
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
            }else{
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    //rep(i, 0, n){rep(j, 0, m)cout << dp[i][j] << " "; cout << endl;} 

    print(n + m - dp[n][m])

    return 0;
}