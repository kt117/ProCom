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
    
    bool ok[1001]; memset(ok, 0, sizeof(ok));

    rep(a, 1, 1000){
        rep(b, 1, 1000){
            ll x = 4 * a * b + 3 * a + 3 * b;
            if(x <= 1000)ok[x] = true;
        }
    }
    
    ll n; cin >> n;
    ll ans = 0;
    while(n--){
        ll s; cin >> s;
        if(!ok[s])ans++;
    }
    print(ans)

    return 0;
}