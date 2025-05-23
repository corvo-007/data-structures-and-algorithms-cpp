#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include "../../common/functions.h"

namespace Graph {

    class Edge {
    public:
        int source;
        int dest;
        int weight;

        Edge() {

        }

        Edge(int source, int dest): source(source), dest(dest), weight(0) {

        }

        Edge(int source, int dest, int weight): source(source), dest(dest), weight(weight) {

        }

        static bool compare(const Edge &e1, const Edge &e2) {
            return e1.weight < e2.weight;
        }
    };

    template <typename T>
    T** constructGraph(T value, int n) {
        T **edges = new T*[n];

        for (int i = 0; i < n; i++) {
            edges[i] = new T[n];

            for (int j = 0; j < n; j++) {
                edges[i][j] = value;
            }
        }

        return edges;
    }

    std::pair<bool**, int> inputGraph() {
        int n, e;
        std::cin >> n >> e;

        bool **edges = constructGraph(false, n);

        for (int i = 0; i < e; i++) {
            int f, s;
            std::cin >> f >> s;

            edges[f][s] = true;
            edges[s][f] = true;
        }

        return { edges, n };
    }

    std::pair<int**, int> inputWeightedGraph() {
        int n, e;
        std::cin >> n >> e;

        int **edges = constructGraph(-1, n);

        for (int i = 0; i < e; i++) {
            int f, s, w;
            std::cin >> f >> s >> w;

            edges[f][s] = w;
            edges[s][f] = w;
        }

        return { edges, n };
    }

    std::pair<Edge*, std::pair<int, int>> inputEdges() {
        int n, e;

        std::cin >> n >> e;

        Edge *edges = new Edge[e];

        for (int i = 0; i < e; i++) {
            int source, dest, weight;

            std::cin >> source >> dest >> weight;

            edges[i].source = source;
            edges[i].dest = dest;
            edges[i].weight = weight;
        }

        return { edges, { n, e } };
    }

    void DFS(bool **edges, int n, int sv, bool *visited) {
        std::cout << sv << ' ';
        visited[sv] = true;

        for (int i = 0; i < n; i++) {
            if (i != sv && edges[sv][i] && !visited[i]) {
                DFS(edges, n, i, visited);
            }
        }
    }

    void DFS(bool **edges, int n) {
        bool *visited = new bool[n];

        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(edges, n, i, visited);
            }
        }
        delete [] visited;
    }

    void BFS(bool **edges, int n) {
        std::queue<int> q;
        std::vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int front = q.front();
                q.pop();

                std::cout << front << ' ';

                for (int j = 0; j < n; j++) {
                    if (j != front && edges[front][j] && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }

    bool hasPathDFS(bool **edges, int n, int sv, int ev, std::vector<bool> &visited) {
        if (edges[sv][ev]) {
            return true;
        }

        visited[sv] = true;

        for (int i = 0; i < n; i++) {
            if (i != sv && edges[sv][i] && !visited[i]) {
                if (hasPathDFS(edges, n, i, ev, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool hasPathDFS(bool **edges, int n, int sv, int ev) {
        std::vector<bool> visited(n, false);
        return hasPathDFS(edges, n, sv, ev, visited);
    }

    bool hasPathBFS(bool **edges, int n, int sv, int ev) {
        std::queue<int> q;
        std::vector<bool> visited(n, false);

        q.push(sv);
        visited[sv] = true;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            if (edges[front][ev]) {
                return true;
            }

            for (int i = 0; i < n; i++) {
                if (i != front && edges[front][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        return false;
    }

    std::vector<int>* getPathDFS(bool **edges, int n, int sv, int ev, std::vector<bool> &visited) {
        if (sv == ev) {
            return new std::vector<int> { sv };
        }

        visited[sv] = true;

        for (int i = 0; i < n; i++) {
            if (i != sv && edges[sv][i] && !visited[i]) {
                std::vector<int> *path = getPathDFS(edges, n, i, ev, visited);

                if (path != nullptr) {
                    path -> push_back(sv);
                    return path;
                }
            }
        }

        return nullptr;
    }

    std::vector<int>* getPathDFS(bool **edges, int n, int sv, int ev) {
        std::vector<bool> visited(n, false);
        return getPathDFS(edges, n, sv, ev, visited);
    }

    std::vector<int>* getPathBFS(bool **edges, int n, int sv, int ev) {
        std::queue<int> q;
        std::vector<bool> visited(n, false);

        std::unordered_map<int, int> map;

        q.push(sv);
        visited[sv] = true;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            if (edges[front][ev]) {
                map[ev] = front;
                break;
            }

            for (int i = 0; i < n; i++) {
                if (i != front && edges[front][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                    map[i] = front;
                }
            }
        }

        if (!map.count(ev)) {
            return nullptr;
        }

        std::vector<int> *path = new std::vector<int>();

        int temp = ev;

        while (map.count(temp)) {
            path -> push_back(temp);

            temp = map[temp];
        }
        path -> push_back(temp);

        return path;
    }

    void isConnectedDFS(bool **edges, int n, int sv, std::vector<bool> &visited) {
        visited[sv] = true;

        for (int i = 0; i < n; i++) {
            if (i != sv && edges[sv][i] && !visited[i]) {
                isConnectedDFS(edges, n, i, visited);
            }
        }
    }

    bool isConnectedDFS(bool **edges, int n) {
        std::vector<bool> visited(n, false);

        isConnectedDFS(edges, n, 0, visited);

        for (const bool &v: visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }

    bool isConnectedBFS(bool **edges, int n) {
        std::queue<int> q;
        std::vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (int i = 0; i < n; i++) {
                if (i != front && edges[front][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        for (const bool &v: visited) {
            if (!v) {
                return false;
            }
        }

        return true;
    }

    void getConnectedComponentsDFS(bool **edges, int n, int sv, std::vector<bool> &visited, std::vector<int> &component) {
        component.push_back(sv);

        visited[sv] = true;

        for (int i = 0; i < n; i++) {
            if (i != sv && edges[sv][i] && !visited[i]) {
                getConnectedComponentsDFS(edges, n, i, visited, component);
            }
        }
    }

    std::vector<std::vector<int>> getConnectedComponentsDFS(bool **edges, int n) {
        std::vector<std::vector<int>> components;

        std::vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                std::vector<int> component;
                getConnectedComponentsDFS(edges, n, i, visited, component);
                components.push_back(component);
            }
        }

        return components;
    }

    std::vector<std::vector<int>> getConnectedComponentsBFS(bool **edges, int n) {
        std::vector<std::vector<int>> components;
        std::queue<int> q;
        std::vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }

            std::vector<int> component;

            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int front = q.front();
                q.pop();

                component.push_back(front);

                for (int j = 0; j < n; j++) {
                    if (j != front && edges[front][j] && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }

            components.push_back(component);
        }

        return components;
    }

    int findParent(int *parents, int vertex) {
        while (parents[vertex] != vertex) {
            vertex = parents[vertex];
        }
        return vertex;
    }

    // Kruskal's algorithm - minimum spanning tree with union find
    std::pair<Edge*, int> minimumSpanningTree(Edge *edges, int n, int e) {
        std::sort(edges, edges + e, Edge::compare);

        Edge *mst = new Edge[n - 1];

        int *parents = new int[n];
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        int verticesCount = 0;

        for (int i = 0; i < e; i++) {
            int srcParent = findParent(parents, edges[i].source);
            int destParent = findParent(parents, edges[i].dest);

            if (srcParent == destParent) {
                continue;
            }

            parents[destParent] = srcParent;

            mst[verticesCount].source = edges[i].source;
            mst[verticesCount].dest = edges[i].dest;
            mst[verticesCount].weight = edges[i].weight;

            verticesCount++;

            if (verticesCount == n - 1) {
                break;
            }
        }

        delete [] parents;

        return { mst, n - 1 };
    }

    int minimumWeightNotVisitedVertex(const std::vector<int> &weights, const std::vector<bool> &visited) {
        int index = -1;

        for (int i = 0; i < weights.size(); i++) {
            if (visited[i]) {
                continue;
            }
            if (index == -1 || weights[i] < weights[index]) {
                index = i;
            }
        }
        return index;
    }

    // Prim's algorithm - minimum spanning tree
    int** minimumSpanningTree(int **edges, int n) {
        std::vector<bool> visited(n, false);
        std::vector<int> weights(n, INT_MAX);
        std::vector<int> parents(n);

        weights[0] = 0;
        parents[0] = -1;

        for (int i = 0; i < n - 1; i++) {
            int vertex = minimumWeightNotVisitedVertex(weights, visited);

            visited[vertex] = true;

            for (int i = 0; i < n; i++) {
                if (i != vertex && edges[vertex][i] != -1 && !visited[i] && edges[vertex][i] < weights[i]) {
                    weights[i] = edges[vertex][i];
                    parents[i] = vertex;
                }
            }
        }

        int **mst = constructGraph(-1, n);

        for (int i = 1; i < weights.size(); i++) {
            mst[i][parents[i]] = weights[i];
            mst[parents[i]][i] = weights[i];
        }

        return mst;
    }

    std::vector<int> shortestPath(int **edges, int n, int source) {
        std::vector<bool> visited(n, false);
        std::vector<int> dist(n, INT_MAX);

        dist[source] = 0;

        for (int i = 0; i < n - 1; i++) {
            int vertex = minimumWeightNotVisitedVertex(dist, visited);

            visited[vertex] = true;

            for (int i = 0; i < n; i++) {
                if (i != vertex && edges[vertex][i] != -1 && !visited[i]) {
                    int d = dist[vertex] + edges[vertex][i];
                    if (d < dist[i]) {
                        dist[i] = d;
                    }
                }
            }
        }

        return dist;
    }

    // only works for DAG (Directed Acyclic Graph)
    void topologicalSort(const bool * const * const edges, int n, int vertex, std::vector<int> &visited, std::vector<int> &output) {
        visited[vertex] = true;

        for (int i = 0; i < n; i++) {
            if (edges[vertex][i] && !visited[i]) {
                topologicalSort(edges, n, i, visited, output);
            }
        }

        output.push_back(vertex);
    }

    std::vector<int> topologicalSort(bool **edges, int n) {
        std::vector<int> output;
        std::vector<int> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                topologicalSort(edges, n, i, visited, output);
            }
        }

        std::reverse(output.begin(), output.end());
        return output;
    }

    // kahn's algorithm
    std::vector<int> topologicalSort(const std::vector<std::vector<int>> &adjList, int n) {
        std::vector<int> indegree(n, 0);

        for (auto &vec : adjList) {
            for (const int &i : vec) {
                indegree[i]++;
            }
        }

        std::queue<int> queue;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                queue.push(i);
            }
        }

        std::vector<int> output;

        while (!queue.empty()) {
            int front = queue.front();
            queue.pop();

            output.push_back(front);

            for (const int &i : adjList[front]) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    queue.push(i);
                }
            }
        }

        return output;
    }

    void destructGraph(bool **edges, int n) {
        for (int i = 0; i < n; i++) {
            delete [] edges[i];
        }

        delete [] edges;
    }

    void destructEdges(Edge *edges) {
        delete [] edges;
    }
}
