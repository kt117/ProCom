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
    vector<ll> a(n + 1, 0); zep(i, 0, n)cin >> a[i];

    sort(a.begin(), a.end(), greater<>());
    // printa(a, 0, n)

    ll to[n];
    ll r = 0;
    zep(l, 0, n){
        while(2 * a[r] > a[l])r++;
        to[l] = r;
    }
    // printa(to, 0, n - 1)

    ll dp[n + 1][40];
    rep(i, 0, n)zep(j, 0, 40)dp[i][j] = INF;
    dp[0][0] = 0;

    zep(i, 0, n){
        zep(j, 0, 40){
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
        }

        zep(j, 0, 39){
            dp[to[i]][j + 1] = min(dp[to[i]][j + 1], dp[i][j]);
        }
    }

    zep(j, 0, 39){
        if(dp[n][j] <= k){
            cout << j << " " << dp[n][j] << endl;
            return 0;
        }
    }

    return 0;
}