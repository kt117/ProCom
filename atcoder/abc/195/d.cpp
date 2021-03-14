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
    
    ll n, m, q; cin >> n >> m >> q;
    ll w[n], v[n]; zep(i, 0, n)cin >> w[i] >> v[i];
    
    P vw[n]; zep(i, 0, n)vw[i] = P(v[i], w[i]);
    sort(vw, vw + n, greater<>());

    ll x[m]; zep(j, 0, m)cin >> x[j];
    while(q--){
        ll l, r; cin >> l >> r; l--;
        map<ll, ll> b;
        zep(j, 0, m){
            if(j < l || r <= j){
                if(b.find(x[j]) == b.end()){
                    b[x[j]] = 0;
                }
                b[x[j]]++;
            }
        }
        //print(b.size())

        ll ans = 0;
        zep(i, 0, n){
            auto it = b.lower_bound(vw[i].second);
            if(it != b.end()){
                ll y = (*it).first;
                ans += vw[i].first;
                b[y]--;
                if(b[y] == 0){
                    b.erase(y);
                }
            }
        }
        print(ans)
    }
    
    return 0;
}