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
    ll c[n][n]; zep(i, 0, n)zep(j, 0, n)cin >> c[i][j];

    ll a[n], b[n];
    a[0] = 0;
    zep(j, 0, n){
        b[j] = c[0][j] - a[0];
    }

    zep(i, 1, n){
        a[i] = c[i][0] - b[0];

        zep(j, 1, n){
            if(a[i] + b[j] != c[i][j]){
                print("No") return 0;
            }
        }
    }

    ll mn = 0;
    zep(i, 0, n)if(a[i] < 0)mn = min(mn, a[i]);
    zep(i, 0, n)a[i] -= mn;
    zep(j, 0, n)b[j] += mn;

    mn = 0;
    zep(j, 0, n)if(b[j] < 0)mn = min(mn, b[j]);
    zep(i, 0, n)a[i] += mn;
    zep(j, 0, n)b[j] -= mn;

    zep(i, 0, n){
        if(a[i] < 0){
            print("No") return 0;
        }
    }

    print("Yes")
    printa(a, 0, n - 1)
    printa(b, 0, n - 1)
    
    return 0;
}