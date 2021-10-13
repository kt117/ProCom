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
    
    string s; cin >> s;
    ll n = s.size();

    ll dp[n + 1][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    zep(i, 0, n){
        if(i > 0 && s[i] == s[i - 1]){
            dp[i + 1][0] = dp[i][1] % MOD;
            dp[i + 1][1] = dp[i][0] % MOD;
        }else{
            dp[i + 1][0] = (dp[i][0] + dp[i][1]) % MOD;
            dp[i + 1][1] = dp[i][0] % MOD;
        }
    }

    print((dp[n][0] + dp[n][1]) % MOD)
    
    return 0;
}