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
    
    ll n, m; cin >> n >> m;
    ll x[m], y[m], z[m]; zep(i, 0, m)cin >> x[i] >> y[i] >> z[i];
    
    vector<vector<P>> v(n + 1);
    zep(i, 0, m)v[x[i]].push_back(P(y[i], z[i]));

    map<ll, ll> mp;
    mp[0] = 1;
    
    rep(i, 1, n){
        map<ll, ll> res;

        for(auto it = mp.begin(); it != mp.end(); it++){
            ll bit = (*it).first;

            zep(j, 0, n){
                if(!(bit & (1LL << j))){
                    ll b = bit | (1LL << j);
                    //print(b)
                    bool ok = true;
                    zep(k, 0, v[i].size()){
                        ll c = __builtin_popcount(b & ((1LL << v[i][k].first) - 1));
                        if(c > v[i][k].second){
                            ok = false;
                            break;
                        }
                    }

                    if(ok){
                        if(res.find(b) == res.end())res[b] = 0;
                        res[b] += (*it).second;
                    }
                }
            }
        }

        mp.swap(res);
    }

    if(mp.find((1LL << n) - 1) == mp.end()){
        print(0)
    }else{
        print(mp[(1LL << n) - 1])
    }
    
    return 0;
}