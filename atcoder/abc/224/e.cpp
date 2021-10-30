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
    
    ll h, w, n; cin >> h >> w >> n;
    vector<vector<ll>> v;
    zep(i, 0, n){
        ll r, c, a; cin >> r >> c >> a;
        r--; c--;
        v.push_back({a, i, r, c});
    }
    sort(v.begin(), v.end());

    vector<ll> bh(h, -1), bw(w, -1), ans(n, 0);
    
    vector<vector<ll>> bbh, bbw;
    rrep(i, n - 1, 0){
        if(i != n - 1 && v[i][0] != v[i + 1][0]){
            while(!bbh.empty()){
                bh[bbh.back()[0]] = max(bh[bbh.back()[0]], ans[bbh.back()[1]]);
                bbh.pop_back();
            }
            while(!bbw.empty()){
                bw[bbw.back()[0]] = max(bw[bbw.back()[0]], ans[bbw.back()[1]]);
                bbw.pop_back();
            }
        }

        ans[v[i][1]] = max(ans[v[i][1]], bh[v[i][2]] + 1);
        ans[v[i][1]] = max(ans[v[i][1]], bw[v[i][3]] + 1);
        
        // bh[v[i][2]] = v[i][1];
        // bw[v[i][3]] = v[i][1];
        bbh.push_back({v[i][2], v[i][1]});
        bbw.push_back({v[i][3], v[i][1]});
    }

    zep(i, 0, n)print(ans[i])
    
    return 0;
}