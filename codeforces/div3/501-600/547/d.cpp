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
    string l, r; cin >> l >> r;

    vector<vector<ll>> u(27);
    vector<vector<ll>> v(27);

    zep(i, 0, n){
        ll x = (l[i] == '?')? 26 : l[i] - 'a';
        u[x].push_back(i);
    }

    zep(i, 0, n){
        ll x = (r[i] == '?')? 26 : r[i] - 'a';
        v[x].push_back(i);
    }
    
    vector<P> ans;
    zep(j, 0, 26){
        while(!u[j].empty() && !v[j].empty()){
            ans.push_back(P(u[j].back(), v[j].back()));
            u[j].pop_back();
            v[j].pop_back();
        }
    }

    zep(j, 1, 26){
        zep(k, 0, u[j].size())u[0].push_back(u[j][k]);
        zep(k, 0, v[j].size())v[0].push_back(v[j][k]);
    }

    while(!u[0].empty() && !v[26].empty()){
        ans.push_back(P(u[0].back(), v[26].back()));
        u[0].pop_back();
        v[26].pop_back();
    }

    while(!u[26].empty() && !v[0].empty()){
        ans.push_back(P(u[26].back(), v[0].back()));
        u[26].pop_back();
        v[0].pop_back();
    }

    while(!u[26].empty() && !v[26].empty()){
        ans.push_back(P(u[26].back(), v[26].back()));
        u[26].pop_back();
        v[26].pop_back();
    }

    print(ans.size())
    zep(i, 0, ans.size())cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;

    return 0;
}