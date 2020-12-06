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
        ll n, k; cin >> n >> k;
        ll x[n], y[n]; zep(i, 0, n)cin >> x[i] >> y[i];

        bool ok = false;
        zep(i, 0, n){
            bool oki = true;
            zep(j, 0, n){
                if(abs(x[i] - x[j]) + abs(y[i] - y[j]) > k)oki = false;
            }
            if(oki)ok = true;
        }

        print(ok? 1 : -1)
    }
    
    return 0;
}