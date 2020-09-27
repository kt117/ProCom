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
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll a[n + 1]; rep(i, 1, n)cin >> a[i];

        if(n == 1){print(0) continue;}
        
        ll sm = 0; rep(i, 1, n)sm += a[i];
        if(sm % n != 0){print(-1) continue;}

        print(3 * (n - 1))
        rep(i, 2, n){
            cout << 1 << " " << i << " " << (i - (a[i] % i)) % i << endl;
            a[i] += (i - (a[i] % i)) % i;
            cout << i << " " << 1 << " " << a[i] / i << endl;
        }

        rep(i, 2, n){
            cout << 1 << " " << i << " " << sm / n << endl;
        }
    }
    
    return 0;
}