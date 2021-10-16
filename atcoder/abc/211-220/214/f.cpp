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

    ll dp[n + 2];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    zep(i, 0, n){
        for(ll j = i;; j--){
            if(j == -1 || (i != j && s[i] == s[j]))break;
            dp[i + 2] += dp[j];
            dp[i + 2] %= MOD;
        }
    }
    
    ll ans = 0;
    zep(i, 0, n){
        ans += dp[i + 2];
        ans %= MOD;
    }
    print(ans)
    
    return 0;
}