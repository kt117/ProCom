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
        ll n, a, b; cin >> n >> a >> b;

        if(b == 1){
            print("Yes")
            continue;
        }

        if(a == 1){
            print((n % b == 1)? "Yes" : "No")
            continue;
        }

        ll x = 1;
        bool ok = false;
        while(x <= n){
            if((n - x) % b == 0){
                ok = true;
            }
            x *= a;
        }
        print(ok? "Yes" : "No")
    }
    
    return 0;
}