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

ll a[6], b[6];

void m1(){
    rep(i, 1, 5){
        ll x = min(a[i], b[i]);
        a[i] -= x;
        b[i] -= x;
    }
}

bool c(){
    rep(i, 1, 5)if(a[i] > 0)return false;
    return true;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    
    while(t--){  
        rep(i, 1, 5)cin >> a[i];
        rep(i, 1, 5)cin >> b[i];

        m1();

        if(a[5] > 0){print("No") continue;}

        ll x1 = min(a[2], b[3]);
        a[2] -= x1;
        b[3] -= x1;
        b[1] += x1;

        ll x2 = min(a[1], b[2]);
        a[1] -= x2;
        b[2] -= x2;
        b[1] += x2;

        ll x3 = min(a[4], b[5]);
        a[4] -= x3;
        b[5] -= x3;
        b[1] += x3;

        m1();

        ll x4 = min(a[3], b[5]);
        a[3] -= x4;
        b[5] -= x4;
        b[2] += x4;

        ll x5 = min(a[3], b[4]);
        a[3] -= x5;
        b[4] -= x5;
        b[1] += x5;

        m1();

        rrep(i, 5, 2){
            ll x6 = min(a[2], b[i]);
            a[2] -= x6;
            b[i] -= x6;
            b[i - 2] += x6;
        }

        rrep(i, 5, 1){
            ll x7 = min(a[1], b[i]);
            a[1] -= x7;
            b[i] -= x7;
            b[i - 1] += x7;
        }

        print(c()? "Yes" : "No")
    }
    
    return 0;
}