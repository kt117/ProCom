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
    ll a[n]; zep(i, 0, n)cin >> a[i];

    bool ok[100000 + 1]; memset(ok, 1, sizeof(ok));
    ok[1] = true;

    zep(i, 0, n){
        ll x = a[i];
        for(ll j = 2; j * j <= x; j++){
            if(x % j == 0){
                while(x % j == 0)x /= j;
                ok[j] = false;
            }
        }
        // print(x)
        if(x > 1)ok[x] = false;
    }

    rep(i, 2, m){
        if(!ok[i]){
            for(ll j = 1; j * i <= m; j++){
                ok[j * i] = false;
            }
        }
    }

    ll cnt = 0;
    rep(i, 1, m){
        if(ok[i])cnt++;
    }
    print(cnt)

    rep(i, 1, m){
        if(ok[i])print(i)
    }

    
    return 0;
}