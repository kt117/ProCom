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

ll n, m, dst[500][500], ans;

void warshall_floid(){
    for(ll k = 0; k < n; k++){
        for(ll i = 0; i < n; i++)
            for(ll j = 0; j < n; j++)
                dst[i][j] = min(dst[i][k] + dst[k][j], dst[i][j]);

        zep(i, 0, n){
            zep(j, 0, n){
                if(dst[i][j] < INF){
                    ans += dst[i][j];
                }
            }
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    zep(i, 0, n)zep(j, 0, n)if(i != j)dst[i][j] = INF;

    zep(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;

        dst[a][b] = c;
    }

    warshall_floid();

    print(ans)

    return 0;
}