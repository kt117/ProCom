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
    
    ll n; cin >> n;
    ll ans = 1;
    bool use[12]; memset(use, 0, sizeof(use));
    
    rep(i, 1, 11){
        ll x = n - i;
        rrep(j, 11, 1){
            if(!use[j] && x % j == 0){
                use[j] = true;
                x /= j;
            }
        }
        ans *= x;
        //printa(use, 1, 11)
        //print(ans)
    }
    rrep(j, 11, 1){
        if(!use[j] && ans % j == 0){
            use[j] = true;
            ans /= j;
        }
    }
    print(ans)
    
    return 0;
}