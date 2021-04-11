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

ll n;

ll f(ll sme, ll smo, ll mxe, ll mxo, ll cnte, ll cnto){
    //cout << sme << " " << smo << " " << mxe << " " << mxo << " " << cnte << " " << cnto << endl;
    return sme + mxe * (n - cnte) + smo + mxo * (n - cnto);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        cin >> n;
        ll c[n]; zep(i, 0, n)cin >> c[i];

        ll sme = c[0], smo = c[1];
        ll mxe = c[0], mxo = c[1];
        ll cnte = 1, cnto = 1;
        ll ans = f(sme, smo, mxe, mxo, cnte, cnto);
        zep(i, 2, n){
            //print(ans)
            if(i % 2){
                smo += c[i];
                mxo = min(mxo, c[i]);
                cnto++;
            }else{
                sme += c[i];
                mxe = min(mxe, c[i]);
                cnte++;
                //print(mxe)
            }

            ans = min(ans, f(sme, smo, mxe, mxo, cnte, cnto));
        }
        print(ans)
    }
    
    return 0;
}