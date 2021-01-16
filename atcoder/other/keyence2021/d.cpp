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

ll n;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    
    vector<vector<ll>> v;
    v.push_back({0, 1});
    ll m = 1;
    rep(i, 2, n){
        m *= 2;
        vector<vector<ll>> u(2 * v.size() + 1, vector<ll>(2 * m, -1));

        zep(j, 0, v.size()){
            zep(k, 0, m / 2){
                u[2 * j][k] = v[j][k];
                u[2 * j + 1][k] = v[j][k];
                u[2 * j][k + m] = v[j][k + m / 2];
                u[2 * j + 1][k + m] = v[j][k + m / 2];
            }
        }

        zep(j, 0, v.size()){
            zep(k, 0, m / 2){
                u[2 * j][k + m / 2] = v[j][k] + m;
                u[2 * j][k + m / 2 + m] = v[j][k + m / 2] + m;
                u[2 * j + 1][k + m / 2] = v[j][k + m / 2] + m;
                u[2 * j + 1][k + m / 2 + m] = v[j][k] + m;
            }
        }

        zep(k, 0, 2 * m){
            u[2 * v.size()][k] = k;
        }

        v.swap(u);
    }

    print(v.size())
    bool ans[v.size()][2 * m]; memset(ans, 0, sizeof(ans));
    zep(i, 0, v.size()){
        zep(j, 0, m){
            ans[i][v[i][j]] = true;
        }

        zep(j, 0, 2 * m)cout << ((ans[i][j])? 'A' : 'B'); cout << endl;
    }

    return 0;
}