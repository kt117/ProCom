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
    string a[2 * n]; zep(i, 0, 2 * n)cin >> a[i];

    vector<P> v;
    zep(i, 0, 2 * n)v.push_back(P(0, i));

    zep(k, 0, m){
        vector<P> u;

        zep(i, 0, n){
            char l = a[v[2 * i].second][k], r = a[v[2 * i + 1].second][k];
            
            if(l == r){
                u.push_back(v[2 * i]);
                u.push_back(v[2 * i + 1]);
            }else if((l == 'G' && r == 'C') || (l == 'C' && r == 'P') || (l == 'P' && r == 'G')){
                u.push_back(P(v[2 * i].first - 1, v[2 * i].second));
                u.push_back(v[2 * i + 1]);
            }else{
                u.push_back(v[2 * i]);
                u.push_back(P(v[2 * i + 1].first - 1, v[2 * i + 1].second));
            }
        }

        sort(u.begin(), u.end());
        v.swap(u);
        // zep(i, 0, 2 * n)cout << - v[i].first << " "; cout << endl;
        // zep(i, 0, 2 * n)cout << v[i].second + 1 << " "; cout << endl;
    }

    zep(i, 0, 2 * n)print(v[i].second + 1)

    return 0;
}