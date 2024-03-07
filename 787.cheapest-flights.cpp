class Graph {
public:
  int vertices;
  vector<vector<pair<int, int>>> adjacencyList;

  Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
  }

  void add_edge(int v, int w, int weight) {
    adjacencyList[v].push_back({w, weight});
  }

  void print_graph() {
    for (int i = 0; i < vertices; ++i) {
      std::cout << "Adjacency list of vertex " << i << ": ";
      for (const auto &neighbor : adjacencyList[i]) {
        std::cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
      }
      std::cout << std::endl;
    }
  }

  vector<pair<int, int>> neighbours(int *node_index) {
    return adjacencyList[node_index];
  }
};

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    int main_array[n];
    fill(main_array, main_array + n, 101);
    main_array[src] = 0;

    Graph *graph = build_graph(n, flights);

    // 1. heapify
    priority_queue<int, vector<int>, greater<int>> min_heap(main_array,
                                                            main_array + n);

    // 2. visit the node with the smallest value
    int node_index = priority_queue.top();

    // 3. visit all unvisited neighbours
    vector<pair<int, int>> neighbours = graph.neighbours(&node_index);

    // 4. calculate distance

    // 5. update distance

    // repeat until all nodes are visited
    return 0;
  }

  Graph *build_graph(int n, vector<vector<int>> &flight) {
    Graph graph(n);
    for (int i = 0; i < flight.size(); i++) {
      graph.add_edge(flight[i][0], flight[i][1], flight[i][2]);
    }
    graph.print_graph();
    return &graph;
  }
}
