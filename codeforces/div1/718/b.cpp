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
        ll n, m; cin >> n >> m;
        ll b[n][m]; zep(i, 0, n)zep(j, 0, m)cin >> b[i][j];

        vector<vector<ll>> v;
        zep(i, 0, n)zep(j, 0, m)v.push_back({b[i][j], i, j});
        sort(v.begin(), v.end());

        bool use[n][m]; memset(use, 0, sizeof(use));
        zep(j, 0, m)use[v[j][1]][v[j][2]] = true;
        //zep(j, 0, m)print(v[j][0])
        ll ans[n][m]; memset(ans, -1, sizeof(ans));
        ll at = 0;
        zep(i, 0, n){
            zep(j, 0, m){
                if(use[i][j]){
                    //cout << i << " " << j << endl;
                    ans[i][at] = b[i][j];
                    at++;
                }
            }
            
            ll att = 0;
            zep(j, 0, m){
                if(!use[i][j]){
                    while(ans[i][att] != -1)att++;
                    ans[i][att] = b[i][j];
                }
            }
        } 
        
        zep(i, 0, n){
            zep(j, 0, m)cout << ans[i][j] << " "; cout << endl;
        }
    }
    
    return 0;
}