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
    
    ll h, w;
    cin >> h >> w;

    ll mn = INF;
    ll a[h][w];
    zep(i, 0, h){
        zep(j, 0, w){
            cin >> a[i][j];
            mn = min(mn, a[i][j]);
        }
    }

    ll ans = 0;
    zep(i, 0, h){
        zep(j, 0, w){
            ans += a[i][j] - mn;
        }
    }
    print(ans)
    
    return 0;
}