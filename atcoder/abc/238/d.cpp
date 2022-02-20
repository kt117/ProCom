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
        ll a, s; cin >> a >> s;

        if(2 * a > s){print("No") continue;}

        zep(i, 0, 60){
            if((1LL << i) & a){
                s -= 2 * (1LL << i);
            }
        }

        bool ok = true;
        zep(i, 0, 60){
            if(((1LL << i) & s) && ((1LL << i) & a))ok = false;
        }
        print(ok? "Yes" : "No")
    }
    
    return 0;
}