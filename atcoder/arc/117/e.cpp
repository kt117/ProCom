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

map<string, string> dp;

string f(string s){
    if(dp.find(s) != dp.end())return dp[s];
    ll m = s.size();
    if(m > 10){
        string res;
        zep(i, 0, m - 10 + 1)res += f(s.substr(i, 10));
        return f(res);
    }
    return dp[s] = f(f(s.substr(0, m - 1)) + f(s.substr(1, m - 1)));
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    dp["BB"] = "B";
    dp["BW"] = "R";
    dp["BR"] = "W";
    dp["WB"] = "R";
    dp["WW"] = "W";
    dp["WR"] = "B";
    dp["RB"] = "W";
    dp["RW"] = "B";
    dp["RR"] = "R";

    ll n; cin >> n;
    string s; cin >> s;

    print(f(s))
    
    return 0;
}