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
    
    ll a, b, c; cin >> a >> b >> c;

    if(c % 2 == 0){
        a = abs(a);
        b = abs(b);

        if(a < b){
            print("<")
        }else if(a == b){
            print("=")
        }else{
            print(">")
        }
    }else{
        if(a < 0){
            if(b < 0){
                if(a < b){
                    print("<")
                }else if(a == b){
                    print("=")
                }else{
                    print(">")
                }
            }else{
                print("<")
            }
        }else{
            if(b < 0){
                print(">")
            }else{
                if(a < b){
                    print("<")
                }else if(a == b){
                    print("=")
                }else{
                    print(">")
                }
            }
        }
    }
    
    return 0;
}