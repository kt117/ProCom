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
        ll n; cin >> n;
        ll p[2 * n]; zep(i, 0, 2 * n)cin >> p[i];

        vector<ll> a, b;
        a.push_back(INF + 1);
        b.push_back(INF);

        bool ok = true;
        rrep(i, 2 * n - 1, 0){
            if(p[i] < a.back() && p[i] < b.back()){
                if(a.back() < b.back()){
                    a.push_back(p[i]);
                }else{
                    b.push_back(p[i]);
                }
            }else if(p[i] < a.back() && p[i] > b.back()){
                a.push_back(p[i]);
            }else if(p[i] > a.back() && p[i] < b.back()){
                b.push_back(p[i]);
            }else{
                ok = false;
                break;
            }
        }
    }
    
    return 0;
}