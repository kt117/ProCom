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

ll n, k, mod, dp[101][25 * 49 * 101], ans[101], mx[101];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k >> mod;

    dp[0][0] = 1;

    rep(i, 1, n - 1)mx[i] = mx[i - 1] + i * k;
    rep(i, 0, n - 1)mx[i] = min(mx[i], mx[n - i - 1]);

    rep(i, 1, n - 1){
        rep(l, 0, mx[i - 1]){
            rep(j, 0, k){
                if(l + i * j > mx[i])break;

                dp[i][l + i * j] += dp[i - 1][l];
                dp[i][l + i * j] %= mod;
            }
        }
    }

    rep(i, 1, n){
        rep(j, 0, mx[i - 1]){
            ans[i] += dp[i - 1][j] * dp[n - i][j] % mod;
            ans[i] %= mod;
        }
        
        ans[i] *= k + 1;
        ans[i] %= mod;
        ans[i] += mod - 1;
        ans[i] %= mod;

        print(ans[i])
    }
    
    return 0;
}
