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
        vector<vector<ll>> v;
        zep(i, 0, n){
            ll l, r; cin >> l >> r;
            v.push_back({l, 0, i});
            v.push_back({r, 1, i});
        }
        sort(v.begin(), v.end());

        ll cnt[2] = {0, 0};
        ll cntt[n][2]; memset(cntt, 0, sizeof(cntt));

        vector<vector<ll>> u;
        zep(i, 0, v.size()){
            if(!u.empty() && u[0][0] != v[i][0]){
                zep(j, 0, u.size())if(u[j][1] == 0)cnt[0]++;
                zep(j, 0, u.size())cntt[u[j][2]][u[j][1]] = cnt[1 - u[j][1]];
                zep(j, 0, u.size())if(u[j][1] == 1)cnt[1]++;
                u.clear();
            }

            u.push_back(v[i]);
        }

        zep(j, 0, u.size())if(u[j][1] == 0)cnt[0]++;
        zep(j, 0, u.size())cntt[u[j][2]][u[j][1]] = cnt[1 - u[j][1]];
        zep(j, 0, u.size())if(u[j][1] == 1)cnt[1]++;
        u.clear();

        ll ans = INF;
        zep(i, 0, n){
            ans = min(ans, cntt[i][0] + n - cntt[i][1]);
        }
        print(ans)
    }
    
    return 0;
}