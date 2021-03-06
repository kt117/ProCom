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
        string s; cin >> s;

        bool ans = true;
        vector<char> a(n), b(n);
        ll cnta = 0, cntb = 0;
        zep(i, 0, n){
            if(s[i] == '1'){
                if((cnta > 1 && cntb > 0) || (cnta > 0 && cntb > 1) || i == n - 1){
                    a[i] = ')';
                    b[i] = ')';
                    cnta--;
                    cntb--;
                }else{
                    a[i] = '(';
                    b[i] = '(';
                    cnta++;
                    cntb++;
                }
            }else{
                if(cnta >= cntb){
                    a[i] = ')';
                    b[i] = '(';
                    cnta--;
                    cntb++;
                }else{
                    a[i] = '(';
                    b[i] = ')';
                    cnta++;
                    cntb--;
                }
            }

            if(cnta < 0 || cntb < 0){
                ans = false;
            }
        }

        if(ans && cnta == 0 && cntb == 0){
            print("YES")
            zep(i, 0, n)cout << a[i]; cout << endl;
            zep(i, 0, n)cout << b[i]; cout << endl;
        }else{
            print("NO")
        }
    }
    
    return 0;
}