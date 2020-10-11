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
    
    ll a[4]; zep(i, 0, 4)cin >> a[i];
    
    ll sm = 0;
    zep(i, 0, 4)sm += a[i];
    
    zep(i, 0, 4){
        if(sm - a[i] == a[i]){
            print("Yes") return 0;
        }
    }

    zep(i, 0, 4){
        zep(j, i + 1, 4){
            if(sm - a[i] - a[j] == a[i] + a[j]){
                print("Yes") return 0;
            }
        }
    }
    print("No")

    return 0;
}