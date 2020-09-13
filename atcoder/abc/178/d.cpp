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

ll dp[2020][2020]; 

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll s; cin >> s;
    
    
    dp[0][0] = 1;
    
    rep(i, 0, 2000){
        ll x = 0;

        rep(j, 0, 2000){
            x += dp[i][j]; x %= MOD;

            dp[i + 1][j + 3] += x; dp[i + 1][j + 3] %= MOD;
        }
    }

    ll ans = 0;
    rep(i, 0, 2000){
        ans += dp[i][s]; ans %= MOD;
    }
    print(ans)
    
    return 0;
}