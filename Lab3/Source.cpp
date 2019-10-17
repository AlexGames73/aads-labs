#include <iostream>
#include <set>
#include "BinaryHeap.h"
using namespace std;

#define HEAP 0
#define DFS 1
#define DIJKSTRA 2
#define TASK DIJKSTRA

#if TASK == HEAP
void heapSort(int* a, int size) {
	BinaryHeap heap;
	heap.buildHeap(a, size);
	for (int i = size - 1; i >= 0; i--) {
		a[i] = heap.max();
		heap.popMax();
	}
}
#endif // TASK == HEAP
#if TASK == DFS
bool matrix[1000][1000];
bool visit[1000];

void dfs(int v) {
	if (visit[v])
		return;
	visit[v] = 1;
	cout << "\t\t" << "Enter to " << v << endl;
	for (int i = 0; i < 1000; i++) {
		if (matrix[v][i]) {
			dfs(i);
		}
	}
	cout << "\t\t" << "Exit from " << v << endl;
}
#endif // TASK == DFS
#if TASK == DIJKSTRA
struct Vertex {
	int number;
	int weight;
};
vector<Vertex> g[1000];
int dist[1000];
set<pair<int, int>> s;

void dijkstra(int vStart) {
	for (int i = 0; i < 1000; i++)
		dist[i] = (int)1e9;
	dist[vStart] = 0;
	s.insert(make_pair(dist[vStart], vStart));

	while (!s.empty()) {
		int v = s.begin()->second;
		s.erase(s.begin());
		cout << "\t\tChecking " << v << endl;
		for (int j = 0; j < g[v].size(); j++) {
			int u = g[v][j].number;
			int w = g[v][j].weight;
			if (dist[u] > dist[v] + w) {
				cout << "\t\tUpdate (" << v << ", " << u << ") edge from " << dist[u] << " to " << dist[v] + w << endl;
				s.erase(make_pair(dist[u], u));
				dist[u] = dist[v] + w;
				s.insert(make_pair(dist[u], u));
			}
		}
	}
}
#endif // TASK == DIJKSTRA

int main() {
#if TASK == HEAP
	int a[10] = { 1, 2, 3, 4, 5, 10, 9, 8, 7, 6 };
	heapSort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
#endif
#if TASK == DFS
	int n;
	cout << "How many vertexes in graph? ";
	cin >> n;
	cout << "Adjacency matrix: {" << endl;
	for (int i = 0; i < n; i++) {
		cout << "\t";
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << "}" << endl;

	cout << "DFS tracing: {" << endl;
	int cc = 0;
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			cout << "\tConnectivity component " << cc << ": {" << endl;
			dfs(i);
			cc++;
			cout << "\t}" << endl;
		}
	}
	cout << "}" << endl;
#endif
#if TASK == DIJKSTRA
	int n, m;
	cout << "How many vertexes in graph? ";
	cin >> n;
	cout << "How many edges in graph? ";
	cin >> m;
	int a, b, w;
	cout << "Edges (from, to, weight): {" << endl;
	for (int i = 0; i < n; i++) {
		cout << "\t";
		cin >> a >> b >> w;
		Vertex v;
		v.weight = w;
		v.number = b;
		g[a].push_back(v);
		v.number = a;
		g[b].push_back(v);
	}
	cout << "}" << endl;

	cout << "Dijkstra tracing: {" << endl;
	dijkstra(0);
	cout << "}" << endl;
#endif
}