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

ll n, N, x[20][2], p[20], c[(1LL << 16)], dp[20][(1 << 16)];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)cin >> x[i][0] >> x[i][1] >> p[i];

    N = (1LL << n);
    zep(bit, 1, N){
        c[bit] = INF;

        zep(k, 0, 2){
            ll a = 0, b = 0;

            zep(i, 0, n){
                if(bit & (1LL << i)){
                    a += x[i][k] * p[i];
                    b += p[i]; 
                }
            }

            ll g = (a == 0)? 0 : (a / abs(a)) * (2 * abs(a) + b) / (2 * b);
            
            ll cx = 0;
            zep(i, 0, n){
                if(bit & (1LL << i)){
                    cx += abs(x[i][k] - g) * p[i];
                }
            }

            c[bit] = min(c[bit], cx);
        }
    }

    zep(bit, 1, N){
        zep(i, 0, n){
            if(bit & (1LL << i)){
                dp[0][bit] += min(abs(x[i][0]), abs(x[i][1])) * p[i];
            }
        }
    }
    
    rep(t, 1, n){
        zep(bit, 0, N)dp[t][bit] = INF;

        zep(bi, 0, N){
            zep(bj, 0, N){
                dp[t][(bi | bj)] = min(dp[t][(bi | bj)], dp[t - 1][bi] + c[bj]);
            }
        }
    }

    rep(t, 0, n){
        print(dp[t][(1LL << n) - 1])
    }

    return 0;
}