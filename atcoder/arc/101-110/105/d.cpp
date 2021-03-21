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
        ll a[n]; zep(i, 0, n)cin >> a[i];

        if(n == 1){print("Second") continue;}
        if(n % 2 == 1){print("Second") continue;}

        sort(a, a + n);
        ll ok = true;
        zep(i, 0, n / 2){
            if(a[2 * i] != a[2 * i + 1]){
                ok = false;
            }
        }

        print(ok? "Second" : "First")
    }
    
    return 0;
}