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

ll n;
vector<set<ll>> L, R;
vector<vector<ll>> ylr, qxy;


// bool ok(ll i, ll j, ll x, ll y){
//     if(xy[i][j].first == xy[i][j + 1].first)return false;

//     ll l = min(xy[i][j].first, xy[i][j + 1].first);
//     ll r = max(xy[i][j].first, xy[i][j + 1].first);
//     ll Y = xy[i][j].second;

//     if(Y > y)return false;
//     if(x < l || r <= x)return false;
//     return true;
// }

// ll cnt(ll i, ll x, ll y){
//     ll res = 0;
//     zep(j, 0, m[i]){
//         if(ok(i, j, x, y))res++;
//     }
//     return res;
// }

ll cal(ll i){
    ll qx = qxy[i][1];
    ll qy = qxy[i][0];
    ll qi = qxy[i][2];

    while(!ylr.empty() && ylr.back()[0] <= qy){
        auto v = ylr.back();
        ylr.pop_back();

        L[v[3]].insert(v[1]);
        R[v[3]].insert(v[2]);
    }

    
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    L.resize(n);
    R.resize(n);

    zep(i, 0, n){
        ll m; cin >> m;
        
        vector<P> v;
        zep(j, 0, m){
            ll x, y; cin >> x >> y;
            v.push_back(P(x, y));
        }
        v.push_back(v.front());

        zep(j, 0, m){
            if(v[j].first == v[j + 1].first)continue;

            ll l = min(v[j].first, v[j + 1].first);
            ll r = max(v[j].first, v[j + 1].first);
            ll y = v[j].second;

            ylr.push_back({y, l, r, i});
        }
    }

    sort(ylr.begin(), ylr.end(), greater<>());

    ll q; cin >> q;
    zep(i, 0, q){
        ll x, y; cin >> x >> y;
        qxy.push_back({y, x, i});
    }

    sort(qxy.begin(), qxy.end());
    
    zep(i, 0, q){
        cal(i);
    }

    return 0;
}