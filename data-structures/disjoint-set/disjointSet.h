#include <vector>

class DisjointSet {
    std::vector<int> parents;
    std::vector<int> ranks;
    std::vector<int> sizes;

public:
    DisjointSet(int n) {
        parents.resize(n);
        ranks.resize(n, 0);
        sizes.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }

    int findParent(int v) {
        if (v == parents[v]) {
            return v;
        }

        return parents[v] = findParent(parents[v]);
    }

    void unionByRank(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);

        if (up == vp) {
            return ;
        }

        if (ranks[up] == ranks[vp]) {
            parents[vp] = up;
            ranks[up]++;
        }
        else if (ranks[up] < ranks[vp]) {
            parents[up] = vp;
        }
        else {
            parents[vp] = up;
        }
    }

    void unionBySize(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);

        if (up == vp) {
            return ;
        }

        if (sizes[up] <= sizes[vp]) {
            parents[up] = vp;
            sizes[vp] += sizes[up];
        }
        else {
            parents[vp] = up;
            sizes[up] += sizes[vp];
        }
    }
};