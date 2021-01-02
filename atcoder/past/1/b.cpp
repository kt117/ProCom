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

    zep(i, 1, n){
        if(a[i] > a[i - 1]){
            cout << "up " << a[i] - a[i - 1] << endl; 
        }else if(a[i] == a[i - 1]){
            cout << "stay" << endl;
        }else{
            cout << "down " << a[i - 1] - a[i] << endl;
        }
    }
    
    return 0;
}