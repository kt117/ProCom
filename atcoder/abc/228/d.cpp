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

 const ll n = (1LL << 20);
 ll q, a[n];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> q;
    
    memset(a, -1, sizeof(a));
    set<ll> r;
    while(q--){
        ll t, x; cin >> t >> x;
        ll h = x % n;

        if(t == 1){
            if(a[h] == -1){
                if(a[(h + n - 1) % n] != -1){
                    r.erase((h + n - 1) % n);
                }
            }else{
                auto it = r.lower_bound(h);
                if(it == r.end())r.lower_bound(0);
                h = ((*it) + 1) % n;
                r.erase((*it));
            }

            a[h] = x;
            if(a[(h + 1) % n] == -1){
                r.insert(h);
            }
        }else{
            print(a[h])
        }
    }
    
    return 0;
}