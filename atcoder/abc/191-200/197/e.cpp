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
    ll x[n], c[n]; zep(i, 0, n)cin >> x[i] >> c[i];
    
    map<ll, P> mp;
    zep(i, 0, n){
        if(mp.find(c[i]) == mp.end()){
            mp[c[i]] = P(x[i], x[i]);
        }
        mp[c[i]] = P(min(mp[c[i]].first, x[i]), max(mp[c[i]].second, x[i]));
    }

    ll m = mp.size();
    ll dp[m + 1][2]; memset(dp, 0, sizeof(dp));
    ll l = 0, r = 0;
    ll at = 0;
    for(auto it = mp.begin(); it != mp.end(); it++){
        ll L = (*it).second.first, R = (*it).second.second;
        
        dp[at + 1][0] = INF;
        dp[at + 1][1] = INF;

        if(R < l){
            dp[at + 1][0] = min(dp[at + 1][0], l - L + dp[at][0]);
        }else{
            dp[at + 1][0] = min(dp[at + 1][0], 2 * R - l - L + dp[at][0]);
        }

        if(R < r){
            dp[at + 1][0] = min(dp[at + 1][0], r - L + dp[at][1]);
        }else{
            dp[at + 1][0] = min(dp[at + 1][0], 2 * R - r - L + dp[at][1]);
        }
        
        if(L < l){
            dp[at + 1][1] = min(dp[at + 1][1], R + l - 2 * L + dp[at][0]);
        }else{
            dp[at + 1][1] = min(dp[at + 1][1], R - l + dp[at][0]);
        }

        if(L < r){
            dp[at + 1][1] = min(dp[at + 1][1], R + r - 2 * L + dp[at][1]);
        }else{
            dp[at + 1][1] = min(dp[at + 1][1], R - r + dp[at][1]);
        }
        
        l = L, r = R;
        at++;
        //cout << dp[at][0] << " " << dp[at][1] << endl;
    }
    print(min(dp[m][0] + abs(l), dp[m][1] + abs(r)))

    return 0;
}