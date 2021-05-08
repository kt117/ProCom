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
    
    ll n, m; cin >> n >> m;
    bool c[n][n]; memset(c, 0, sizeof(c));
    zep(i, 0, n)c[i][i] = true;

    zep(j, 0, m){
        ll a, b; cin >> a >> b; a--; b--;
        c[a][b] = true;
        c[b][a] = true;
    }

    ll ans = 0, mi, mj, mk;
    zep(i, 0, n){
        zep(j, i + 1, n){
            zep(k, j + 1, n){
                ll cnt = 0;
                zep(l, 0, n){
                    if(c[i][l] || c[j][l] || c[k][l])cnt++;
                }
                if(cnt > ans){
                    ans = cnt;
                    mi = i;
                    mj = j;
                    mk = k;
                }
            }
        }
    }
    cout << mi + 1 << " " << mj + 1 << " " << mk + 1 << endl;
    
    return 0;
}