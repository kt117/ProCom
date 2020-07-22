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

long long gcd(long long a, long long b){return (b == 0)? a : gcd(b, a % b);}

struct Point{
    ll x, y;
    Point(ll x=0, ll y=0) : x(x), y(y) {}
};

struct Line{
    ll a, b, c;
    Line(Point p=Point(), Point q=Point()){
        a = p.y - q.y;
        b = -(p.x - q.x);
        c = -(a * p.x + b * p.y);
    }
};

pair<bool, Point> intersection(Line l, Line m){
    bool ok = (((l.b * m.c - m.b * l.c) % (l.a * m.b - m.a * l.b) == 0) && ((m.a * l.c - l.a * m.c) % (l.a * m.b - m.a * l.b) == 0));
    return make_pair(ok, Point((l.b * m.c - m.b * l.c) / (l.a * m.b - m.a * l.b), (m.a * l.c - l.a * m.c) / (l.a * m.b - m.a * l.b)));
}

bool on(Point p, Point a, Point b){
    if((a.x <= p.x && p.x <= b.x) || (b.x <= p.x && p.x <= a.x)){
        if((a.y <= p.y && p.y <= b.y) || (b.y <= p.y && p.y <= a.y)){
            return true;
        }
    }
    return false;
}

ll f(ll x){
    if(x == 1)return 2;

    ll res = 3;
    while(res * (res - 1) / 2 != x){
        res++;
    }
    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    Point a[n], b[n];

    zep(i, 0, n){
        cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
    }
    
    ll ans = 0;
    zep(i, 0, n){
        ans += gcd(abs(a[i].x - b[i].x), abs(a[i].y - b[i].y)) + 1;
    }

    map<P, ll> mp;
    zep(i, 0, n){
        zep(j, 0, i){
            Line l = Line(a[i], b[i]);
            Line m = Line(a[j], b[j]);

            if(l.a * m.b - m.a * l.b != 0){
                auto res = intersection(l, m);
                Point p = res.second;

                if(res.first){
                    if(on(p, a[i], b[i]) && on(p, a[j], b[j])){
                        auto c = P(p.x, p.y);
                        if(mp.find(c) == mp.end())mp[c] = 0;
                        mp[c]++;
                    }
                }
            }
        }
    }

    for(auto it = mp.begin(); it != mp.end(); it++){
        ans -= f((*it).second) - 1;
    }
    print(ans)

    return 0;
}