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
        ll a[n]; zep(i, 0, n){cin >> a[i]; a[i]--;}

        bool ok = true;
        zep(i, 0, n)if(a[i] != i)ok = false;
        if(ok){print(0) continue;}

        if(a[0] == 0 || a[n - 1] == n - 1){
            print(1) continue;
        }

        if(a[0] == n - 1 && a[n - 1] == 0){
            print(3) continue;
        }

        print(2)
    }
    
    return 0;
}