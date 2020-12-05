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
    string s; cin >> s;
    
    ll dp[n + 1][3]; memset(dp, 0, sizeof(dp));

    ll p = 1;
    zep(i, 0, n){
        zep(j, 0, 3)dp[i + 1][j] += dp[i][j];

        if(s[i] == 'a'){
            dp[i + 1][0] += p;
        }else if(s[i] == 'b'){
            dp[i + 1][1] += dp[i][0];
        }else if(s[i] == 'c'){
            dp[i + 1][2] += dp[i][1];
        }else{
            dp[i + 1][0] *= 3;
            dp[i + 1][1] *= 3;
            dp[i + 1][2] *= 3;
            dp[i + 1][0] += p;
            dp[i + 1][1] += dp[i][0];
            dp[i + 1][2] += dp[i][1];
            p *= 3; p %= MOD;
        }

        zep(j, 0, 3)dp[i + 1][j] %= MOD;
    }

    print(dp[n][2])
    
    return 0;
}