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

    map<ll, set<ll>> mp;
    vector<ll> v;
    zep(i, 0, n){
        ll x, y; cin >> x >> y;

        if(mp.find(x) == mp.end()){
            mp[x] = {};
            v.push_back(x);
        }
        mp[x].insert(y);
    }

    ll ans = 0;
    zep(i, 0, v.size()){
        zep(j, i + 1, v.size()){
            ll cnt = 0;
            for(auto it = mp[v[i]].begin(); it != mp[v[i]].end(); it++){
                if(mp[v[j]].find(*it) != mp[v[j]].end())cnt++;
            }
            ans += cnt * (cnt - 1) / 2;
        }
    }
    
    print(ans)
    // print(mp.size())

    return 0;
}