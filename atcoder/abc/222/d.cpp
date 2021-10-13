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

ll dp[3030][3030];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];
    ll b[n]; zep(i, 0, n)cin >> b[i];


    dp[0][0] = 1;
    zep(i, 0, n){
        rep(j, 0, 3000){
            if(j < a[i] || b[i] < j){
                dp[i + 1][j] = 0;
            }else{
                dp[i + 1][j] = dp[i][j];
            }

            dp[i][j + 1] += dp[i][j];
            dp[i][j + 1] %= MOD;
        }
    }

    ll ans = 0;
    rep(j, 0, 3000){
        ans += dp[n][j];
        ans %= MOD;
    }
    print(ans)
    
    return 0;
}