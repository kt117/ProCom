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
        ll n, m; cin >> n >> m;
        ll r[m], c[m]; zep(i, 0, m)cin >> r[i] >> c[i];

        vector<P> v;
        zep(i, 0, m)v.push_back(P(c[i], r[i]));
        sort(v.begin(), v.end());

        if(m % 2 == 1){
            print("NO") continue;
        }

        bool ok = true;
        zep(i, 0, m / 2){
            ll x = 2 * i;

            if(v[x].first != v[x + 1].first){
                if(i != m / 2 - 1 && v[x + 1].first == v[x + 2].first){
                    ok = false;
                }else{
                    if(v[x].second == v[x + 1].second){
                        if((v[x + 1].first - v[x].first) % 2 == 0){
                            ok = false;
                        }
                    }else{
                        if((v[x + 1].first - v[x].first) % 2 == 1){
                            ok = false;
                        }
                    }
                }
            }
        }
        print(ok? "YES" : "NO")
    }
    
    return 0;
}