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
    
    ll h, w, n, m; cin >> h >> w >> n >> m;

    ll mp[h][w]; memset(mp, 0, sizeof(mp));
    zep(i, 0, n){
        ll a, b; cin >> a >> b; a--; b--;
        mp[a][b] = 1;
    }

    zep(i, 0, m){
        ll c, d; cin >> c >> d; c--; d--;
        mp[c][d] = - 1;
    }

    bool li[h][w]; memset(li, 0, sizeof(li));

    zep(i, 0, h){
        bool ok = false;
        zep(j, 0, w){
            if(mp[i][j] == 1){
                ok = true;
            }else if(mp[i][j] == - 1){
                ok = false;
            }

            if(ok)li[i][j] = true;
        }

        ok = false;
        rrep(j, w - 1, 0){
            if(mp[i][j] == 1){
                ok = true;
            }else if(mp[i][j] == - 1){
                ok = false;
            }

            if(ok)li[i][j] = true;
        }
    }

    zep(j, 0, w){
        bool ok = false;
        zep(i, 0, h){
            if(mp[i][j] == 1){
                ok = true;
            }else if(mp[i][j] == - 1){
                ok = false;
            }

            if(ok)li[i][j] = true;
        }

        ok = false;
        rrep(i, h - 1, 0){
            if(mp[i][j] == 1){
                ok = true;
            }else if(mp[i][j] == - 1){
                ok = false;
            }

            if(ok)li[i][j] = true;
        }
    }

    ll ans = 0;
    zep(i, 0, h)zep(j, 0, w)if(li[i][j])ans++;
    print(ans)

    return 0;
}