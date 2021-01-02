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
    
    ll n, q; cin >> n >> q;
    bool f[n][n]; memset(f, 0, sizeof(f));
    while(q--){
        ll c; cin >> c;

        if(c == 1){
            ll a, b; cin >> a >> b; a--; b--;
            f[a][b] = true;
        }else if(c == 2){
            ll a; cin >> a; a--;
            zep(i, 0, n){
                if(f[i][a])f[a][i] = true;
            }
        }else{
            ll a; cin >> a; a--;
            bool b[n]; memset(b, 0, sizeof(b));
            zep(i, 0, n){
                if(f[a][i]){
                    zep(j, 0, n){
                        if(j != a && f[i][j])b[j] = true;
                    }
                }
            }

            zep(i, 0, n)if(b[i])f[a][i] = true;
        }
    }

    zep(i, 0, n){
        zep(j, 0, n)cout << (f[i][j]? 'Y' : 'N');
        cout << endl;
    }
    
    return 0;
}