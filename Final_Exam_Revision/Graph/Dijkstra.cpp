#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

// Hàm Dijkstra có thêm mảng truy vết (parent)
void dijkstra(int start, int dest, int n, const vector<vector<pii>> &adj)
{
    // Khởi tạo mảng lưu khoảng cách của điểm start tới các điểm (khởi tạo: Khoảng cách là vô cực)
   vector<int> dist (n+1, INF);
   
   // Mảng parent dùng để lưu vết đường đi
   vector<int> parent(n+1, -1);

   // Khởi tạo khoảng cách từ start tới start
    dist[start] = 0;

    // Cấu trúc dữ liệu hàng đợi ưu tiền (Min-Heap): Lưu trữ pair <khoảng cách, điểm>
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    pq.push({0,start});

    // Chạy vòng while đến khi hàng đợi rỗng
    while (!pq.empty()) {
        // Lấy khoảng cách hiện tại và điểm có khoảng cách nhỏ nhất trong Priority Queue
        int cur_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Nếu như khoảng cách hiện tại mà lớn hơn khoảng cách từ start dến u thì continue
        if (cur_dist > dist[u]) continue;

        // Xét các cạnh kề với đỉnh u
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Nếu như khoảng cách đến đỉnh u + trọng số của u đến v mà bé hơn khoảng cách từ start đến đỉnh v thì sẽ thực hiện thay đổi khoảng cách của dỉnh v mà đẩy vào hàng đợi
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v],v});
            }
        }
    }

    // --- PHẦN XỬ LÝ IN KẾT QUẢ VÀ TRUY VẾT ---
    if (dist[dest] == INF)
    {
        cout << "Khong co duong di tu " << start << " den " << dest << "\n";
        return;
    }

    cout << "Khoang cach ngan nhat tu " << start << " den " << dest << " la: " << dist[dest] << "\n";

    // Mảng lưu trữ đường đi
    vector<int> path;

    // Bắt đầu từ đỉnh đích, lùi dần về đỉnh nguồn
    for (int v = dest; v != -1; v = parent[v]) {
        path.push_back(v);
    }

    // Đảo ngược mảng vì ta đang đi ngược từ Đích về Nguồn
    reverse(path.begin(), path.end());

    cout << "Lo trinh cu the: ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i != path.size() - 1)
        {
            cout << " -> "; // In mũi tên giữa các đỉnh
        }
    }
    cout << "\n";
}
int main()
{
    int n = 5; // Số lượng đỉnh (đánh số từ 1 đến 5)

    // Danh sách kề: adj[u] chứa các cặp {v, weight}
    vector<vector<pii>> adj(n + 1);

    // Thêm các cạnh vào đồ thị (Đồ thị có hướng)
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 4});
    adj[2].push_back({3, 1});
    adj[2].push_back({4, 7});
    adj[3].push_back({5, 3});
    adj[4].push_back({5, 1});

    // Chạy thuật toán bắt đầu từ đỉnh 1
    dijkstra(1, 5, n, adj);

    return 0;
}