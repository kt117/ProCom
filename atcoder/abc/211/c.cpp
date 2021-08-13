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
    string t = "chokudai";

    ll dp[s.size() + 1][t.size() + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    zep(i, 0, s.size()){
        zep(j, 0, t.size() + 1){
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
        }

        zep(j, 0, t.size()){
            if(s[i] == t[j]){
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= MOD;
            }
        }
    }

    print(dp[s.size()][t.size()])

    return 0;
}