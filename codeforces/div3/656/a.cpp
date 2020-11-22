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
        ll x, y, z; cin >> x >> y >> z;

        if(x == y && y == z){
            print("YES")
            cout << x << " " << x << " " << x << endl;
        }else{
            if(x == y && y > z){
                print("YES")
                cout << x << " " << z << " " << z << endl;
            }else if(y == z && z > x){
                print("YES")
                cout << x << " " << x << " " << y << endl;
            }else if(z == x && x > y){
                print("YES")
                cout << y << " " << z << " " << y << endl;
            }else{
                print("NO")
            }
        }
    }
    
    return 0;
}