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

ll n, a[3939], dp[3939][3939];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    rep(i, 1, n)cin >> a[i];
    rep(i, 1, n)a[i] += a[i - 1];

    dp[0][0] = 1;
    rep(i, 1, n){
        vector<vector<ll>> v(i);
        rep(j, 0, n){
            v[a[j] % i].push_back(j);
        }

        zep(k, 0, i){
            ll buf = 0;
            zep(j, 0, v[k].size()){
                dp[i][v[k][j]] += buf;
                dp[i][v[k][j]] %= MOD;
                buf += dp[i - 1][v[k][j]];
                buf %= MOD;
            }
        }
    }
    
    ll ans = 0;
    rep(i, 1, n){
        ans += dp[i][n];
        ans %= MOD;
    }
    print(ans)


    return 0;
}