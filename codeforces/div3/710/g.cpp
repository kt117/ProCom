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

vector<ll> f(vector<ll> v, ll j){
    vector<ll> res;

    bool ok = false;
    zep(i, 0, v.size()){
        if(v[i] != j && ok){
            res.push_back(v[i]);
        }else if(v[i] == j){
            ok = true;
        }
    }
    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        string s; cin >> s;
        ll n = s.size();

        vector<ll> v(n); zep(i, 0, n)v[i] = s[i] - 'a';
        
        ll bit = 0;
        zep(i, 0, n)bit |= (1LL << v[i]);
        
        vector<ll> ans;

        while(bit){
            rrep(j, 25, 0){
                if(bit & (1LL << j)){
                    auto r = f(v, j);

                    ll b = 0;
                    zep(i, 0, r.size())b |= (1LL << r[i]);

                    if(__builtin_popcount(bit - b) == 1){
                        bit = b;
                        v = r;
                        ans.push_back(j);
                        break;
                    }
                }
            }
        }

        zep(i, 0, ans.size())cout << char(ans[i] + 'a'); cout << endl;
    }
    
    return 0;
}