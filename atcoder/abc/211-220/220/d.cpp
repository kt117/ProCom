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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll dp[n][10]; memset(dp, 0, sizeof(dp));
    dp[0][a[0]]++;

    zep(i, 1, n){
        zep(k, 0, 10){
            dp[i][(k + a[i]) % 10] += dp[i - 1][k];
            dp[i][(k + a[i]) % 10] %= MOD;
            dp[i][(k * a[i]) % 10] += dp[i - 1][k];
            dp[i][(k * a[i]) % 10] %= MOD;
        }
    }

    zep(k, 0, 10){
        print(dp[n - 1][k])
    }
    
    return 0;
}