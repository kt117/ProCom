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
    sort(a, a + n, greater<>());

    ll ok = INF;
    ll ng = 0;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;

        ll p = 0;
        zep(i, 0, n){
            p += max(a[i] - i / mid, 0LL);
        }

        if(p >= m){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    print((ok == INF)? -1 : ok)
    
    return 0;
}