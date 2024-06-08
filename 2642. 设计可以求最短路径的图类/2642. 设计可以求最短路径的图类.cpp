class Graph {
public
    vectorvectorint E, nums;
    int m;
    Graph(int n, vectorvectorint& edges) {
        m = n;
        E = vectorvectorint(n + 1);
        nums = vectorvectorint(n + 1);
        for (auto& e  edges) {
            int a = e[0], b = e[1], c = e[2];
            E[a].push_back(b);
            nums[a].push_back(c);
        }
    }

    void addEdge(vectorint edge) {
        int a = edge[0], b = edge[1], c = edge[2];
        E[a].push_back(b);
        nums[a].push_back(c);
    }

    struct comp {
        bool operator()(const pairint, int& a, const pairint, int& b) {
            return a.second  b.second;
        }
    };


    int shortestPath(int node1, int node2) {
        vectorint dist(m + 1, INT_MAX);
        vectorbool Hash(m + 1,0);
        dist[node1] = 0;
        priority_queuepairint, int, vectorpairint, int,compqueue;

        queue.push({node1, 0});  

        while (queue.size()) {
            auto e = queue.top();
            queue.pop();

            int u = e.first, distance = e.second;
            if (Hash[u])
                continue;
            Hash[u] = 1;

            for (int i = 0; i  E[u].size(); i++) {
                int v = E[u][i], dist_v = nums[u][i];
                if (dist[v]  distance + dist_v) {
                    
                    dist[v] = distance + dist_v;
                    queue.push({v, dist[v]});
                }
            }
        }
        return dist[node2] == INT_MAX  -1  dist[node2];
    }
};


  Your Graph object will be instantiated and called as such
  Graph obj = new Graph(n, edges);
  obj-addEdge(edge);
  int param_2 = obj-shortestPath(node1,node2);
 