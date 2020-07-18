#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e16;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, m, a[20][20];
P b[110], dst[1000][1000];

ll mp(ll p, ll x, ll y){
    ll res = p * n * n + x * n + y;
    if(0 <= x && x < n && 0 <= y && y < n)return res;
    return 3 * n * n;
}

P pp(P a, P b){
    return P(a.first + b.first, a.second + b.second);
}

void warshall_floid(){
    for(ll k = 0; k < 3 * m; k++)
        for(ll i = 0; i < 3 * m; i++)
            for(ll j = 0; j < 3 * m; j++)
                dst[i][j] = min(pp(dst[i][k], dst[k][j]), dst[i][j]);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)zep(j, 0, n)cin >> a[i][j];

    m = n * n;
    zep(i, 0, n)zep(j, 0, n)b[a[i][j] - 1] = P(i, j);

    zep(i, 0, 3 * m)zep(j, 0, 3 * m)dst[i][j] = P(INF, INF);
    
    ll dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    ll dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

    zep(i, 0, n){
        zep(j, 0, n){
            zep(k, 0, 3)zep(l, 0, 3)dst[mp(k, i, j)][mp(l, i, j)] = P(1, 1);

            zep(k, 0, n){
                dst[mp(0, i, j)][mp(0, i, k)] = P(1, 0);
                dst[mp(0, i, j)][mp(0, k, j)] = P(1, 0);
            }

            zep(k, 0, n){
                dst[mp(1, i, j)][mp(1, k, j + k - i)] = P(1, 0);
                dst[mp(1, i, j)][mp(1, k, j - k + i)] = P(1, 0);
            }

            zep(k, 0, 8){
                dst[mp(2, i, j)][mp(2, i + dx[k], j + dy[k])] = P(1, 0);
            }
        }
    }

    zep(i, 0, 3 * m)dst[i][i] = P(0, 0);

    warshall_floid();
    
    P dp[m][3];
    zep(j, 0, 3)dp[0][j] = P(0, 0);
    
    zep(i, 0, m - 1){
        zep(j, 0, 3){
            dp[i + 1][j] = P(INF, INF);

            zep(k, 0, 3){
                //cout << mp(k, b[i].first, b[i].second) << " -> " << mp(j, b[i + 1].first, b[i + 1].second) << endl;
                dp[i + 1][j] = min(dp[i + 1][j], pp(dp[i][k], dst[mp(k, b[i].first, b[i].second)][mp(j, b[i + 1].first, b[i + 1].second)]));
            }
        }
        //zep(j, 0, 3){cout << dp[i + 1][j].first << " " << dp[i + 1][j].second << endl;}
    }

    P ans = P(INF, INF);
    zep(j, 0, 3)ans = min(ans, dp[m - 1][j]);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}