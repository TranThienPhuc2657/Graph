#include <bits/stdc++.h>
using namespace std;
#define file(name) if (fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define ll long long
const ll INF=LLONG_MAX;
const int N=1e6+5;

int n;
string a,b;
map <char,int> m;
vector <ll> d;
vector <pair<char,char>> trace;

ll findSet(int u) {
    return d[u]<0 ?u :d[u]=findSet(d[u]);
}

void unionSet(int u, int v) {
    if (d[u]>d[v]) swap(u,v);
    d[u]+=d[v];
    d[v]=u;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("REPLACE");

    d.resize(26,-2);
    cin >> n >> a >> b;
    ll res=0;
    for (int i=0; i<n; i++) {
        if (d[a[i]-'a']==-2) d[a[i]-'a']=-1;
        if (d[b[i]-'a']==-2) d[b[i]-'a']=-1;
        int u=findSet(a[i]-'a'); int v=findSet(b[i]-'a');
        if (u!=v) {
            unionSet(u,v);
            trace.pb({u+'a',v+'a'});
        }
    }
    cout << trace.size() << "\n";
    for (auto i:trace) cout << i.fi << " " << i.se << "\n";
    return 0;
}
