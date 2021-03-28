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
    
    ll h, n; cin >> h >> n;
    ll d[n]; zep(i, 0, n)cin >> d[i];

    ll sm = 0, mn = 0;
    zep(i, 0, n){
        sm += d[i];
        mn = min(mn, sm);
    }

    if(sm >= 0 && h + mn > 0){
        print(-1)
        return 0;
    }

    sm *= -1;
    ll ans = 0;
    if(h + mn > 0){
        ans += (h + mn + sm - 1) / sm;
        h -= ans * sm;
        ans *= n;
    }

    zep(i, 0, n){
        h += d[i];
        ans++;
        if(h <= 0)break;
    }
    print(ans)
    
    return 0;
}