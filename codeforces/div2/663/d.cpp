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

ll n, m; 
vector<string> s;
vector<ll> a;

int f(int b, int c){
    return __builtin_popcount(b ^ c);
}

bool ok2(int j, int k){
    return (__builtin_popcount(j) + __builtin_popcount(k)) % 2 == 1;
}

bool ok3(int j, int k){
    return ok2((j >> 1), (k >> 1)) && ok2(j % 4, k % 4);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    s.resize(n);
    zep(i, 0, n)cin >> s[i];
    if(min(n, m) == 1){print(0) return 0;}
    if(min(n, m) > 3){print(-1) return 0;}

    if(n >= m){
        a.resize(n);
        zep(i, 0, n){
            a[i] = 0;
            zep(j, 0, m){
                a[i] *= 2;
                a[i] += s[i][j] - '0';
            }
        }
    }else{
        ll tmp = n; n = m; m = tmp;
        a.resize(n);
        zep(i, 0, n){
            a[i] = 0;
            zep(j, 0, m){
                a[i] *= 2;
                a[i] += s[j][i] - '0';
            }
        }
    }
    
    if(m == 2){
        ll dp[n][4];
        zep(j, 0, 4)dp[0][j] = f(a[0], j);

        zep(i, 1, n){
            zep(j, 0, 4){
                dp[i][j] = INF;
                zep(k, 0, 4){
                    if(ok2(j, k)){
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + f(a[i], j));
                    }
                }
            }
        }

        ll ans = INF;
        zep(j, 0, 4){
            ans = min(ans, dp[n - 1][j]);
        }
        print(ans)
    }

    if(m == 3){
        ll dp[n][8];
        zep(j, 0, 8)dp[0][j] = f(a[0], j);

        zep(i, 1, n){
            zep(j, 0, 8){
                dp[i][j] = INF;
                zep(k, 0, 8){
                    if(ok3(j, k)){
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + f(a[i], j));
                    }
                }
            }
        }

        ll ans = INF;
        zep(j, 0, 8){
            ans = min(ans, dp[n - 1][j]);
        }
        print(ans)
    }

    return 0;
}