#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 간선 정보를 저장할 구조체
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}

    bool operator<(const Edge& e) const {
        return weight < e.weight; // 가중치 기준으로 오름차순 정렬
    }
};

// Union-Find 자료구조
class DisjointSet {
public:
    vector<int> parent, rank;

    // 초기화
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // 각 노드는 자기 자신을 부모로 설정
        }
    }

    // Find 연산 (경로 압축)
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 경로 압축
        }
        return parent[x];
    }

    // Union 연산 (유니온 by 랭크)
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // 랭크가 작은 트리를 큰 트리에 붙이기
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true; // Union이 이루어졌다면 true 반환
        }
        return false; // 이미 같은 집합에 속해 있다면 false
    }
};

int kruskal(int n, vector<Edge>& edges) {
    DisjointSet ds(n);  // n개의 정점에 대해 유니온-파인드 초기화
    sort(edges.begin(), edges.end());  // 간선 가중치를 기준으로 오름차순 정렬

    int mstWeight = 0;  // 최소 신장 트리의 가중치 합
    int mstEdges = 0;   // MST에 포함된 간선의 개수

    // 간선을 하나씩 처리
    for (auto& edge : edges) {
        if (ds.unionSets(edge.u, edge.v)) {
            mstWeight += edge.weight;  // MST에 간선이 추가되면 가중치 합에 더함
            mstEdges++;

            // 정점의 개수 - 1개의 간선이 선택되면 종료
            if (mstEdges == n - 1) {
                break;
            }
        }
    }

    return mstWeight;  // 최소 신장 트리의 가중치 합 반환
}

int main() {
    int n, m;  // n: 정점 개수, m: 간선 개수
    cout << "정점의 개수와 간선의 개수를 입력하세요: ";
    cin >> n >> m;

    vector<Edge> edges;
    cout << "간선 (u, v, 가중치) 정보를 입력하세요:" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back(Edge(u, v, weight));
    }

    int mstWeight = kruskal(n, edges);
    cout << "최소 신장 트리의 가중치 합: " << mstWeight << endl;

    return 0;
}
