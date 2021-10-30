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
    
    ll h, w; cin >> h >> w;
    ll a[h][w];
    zep(i, 0, h)zep(j, 0, w)cin >> a[i][j];

    bool ok = true;
    zep(i, 0, h){
        zep(ii, 0, i){
            zep(j, 0, w){
                zep(jj, 0, j){
                    if(a[i][j] + a[ii][jj] > a[ii][j] + a[i][jj])ok = false;
                }
            }
        }
    }

    print(ok? "Yes" : "No")
    
    return 0;
}