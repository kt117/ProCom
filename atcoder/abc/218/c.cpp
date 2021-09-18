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

vector<P> u, v;

void kaiten(){
    zep(i, 0, v.size()){
        v[i] = P(v[i].second, - v[i].first);
    }
    sort(v.begin(), v.end());
}

bool f(){
    zep(i, 0, u.size()){
        if(u[i].first - v[i].first != u[0].first - v[0].first)return false;
        if(u[i].second - v[i].second != u[0].second - v[0].second)return false;
    }
    return true;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    string s[n], t[n]; 
    zep(i, 0, n)cin >> s[i];
    zep(i, 0, n)cin >> t[i];

    zep(i, 0, n){
        zep(j, 0, n){
            if(s[i][j] == '#')u.push_back(P(i, j));
            if(t[i][j] == '#')v.push_back(P(i, j));
        }
    }

    if(u.size() != v.size()){
        print("No") return 0;
    }

    zep(k, 0, 4){
        if(f()){
            print("Yes") return 0;
        }

        kaiten();
    }

    print("No")
    
    return 0;
}