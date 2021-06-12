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
    ll t[n]; zep(i, 0, n)cin >> t[i];

    bool dp[n * 1000 + 10]; memset(dp, 0, sizeof(dp));
    dp[0] = true;

    zep(i, 0, n){
        rrep(j, n * 1000, 0){
            if(dp[j]){
                dp[j + t[i]] = true;
            }
        }
    }

    ll sm = 0;
    zep(i, 0, n)sm += t[i];

    ll ans= INF;
    rep(j, 0, n * 1000){
        if(dp[j]){
            ans = min(ans, max(j, sm - j));
        }
    }
    print(ans)
    
    return 0;
}