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
    
    ll n, l; cin >> n >> l;
    
    ll x = l;
    while(pow(3, x - 1) >= n)x--;
    
    vector<vector<ll>> ans(n);
    zep(i, 0, n){
        ll y = i;
        zep(j, 0, x){
            ans[i].push_back(y % 3);
            y /= 3;
        }
        reverse(ans[i].begin(), ans[i].end());
    }

    zep(k, 0, 3){
        zep(i, 0, n){
            cout << k;
            zep(j, 0, l - x - 1)cout << (k + 1) % 3;
            zep(j, 0, x)cout << (ans[i][j] + k + 1) % 3;
            cout << endl;
        }
    }
    
    return 0;
}