#include <bits/stdc++.h>
using namespace std;
#define file(name) if (fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define fi first
#define se second
const int N=2e5+5;

int n,m,u,v,cnt=0,num[N],low[N],bridge=0;
vector <int> a[N];
set <int> check[N];

void dfs(int u,int pre) {
    num[u]=low[u]=++cnt;
    for (auto v:a[u]) {
        if (v==pre) continue;
        if (!num[v]) {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]==num[v] and check[u].find(v)==check[u].end()) bridge++;
        } else low[u]=min(low[u],num[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("BRIDTOUR");
    /*
    Y tuong o day la cho them cai cau can tham quan thi cac canh can di qua se lien thong manh voi cai canh do
    Vay cac canh chua tham se la cac cau cua do thi
    Vay chi can cho het m tour tham quan vao do thi ban dau thi canh cau cua do thi moi se la canh chua tham
    */
    cin >> n;
    for (int i=0; i<n-1; i++) {cin >> u >> v; a[u].pb(v); a[v].pb(u);}
    cin >> m;
    for (int i=0; i<m; i++) {cin >> u >> v; a[u].pb(v); a[v].pb(u); check[min(u,v)].insert(max(u,v));}
    for (int i=1; i<=n; i++) if (!num[i]) dfs(i,i);
    cout << bridge;
    return 0;
}
