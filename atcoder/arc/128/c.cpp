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

ll n, m, s, a[5000];
double sm, ans;

void f(ll r){
    ll cum = 0, bcum = 0, bl = 1;
    rrep(i, r - 1, 0){
        cum += a[i];
        if(cum * bl > (r - i) * bcum){
            bcum = cum;
            bl = r - i;
        }
    }

    if(sm <= m * bl){
        ans += bcum * (sm / bl);
    }else{
        ans += bcum * m;
        sm -= m * bl;
        f(r - bl);
    }
}


int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m >> s;
    zep(i, 0, n)cin >> a[i];

    sm = s;
    f(n);
    cout << fixed << setprecision(20) << ans << endl;
    
    return 0;
}