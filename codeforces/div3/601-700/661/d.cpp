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
        string s; cin >> s;

        vector<ll> v[2];

        vector<ll> ans(n);
        zep(i, 0, n){
            ll x = s[i] - '0';

            if(v[1 - x].empty()){
                v[x].push_back(v[x].size() + 1);
            }else{
                v[x].push_back(v[1 - x].back());
                v[1 - x].pop_back();
            }
            ans[i] = v[x].back();
        }

        print(v[0].size() + v[1].size())
        printa(ans, 0, n - 1)
    }
    
    return 0;
}