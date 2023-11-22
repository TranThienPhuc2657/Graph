#include <bits/stdc++.h>
using namespace std;
#define file(name) if (fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define REP(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define ll long long
const ll INF=LLONG_MAX;
const int N=2e5+5;

struct Edge{
    int v;
    ll w;
};
struct Node{
    int u;
    ll du;
};
struct comp{
    bool operator() (Node a, Node b) {
        return a.du>b.du;
    }
};
int n,m,k,s,t;
vector <Edge> a[N];
vector <ll> d;
vector <bool> check;

void dijkstra() {
    priority_queue <Node,vector<Node>,comp> h;
    h.push({s,d[s]});
    while (!h.empty()) {
        int u=h.top().u;
        h.pop();
        if (check[u]) continue;
        check[u]=true;
        for (auto e:a[u]) {
            int v=e.v;
            ll w=e.w;
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                h.push({v,d[v]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("TRANSNET");

    cin >> n >> m >> k >> s >> t;
    d.resize(2*n+1,INF); d[s]=0;
    check.resize(2*n+1,false);
    int u,v; ll w;
    REP(i,m) {cin >> u >> v >> w; a[u].pb({v,w}); a[u+n].pb({v+n,w});} //Thêm cạnh u+n -> v+n tại vì đang dupe cái đồ thị gốc
    REP(i,k) {cin >> u >> v >> w; a[u].pb({v+n,w}); a[v].pb({u+n,w});}
    dijkstra();
    ll res=min(d[t],d[t+n]);
    if (res==INF) cout << -1;
    else cout << res;
    return 0;
}

//Bài này là một bài khá khó to be honest
//Ý tường của bài này như sau
//Ta sẽ duplicate đồ thị của ta ra
//Cái đầu tiên là đồ thị gốc (đánh thứ tự từ 1 -> n)
//Và cái thứ hai là đồ thị để cho các đường đi thêm, có sự can thiệp của đường đi thêm (đánh thứ tự từ n+1 -> 2n)
//Với mỗi đường đi thêm {u,v,ư} ta sẽ thêm hai cạnh (Do hai chiều):
//Cạnh 1: u -> v+n với trọng số w
//Cạnh 2: v -> u+n với trọng số w
//Ta cũng có thể đặt điểm a+n thành a' cho dễ hiểu, ta viết lại:
//Cạnh 1: u -> v' với trọng số w
//Cạnh 2: v -> u' với trọng số w
//Khi ta biểu diễn đồ thị thì các cạnh thêm chỉ có nối từ một điểm trên đồ thị gốc tới một điểm trên đồ thị thêm
//Và không từ một điểm trên đồ thị thêm tới một điểm trên đồ thị thêm
//Cho nên đường đi ngắn nhất tới a' thì chỉ qua ít nhất một đường nối thêm
//Chứng minh:
//Nếu nó qua hai đường nối thêm thì:
//- Phải có một đường nối thêm từ đồ thị thêm về đồ thị gốc
//- Hoặc một đường nối thêm trên đồ thị thêm
//Nhưng ta chỉ có đường nối thêm từ đồ thị gốc tới đồ thị thêm nên => đpcm
//Nhưng chưa chắc các đường nối thêm đó tối ưu hơn cái đường chính
//Nên kết quả ta cần in ra là min( d[t], d[t']) hay min( d[t], d[t+n])
