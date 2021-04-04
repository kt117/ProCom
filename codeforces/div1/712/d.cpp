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
    ll a[n], b[n]; zep(i, 0, n)cin >> a[i] >> b[i];

    vector<vector<ll>> c(n);
    bool f[n]; memset(f, 0, sizeof(f));

    zep(i, 0, n){
        if(a[i] < b[i]){
            c[i] = {a[i], b[i], i};
        }else{
            c[i] = {b[i], a[i], i};
            f[i] = true;
        }
    }

    sort(c.begin(), c.end());
    
    set<ll> unuse, runuse;
    rep(i, 1, 2 * n)unuse.insert(i);
    rep(i, 1, 2 * n)runuse.insert(-i);

    P o[n];
    ll l = 0, r = n;
    bool ok[n]; memset(ok, 0, sizeof(ok));
    zep(i, 0, n){
        unuse.erase(c[i][0]);
        unuse.erase(c[i][1]);
        runuse.erase(-c[i][0]);
        runuse.erase(-c[i][1]);

        if(unuse.lower_bound(c[i][1]) == unuse.end() && runuse.lower_bound(-c[i][0]) == runuse.end()){
            ok[c[i][2]] = true;
            o[l] = P(c[i][0], c[i][1]);
            l++;
        }else if(unuse.lower_bound(c[i][1]) == unuse.end()){
            o[l] = P(c[i][0], c[i][1]);
            l++;
        }else{
            if(r < n - 1 && c[i][1] > o[r].first){
                print(-1) return 0;
            }
            r--;
            o[r] = P(c[i][1], c[i][0]);
            f[c[i][2]] = !f[c[i][2]];
        }
    }


    ll ansl = 0, ansr = 0;
    zep(i, 0, n)if(f[i] && !ok[i])ansl++;
    zep(i, 0, n)if(!f[i] && !ok[i])ansr++;
    print(min(ansl, ansr))
    
   
    return 0;
}