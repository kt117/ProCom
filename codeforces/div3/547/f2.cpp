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
    ll a[n + 1]; rep(i, 1, n)cin >> a[i];
    a[0] = 0;
    rep(i, 1, n)a[i] += a[i - 1];

    map<ll, vector<P>> mp;

    rep(i, 1, n){
        rep(j, i, n){
            ll x = a[j] - a[i - 1];

            if(mp.find(x) == mp.end())mp[x] = {};
            mp[x].push_back(P(j, i));
        }
    }

    vector<P> ans;
    for(auto it = mp.begin(); it != mp.end(); it++){
        vector<P> u;
        
        auto v = (*it).second;
        sort(v.begin(), v.end());

        ll r = -1;
        zep(i, 0, v.size()){
            if(v[i].second > r){
                u.push_back(P(v[i].second, v[i].first));
                r = v[i].first;
            }
        }

        if(u.size() > ans.size())ans.swap(u);
    }

    print(ans.size())
    zep(i, 0, ans.size())cout << ans[i].first << " " << ans[i].second << endl;
    
    return 0;
}