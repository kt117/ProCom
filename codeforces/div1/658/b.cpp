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
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll p[2 * n]; zep(i, 0, 2 * n)cin >> p[i];

        vector<vector<ll>> v;
        vector<ll> cur;
        zep(i, 0, 2 * n){
            if(cur.size() > 0 && p[i] > cur[0]){
                v.push_back(cur);
                vector<ll> tmp;
                cur.swap(tmp);
            }

            cur.push_back(p[i]);
        }
        v.push_back(cur);

        ll m = v.size();
        ll dp[m + 1][n + 1]; memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        zep(i, 0, m){
            zep(j, 0, n){
                if(dp[i][j] >= 0){
                    dp[i + 1][j] = dp[i][j];
                    if(j + v[i].size() <= n){
                        dp[i + 1][j + v[i].size()] = i;
                    }
                }
            }
        }

        print((dp[m][n] >= 0)? "YES" : "NO")
    }
    
    return 0;
}