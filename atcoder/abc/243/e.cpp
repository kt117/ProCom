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

ll d[500][500];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;

    ll a[m], b[m], c[m];
    zep(i, 0, m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }
    vector<vector<ll>> v;
    zep(i, 0, m)v.push_back({c[i], a[i], b[i]});
    sort(v.begin(), v.end());

    zep(i, 0, n)zep(j, 0, n)d[i][j] = (i == j)? 0 : INF;
    
    ll ans = m;
    zep(k, 0, m){
        if(d[v[k][1]][v[k][2]] > v[k][0]){
            bool u = false;
            zep(i, 0, n){
                zep(j, 0, n){
                    if(d[i][v[k][1]] + v[k][0] + d[v[k][2]][j] < d[i][j]){
                        u = true;
                        d[i][j] = d[i][v[k][1]] + v[k][0] + d[v[k][2]][j];
                    }
                    if(d[i][v[k][2]] + v[k][0] + d[v[k][1]][j] < d[i][j]){
                        u = true;
                        d[i][j] = d[i][v[k][2]] + v[k][0] + d[v[k][1]][j];
                    }
                }
            }
            if(u)ans--;
        }
    }
    print(ans);

    return 0;
}