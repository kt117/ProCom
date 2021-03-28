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

ll n, m, a[20][10010], u[20][20], d[20][20];

ll f(){
    ll res = 0;

    zep(i, 0, n){
        ll dp[1LL << n][n]; memset(dp, -1, sizeof(dp));
        dp[(1LL << i)][i] = INF;
        bool use[1LL << n]; memset(use, 0, sizeof(use));
        use[1LL << i] = true;
        queue<ll> q;
        q.push((1LL << i));
        
        while(!q.empty()){
            ll at = q.front(); q.pop();
            zep(j, 0, n){
                zep(k, 0, n){
                    if((at & (1LL << j)) && !(at & (1LL << k))){
                        ll nx = (at | (1LL << k));
                        if(!use[nx]){use[nx] = true; q.push(nx);}
                        dp[nx][k] = max(dp[nx][k], min(dp[at][j], d[j][k]));
                    }
                }
            }
        }

        zep(j, 0, n){
            res = max(res, min(dp[(1LL << n) - 1][j],  u[j][i]));
        }
    }
    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    zep(i, 0, n)zep(j, 0, m)cin >> a[i][j];
    
    zep(i, 0, n){
        zep(j, 0, n){
            d[i][j] = INF;
            u[i][j] = INF;
            zep(k, 0, m)d[i][j] = min(d[i][j], abs(a[i][k] - a[j][k]));
            zep(k, 1, m)u[i][j] = min(u[i][j], abs(a[i][k - 1] - a[j][k]));
        }
    }

    print(f())
    
    return 0;
}