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

ll n, fac[1000008], dp[1000008];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    
    fac[1] = 1;
    rep(i, 2, n)fac[i] = i * fac[i - 1] % MOD; 

    dp[n + 1];
    dp[2] = 0;
    rep(i, 3, n)dp[i] = (2 * dp[i - 1] % MOD + fac[i] + MOD - 2 * fac[i - 1] % MOD) % MOD;
    
    print(dp[n])

    return 0;
}