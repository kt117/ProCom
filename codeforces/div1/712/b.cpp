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

    vector<P> u[2];
    zep(i, 0, n){
        zep(j, 0, n){
            u[(i + j) % 2].push_back(P(i, j));
        }
    }
    zep(i, 0, n * n){
        ll a; cin >> a;

        if(a == 1){
            if(!u[0].empty()){
                cout << 2 << " " << u[0].back().first + 1 << " " << u[0].back().second + 1 << endl << flush;
                u[0].pop_back();
            }else{
                cout << 3 << " " << u[1].back().first + 1 << " " << u[1].back().second + 1 << endl << flush;
                u[1].pop_back();
            }
        }else if(a == 2){
            if(!u[1].empty()){
                cout << 1 << " " << u[1].back().first + 1 << " " << u[1].back().second + 1 << endl << flush;
                u[1].pop_back();
            }else{
                cout << 3 << " " << u[0].back().first + 1 << " " << u[0].back().second + 1 << endl << flush;
                u[0].pop_back();
            }
        }else{
            if(!u[0].empty()){
                cout << 2 << " " << u[0].back().first + 1 << " " << u[0].back().second + 1 << endl << flush;
                u[0].pop_back();
            }else{
                cout << 1 << " " << u[1].back().first + 1 << " " << u[1].back().second + 1 << endl << flush;
                u[1].pop_back();
            }
        }
    }
    
    return 0;
}