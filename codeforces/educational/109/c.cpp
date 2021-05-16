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
        ll x[n]; zep(i, 0, n)cin >> x[i];
        char d[n]; zep(i, 0, n)cin >> d[i];

        P p[n]; zep(i, 0, n)p[i] = P(x[i], i);
        sort(p, p + n);

        ll ans[n]; memset(ans, -1, sizeof(ans));
        vector<vector<ll>> v(2);

        zep(i, 0, n){
            if(v[p[i].first % 2].empty() || d[p[i].second] == 'R'){
                v[p[i].first % 2].push_back(p[i].second);
            }else{
                ll j = v[p[i].first % 2].back();
                v[p[i].first % 2].pop_back();
                
                if(d[j] == 'L'){
                    ans[p[i].second] = ans[j] = (p[i].first + x[j]) / 2;
                }else{
                    ans[p[i].second] = ans[j] = (p[i].first - x[j]) / 2;
                }
            }
        }

        zep(k, 0, 2){
            while(v[k].size() >= 2){
                ll i = v[k].back(); v[k].pop_back();
                ll j = v[k].back(); v[k].pop_back();

                if(d[j] == 'L'){
                    ans[i] = ans[j] = (2 * m - x[i] + x[j]) / 2;
                }else{
                    ans[i] = ans[j] = (2 * m - x[i] - x[j]) / 2;
                }
            }
        }

        printa(ans, 0, n - 1)
    }
    
    return 0;
}