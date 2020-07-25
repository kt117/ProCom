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
    ll a[n]; zep(i, 0, n)cin >> a[i];

    sort(a, a + n);
    ll x = a[n - 1];

    ll y = -1;
    set<ll> use;
    rrep(i, n - 1, 0){
        if(x % a[i] == 0){
            if(use.find(a[i]) == use.end()){
                use.insert(a[i]);
            }else{
                y = a[i];
            }
        }else{
            y = a[i];
        }
        if(y != -1)break;
    }
    cout << x  << " " << y << endl;

    return 0;
}