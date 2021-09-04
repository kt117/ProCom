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
    
    ll l, q; cin >> l >> q;

    set<ll> s, t;
    // s.insert(0);
    s.insert(l);
    t.insert(0);
    // t.insert(-l);

    zep(i, 0, q){
        ll c, x; cin >> c >> x;

        if(c == 1){
            s.insert(x);
            t.insert(-x);
        }else{
            print(*s.lower_bound(x) + *t.lower_bound(-x))
        }
    }
    
    return 0;
}