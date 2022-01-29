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
    
    ll h, w, k; cin >> h >> w >> k;
    ll a[h]; zep(i, 0, h)cin >> a[i];
    ll b[w]; zep(j, 0, w)cin >> b[j];

    ll sa = 0, sb = 0;
    zep(i, 0, h)sa += a[i];
    zep(j, 0, w)sb += b[j];
    if(sa % k != sb % k){
        print(-1) return 0;
    }

    zep(i, 0, h)a[i] = (w * (k - 1) + k - a[i]) % k;
    zep(j, 0, w)b[j] = (h * (k - 1) + k - b[j]) % k;

    sa = 0, sb = 0;
    zep(i, 0, h)sa += a[i];
    zep(j, 0, w)sb += b[j];
    print(h * w * (k - 1) - max(sa, sb))

    return 0;
}