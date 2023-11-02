#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define fi first
#define se second
using ll=long long;
const int N=1e6+5;

int n,m,u,v,cnt=0,num[N],low[N],cntjoint=0;
set <int> joints; //Danh sach cac khop
vector <int> a[N];
vector <pair<int,int>> bridges; //Danh sach cac cau
map <pair<int,int>,int> edges; //Dem so lan xuat hien cua cac canh cho truong hop da do thi

void dfs(int u, int pre) {
    num[u]=low[u]=++cnt;
    int child=0; //child de dem so con cua mot node
    for (auto v: a[u]) if (v!=pre) if (!num[v]) {
        dfs(v,u);
        low[u]=min(low[u],low[v]);
        //Xet cau: Neu node v khong the len tren duoc nua thi duong di doan u den v la mot cau
        if (low[v]==num[v] and edges[{min(u,v),max(u,v)}]==1) bridges.pb({u,v});
        //Xet khop
        child++;
        if (u==pre) {if(child>=2) joints.insert(u);} //Neu node do la goc thi phai co tu 2 con tro len moi la khop
        else if (low[v]>=num[u]) joints.insert(u); //Nguoc lai neu khong phai la goc thi chi can mot doan khong
                                                   //len tren duoc node u thi node u la khop
    } else low[u]=min(low[u],num[v]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("CUT");

    cin >> n >> m;
    while (m--) {cin >> u >> v; a[u].pb(v); a[v].pb(u); edges[{min(u,v),max(u,v)}]++;}
    FOR(i,1,n) if (!num[i]) dfs(i,i);
    cout << bridges.size() << " " << joints.size() << "\n";
    for (auto i:bridges) cout << i.fi << " " << i.se << "\n";
    for (int i:joints) cout << i << "\n";
    return 0;
}
