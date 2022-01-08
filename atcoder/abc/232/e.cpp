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
    
    ll h, w, k; cin >> h >> w >> k;
    ll x[2], y[2]; cin >> x[0] >> y[0] >> x[1] >> y[1];

    ll dp[2][4]; memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    zep(j, 0, k){
        ll i = j % 2;
        dp[1 - i][0] = ((w - 1) * dp[i][1] + (h - 1) * dp[i][2]) % MOD;
        dp[1 - i][1] = (dp[i][0] + (w - 2) * dp[i][1] + (h - 1) * dp[i][3]) % MOD;
        dp[1 - i][2] = (dp[i][0] + (h - 2) * dp[i][2] + (w - 1) * dp[i][3]) % MOD;
        dp[1 - i][3] = (dp[i][1] + dp[i][2] + (h - 2 + w - 2) * dp[i][3]) % MOD;
    }

    if(x[0] == x[1]){
        if(y[0] == y[1]){
            print(dp[k % 2][0])
        }else{
            print(dp[k % 2][1])
        }
    }else{
        if(y[0] == y[1]){
            print(dp[k % 2][2])
        }else{
            print(dp[k % 2][3])
        }
    }

    return 0;
}