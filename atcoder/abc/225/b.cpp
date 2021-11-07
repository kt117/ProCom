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
    ll count[n]; memset(count, 0, sizeof(count));

    zep(i, 0, n - 1){
        ll a, b; cin >> a >> b; a--; b--;
        count[a]++;
        count[b]++;
    }

    zep(i, 0, n){
        if(count[i] == n - 1){
            print("Yes") return 0;
        }
    }
    print("No")
    
    return 0;
}