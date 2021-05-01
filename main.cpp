#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <functional>

using TLl = long long;
static const TLl INF = INT_MAX;

TLl Dijkstra(const std::vector<std::vector<std::pair<int, int> > >& graph, int start, int finish) {
    int n = graph.size();

    std::priority_queue<std::pair<TLl, int>, std::vector<std::pair<TLl, int> >, std::greater<std::pair<TLl, int> > > pq;
    pq.push(std::make_pair(0, start));

    std::vector<TLl> dist(n, INF);
    dist[start] = 0;

    std::vector<bool> used(n);
    
    while (!pq.empty()) {
        std::pair<int, int> top = pq.top();
        int v = top.second;
        int vd = top.first;
        pq.pop();
        used[v] = true;

        for (int i = 0; i < graph[v].size(); ++i) {
            int to = graph[v][i].first;
            int tod = graph[v][i].second;
            if (vd + tod < dist[to]) {
                dist[to] = vd + tod;
                pq.push(std::make_pair(dist[to], to));
            }
        }
    }

    return dist[finish];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); 
    int n = -1;
    int m = -1;
    int start = -1;
    int finish = -1;
    std::cin >> n >> m >> start >> finish;
    std::vector<std::vector<std::pair<int, int> > > graph(n, std::vector<std::pair<int, int> >());
    for (int i = 0; i < m; ++i) {
        int v, to, w;
        std::cin >> v >> to >> w;
        graph[v-1].push_back(std::make_pair(to-1, w)); 
        graph[to-1].push_back(std::make_pair(v-1, w)); 
    }
    TLl ans = Dijkstra(graph, start - 1, finish - 1);
    ans == INF ? std::cout << "No solution\n" : std::cout << std::to_string(ans) << "\n";
    return 0;
}