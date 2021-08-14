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
    
    ll t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        ll a[n + 1]; rep(i, 1, n)cin >> a[i];

        ll dp[n + 1][n + 1];
        rep(i, 0, n)rep(j, 0, n)dp[i][j] = -INF;
        dp[0][0] = 0;

        rep(i, 1, n){
            rep(j, 0, i){
                if(a[i] == i - j){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
                }else{
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }

                dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j]);
            }
        }

        ll ans = -1;
        rep(j, 0, n){
            if(dp[n][j] >= k){
                ans = j; 
                break;
            }
        }
        print(ans)
    }
    
    return 0;
}