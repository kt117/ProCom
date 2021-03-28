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
    
    ll T; cin >> T;
    zep(t, 0, T){
        ll x, y; cin >> x >> y;
        string s; cin >> s;

        ll n = s.size();
        ll dp[n][2]; memset(dp, 0, sizeof(dp));
        if(s[0] == 'C')dp[0][1] = INF;
        if(s[0] == 'J')dp[0][0] = INF;

        zep(i, 1, n){
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
            dp[i][1] = min(dp[i - 1][0] + x, dp[i - 1][1]);
            if(s[i] == 'C')dp[i][1] = INF;
            if(s[i] == 'J')dp[i][0] = INF;
        }

        cout << "Case #" << t + 1 << ": " << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
    
    return 0;
}