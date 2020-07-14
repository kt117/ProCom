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
    
    ll n, k; cin >> n >> k;
    ll a[n]; zep(i, 0, n)cin >> a[i];
    sort(a, a + n);

    ll l = 0, r = 0, ans[n];
    while(r < n){
        while(a[r] - a[l] > 5)l++;

        ans[r] = r - l + 1;

        r++;
    }

    ll dp[n + 1][k + 1]; memset(dp, 0, sizeof(dp));

    rep(i, 1, n){
        rep(j, 0, k){
            dp[i][j] = dp[i - 1][j];
        }

        rep(j, 1, k){
            dp[i][j] = max(dp[i][j], dp[i - ans[i - 1]][j - 1] + ans[i - 1]);
        }
    }

    print(dp[n][k])

    return 0;
}