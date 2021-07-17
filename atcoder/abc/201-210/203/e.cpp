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
    ll x[m], y[m]; zep(i, 0, m)cin >> x[i] >> y[i];

    map<ll, vector<ll>> mp;
    zep(i, 0, m){
        mp[x[i]].push_back(y[i]);
    }
    
    set<ll> s;
    s.insert(n);
    for(auto it = mp.begin(); it != mp.end(); it++){
        auto v = (*it).second;
        sort(v.begin(), v.end());
        
        set<ll> esc;
        zep(i, 0, v.size()){
            if(s.find(v[i]) != s.end()){
                if(i > 0 && v[i - 1] == v[i] - 1){
                    esc.insert(v[i] - 1);
                }

                if(i < v.size() - 1 && v[i + 1] == v[i] + 1){
                    esc.insert(v[i] + 1);
                }

                s.erase(v[i]);
            }
        }

        zep(i, 0, v.size()){
            if(s.find(v[i] - 1) != s.end() || s.find(v[i] + 1) != s.end()){
                esc.insert(v[i]);
            }
        }

        for(auto jt = esc.begin(); jt != esc.end(); jt++){
            s.insert(*jt);
        }
        // print(s.size())
    }

    // if(s.find(-1) != s.end()){
    //     s.erase(-1);
    // }
    print(s.size())

    return 0;
}