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
    
    ll k;
    string a, b; cin >> k >> a >> b;

    ll aa = 0, bb = 0;
    zep(i, 0, a.size()){
        aa += pow(k, i) * (a[a.size() - 1 - i] - '0');
    }
    zep(i, 0, b.size()){
        bb += pow(k, i) * (b[b.size() - 1 - i] - '0');
    }
    print(aa * bb)
    
    return 0;
}