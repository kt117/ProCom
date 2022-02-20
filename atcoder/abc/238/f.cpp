#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, k, p[500], q[500], dp[2][500][500];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;
    zep(i, 0, n){cin >> p[i]; p[i]--;}
    zep(i, 0, n){cin >> q[i]; q[i]--;}

    vector<P> v(n); zep(i, 0, n)v[i] = P(p[i], q[i]);
    sort(v.begin(), v.end(), greater<>());

    dp[0][0][0] = 1;
    zep(i, 0, n){
        memset(dp[1], 0, sizeof(dp[1]));

        rep(j, 0, k){
            rep(l, 0, n){
                if(l <= v[i].second){
                    dp[1][v[i].second][j + 1] += dp[0][l][j];
                    dp[1][v[i].second][j + 1] %= MOD;
                    dp[1][l][j] += dp[0][l][j];
                    dp[1][l][j] %= MOD;
                }else{
                    dp[1][l][j + 1] += dp[0][l][j];
                    dp[1][l][j + 1] %= MOD;
                }
            }
        }

        rep(j, 0, k){
            rep(l, 0, n){
                dp[0][l][j] = dp[1][l][j];
            }
        }
    }

    ll ans = 0;
    rep(l, 0, n){
        ans += dp[0][l][k];
        ans %= MOD;
    }
    print(ans)
    
    return 0;
}