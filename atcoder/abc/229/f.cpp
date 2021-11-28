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
    ll b[n]; zep(i, 0, n)cin >> b[i];

    ll ans = 0;
    zep(o, 0, 2){
        ll dp[n][2]; memset(dp, 0, sizeof(dp));

        if(o == 0){
            dp[0][1] = -INF;
        }else{
            dp[0][0] = -INF;
            dp[0][1] = a[0];
        }

        zep(i, 1, n){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + b[i - 1]);
            dp[i][1] = max(dp[i - 1][0] + b[i - 1], dp[i - 1][1]) + a[i];
        }

        ans = max(ans, max(dp[n - 1][o], dp[n - 1][1 - o] + b[n - 1]));
    }

    ans *= -1;
    zep(i, 0, n)ans += a[i] + b[i];
    print(ans)

    return 0;
}