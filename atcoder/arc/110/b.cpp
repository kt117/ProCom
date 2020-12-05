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
    string s; cin >> s;

    ll p = 1e10;
    if(n == 1){
        if(s == "0"){
            print(p)
        }else{
            print(2 * p)
        }
    }else if(n == 2){
        if(s == "00"){
            print(0)
        }else if(s == "01"){
            print(p - 1)
        }else if(s == "10"){
            print(p)
        }else{
            print(p)
        }
    }else{
        if(s[0] == '0'){
            bool ok = true;
            zep(i, 0, n){
                if(i % 3 == 0 && s[i] == '1')ok = false;
                if(i % 3 != 0 && s[i] == '0')ok = false;
            }
            if(ok){
                print(p - (1 + (n - 1 + 2) / 3) + 1)
            }else{
                print(0)
            }
        }else{
            if(s[1] == '0'){
                //print("a")
                bool ok = true;
                zep(i, 0, n){
                    if(i % 3 == 1 && s[i] == '1')ok = false;
                    if(i % 3 != 1 && s[i] == '0')ok = false;
                }
                if(ok){
                    print(p - (1 + (n - 2 + 2) / 3) + 1)
                }else{
                    print(0)
                }
            }else{
                bool ok = true;
                zep(i, 0, n){
                    if(i % 3 == 2 && s[i] == '1')ok = false;
                    if(i % 3 != 2 && s[i] == '0')ok = false;
                }
                if(ok){
                    print(p - (n + 2) / 3 + 1)
                }else{
                    print(0)
                }
            }
        }
    }
    
    return 0;
}