#include <vector>
#include <unordered_map>

namespace Graph {

    class Node {
    public:
        int val;
        std::vector<Node*> neighbors;

        Node(): val(0) {

        }

        Node(int val): val(val) {

        }

        Node(int val, std::vector<Node*> neighbors): val(val), neighbors(neighbors) {

        }
    };

    Node* cloneGraph(Node *node, std::unordered_map<Node*, Node*> &visited) {
        if (node == nullptr) {
            return nullptr;
        }

        Node *newNode = new Node(node -> val);
        visited.insert({node, newNode});

        for (int i = 0; i < node -> neighbors.size(); i++) {
            Node *newNeighbor = visited.count(node -> neighbors[i]) ? visited[node -> neighbors[i]] : cloneGraph(node -> neighbors[i], visited);
            newNode -> neighbors.push_back(newNeighbor);
        }

        return newNode;
    }

    Node* cloneGraph(Node *node) {
        std::unordered_map<Node*, Node*> visited;
        return cloneGraph(node, visited);
    }
}