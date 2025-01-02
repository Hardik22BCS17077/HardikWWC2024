#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph {
public:
    unordered_map<int, vector<int>> adjList;

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int findCenter() {
        for (auto& node : adjList) {
            if (node.second.size() == adjList.size() - 1) {
                return node.first;
            }
        }
        return -1; // In case the graph is not a star graph
    }
};

int main() {
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    cout << "The center of the star graph is: " << g.findCenter() << endl;
    return 0;
}
