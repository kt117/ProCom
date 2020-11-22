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

bool f(ll a, ll b, ll c, ll d){
    if(a + b == c + d)return true;
    if(a - b == c - d)return true;
    if(abs(a - c) + abs(b - d) <= 3)return true;
    return false;
}

bool g(ll a, ll b, ll c, ll d){
    for(ll i = -3; i <= 3; i++){
        for(ll j = -3; j <= 3; j++){
            if(abs(i) + abs(j) <= 3){
                if(a + i + b + j == c + d)return true;
                if(a + i - b - j == c - d)return true;
            }
        }
    }

    return false;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

    if(r1 == r2 && c1 == c2){
        print(0) return 0;
    }

    if(f(r1, c1, r2, c2)){
        print(1) return 0;
    }

    if((r1 + c1) % 2 == (r2 + c2) % 2){
        print(2) return 0;
    }

    if(g(r1, c1, r2, c2)){
        print(2) return 0;
    }
    print(3)
    
    return 0;
}