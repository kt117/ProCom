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
    string s; cin >> s;
    ll a[n + 1]; rep(i, 0, n)cin >> a[i];

    ll k = INF;
    zep(i, 0, n)k = min(k, abs(a[i] - a[i + 1]));

    print(k)
    zep(j, 0, k){
        rep(i, 0, n){
            if(j < a[i] % k){
                cout << (a[i] + k - 1) / k << " ";
            }else{
                cout << a[i] / k << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}