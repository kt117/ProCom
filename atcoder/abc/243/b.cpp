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
    ll a[n], b[n];
    zep(i, 0, n)cin >> a[i];
    zep(i, 0, n)cin >> b[i];

    ll x = 0, y = 0;
    set<ll> s;
    zep(i, 0, n)s.insert(a[i]);

    zep(i, 0, n){
        if(b[i] == a[i]){
            x++;
        }else if(s.find(b[i]) != s.end()){
            y++;
        }
    }
    print(x)
    print(y)
    
    return 0;
}