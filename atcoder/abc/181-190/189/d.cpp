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
    string s[n]; zep(i, 0, n)cin >> s[i];

    ll dp[n + 1][2];
    dp[0][0] = 1;
    dp[0][1] = 1;

    zep(i, 0, n){
        if(s[i] == "AND"){
            dp[i + 1][0] = 2 * dp[i][0] + dp[i][1];
            dp[i + 1][1] = dp[i][1];
        }else{
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][0] + 2 * dp[i][1];
        }
    }
    print(dp[n][1])

    return 0;
}