class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    vector<vector<unordered_map<string, int>>> adjacencyList(n);
    for (int i = 0; i < flights.size(); i++) {
      unordered_map<string, int> list;
      list["src"] = flights[i][0];
      list["dest"] = flights[i][1];
      list["dist"] = flights[i][2];
      adjacencyList[flights[i][0]].push_back(list);
    }

    // in the format: {node, hops, distance to source}
    vector<unordered_map<string, int>> distances(
        n, {{"index", 0}, {"hops", 0}, {"dist", 1e9}});
    distances[src]["dist"] = 0;

    // 1. heapify
    // 2. visit the node with the smallest value
    vector<unordered_map<string, int>> neigh_list = {distances[src]};

    while (!neigh_list.empty()) {
      // 2. get the smallest dist node
      int temp = get_min_node(neigh_list);
      int current_index = neigh_list[temp]["index"];

      cout << current_index << endl;

      neigh_list.erase(neigh_list.begin() + temp);

      cout << "printing neighbours of " << current_index << endl;

      // 3. add all your neighbours to neigh_list
      for (auto &neigh : adjacencyList[current_index]) {
        cout << neigh["dest"] << endl;

        int neigh_index = neigh["dest"];

        // new distance = current -> neigh + dist to current
        int new_distance = neigh["dist"] + distances[current_index]["dist"];
        if (new_distance > distances[neigh_index]["dist"] &&
            distances[current_index]["hops"] + 1 <= k) {
          distances[neigh_index]["dist"];
          distances[neigh_index]["hops"] = distances[current_index]["hops"] + 1;
        }
        neigh_list.push_back(neigh);
      }
    }

    // 5. update distance
    return distances[dst]["dist"];
  }

  int get_min_node(vector<unordered_map<string, int>> distance) {
    int min_index = 99;
    int temp_dist = 1e9;
    cout << "contents of neigh_list" << endl;
    for (auto &dict : distance) {
      cout << dict["index"] << endl;
      if (dict["dist"] < temp_dist) {
        temp_dist = dict["dist"];
        min_index = dict["index"];
      }
    }
    cout << "returning " << min_index << endl;
    return min_index;
  }
}
