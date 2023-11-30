#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define ll long long
#define vi vector <int>
#define vll vector <ll>
const ll INF=LLONG_MAX;
const int N=1e6+5;

int n,m,u,v;
vi a[N],t,parent;
bool check[N]; //Mảng check để xét xem điểm đó có mở cửa hay không
stack <string> res;

int findSet(int u) {
    return parent[u]<0 ?u :parent[u]=findSet(parent[u]);
}

void unionSet(int u, int v) {
    if (parent[u]>parent[v]) swap(u,v);
    parent[u]+=parent[v];
    parent[v]=u;
}

void DSU(int u, int v) {
    int s=findSet(u); int r=findSet(v);
    if (s!=r) unionSet(s,r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("CFARM");

    cin >> n >> m;
    parent.resize(n+1,-1);
    REP(i,m) {cin >> u >> v; a[u].pb(v); a[v].pb(u);}
    int test;
    REP(i,n) {cin >> test; t.pb(test);}
    reverse(t.begin(),t.end());
    REP(u,t.size()) {
        check[t[u]]=true;
        for (auto v:a[t[u]])
            if (check[v]) DSU(t[u],v);
        res.push((parent[findSet(t[u])]==-u-1?"YES":"NO"));
    }
    while (!res.empty()) {cout << res.top() << "\n"; res.pop();}
    return 0;
}
//Ý tưởng bài này là mình sẽ DSU ngược lên.
//Cứ mỗi điểm mình lấy vô thì nó sẽ đóng cửa trang trại
//Thì khi cái điểm cuối cùng lấy vô thì sẽ không còn trang trại nào
//Trước khi đóng cửa cái điểm cuối cùng đó thì chỉ có điểm đó mở cửa
//Thì ta sẽ xét tính liên thông của cái điểm cuối cùng đó thì
//sẽ ra tính liên thông sau khi đóng cửa điểm trước đó
//Ta rút ra kết luận là tính liên thông sau khi đóng cửa điểm u bất kì
//Sẽ là tính liên thông của các đỉnh v sau đỉnh u mà chưa đóng cửa
//Tức là DSU(các đỉnh v sau u chưa đóng cửa)
//Như vậy chỉ cần DSU ngược lên
//DSU của điểm cuối cùng thì sẽ là tính liên thông trước khi đóng cửa điểm trên đó
//Và tương tự cho tới điểm đầu tiên thì nó sẽ là tính liên thông trước khi đóng cửa bất cứ điểm nào
//Để xét xem nó có liên thông hay không thì chỉ cần xét parent[findSet(u)] nếu nó có độ lớn bằng với
//số lượng đỉnh hiện đang mở cửa thì nó liên thông với nhau.

//VD:
//3
//4
//1
//2

//Ta sẽ DSU của 2 đầu tiên (tương ứng với kết quả sau khi 1 đóng cửa) với các điểm còn mở cửa
//thì trước khi 2 đóng cửa thì không có điểm khác còn mở cửa
//Nên DSU của parent[2] sẽ là -1 bằng với số lượng đỉnh đang mở cửa => Liên thông

//Tiếp đến ta sẽ DSU điểm 1 (tương ứng với kết quả sau khi 4 đóng cửa) với các điểm còn mở cửa
//Trước khi 4 đóng cửa có điểm 2 khác với điẻm 1 mà còn mở cửa
//Mà a[1] có chứa 2 nên sẽ DSU(1,2) và khi đó parent[findSet(1)] = parent[1] = -2 = số lượng đỉnh còn mở
//=> Liên thông

//Tiếp đến là DSU của 4 (tương ứng với kết quả sau khi 3 đóng cửa) với các điểm còn mở cửa
//thì trước khi 4 đóng cửa thì có 2 và 1 khác 4 còn mở cửa
//Tuy nhiên a[4] không có liên kết với 1 và 2 nên sẽ không DSU
//Khi đó parent[findSet(4)] = parent[4] = -1 != số lượng đỉnh còn mở => Không liên thông

//Cuối cùng là DSU của đỉnh 3 thì sẽ cho ra kết quả là YES

//Dãy kết quả bây giờ là: "YES", "NO", "YES", "YES". Ta có thể dùng stack để cho kết quả vừa mới tìm
//được lên cùng và in ra.
