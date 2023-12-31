#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

struct Point {
    string id;
    int x, y;
};

struct Segment {
    string id;
    int u, v;
};

vector<Point> points;
vector<Segment> segments;
vector<int> adj[MAXN];
bool visited[MAXN];

int maxDepth;

// DFS to find connected components
void dfs(int u, int depth, int start) {
    visited[u] = true;
    maxDepth = max(maxDepth, depth);

    for (int v : adj[u]) {
        if (v == start && depth >= 2) {
            maxDepth = max(maxDepth, depth + 1); // +1 to account for the edge from v back to start
            continue;
        }
        if (!visited[v]) {
            dfs(v, depth + 1, start);
        }
    }
    visited[u] = false;  // Reset the visited status for other paths
}

// Check for cycles starting from u
bool hasCycle(int u, int parent, int start, int depth) {
    if (depth > 2 && u == start) {
        return true;
    }

    visited[u] = true;
    for (int v : adj[u]) {
        if (v != parent && hasCycle(v, u, start, depth + 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Read points
    string id;
    while (cin >> id && id != "#") {
        Point p;
        p.id = id;
        cin >> p.x >> p.y;
        points.push_back(p);
    }

    // Read segments
    while (cin >> id && id != "#") {
        Segment s;
        s.id = id;
        string u_id, v_id;
        cin >> u_id >> v_id;
        for (int i = 0; i < points.size(); ++i) {
            if (points[i].id == u_id) s.u = i;
            if (points[i].id == v_id) s.v = i;
        }
        segments.push_back(s);
        adj[s.u].push_back(s.v);
        adj[s.v].push_back(s.u);
    }

    // Process queries
    string query;
    while (cin >> query && query != "###") {
        if (query == "?number_points") {
            cout << points.size() << endl;
        } else if (query == "?number_segments") {
            cout << segments.size() << endl;
        } else if (query == "?connected_components") {
            memset(visited, false, sizeof(visited));
            int components = 0;
            for (int i = 0; i < points.size(); ++i) {
                if (!visited[i]) {
                    dfs(0, 0, i);
                    components++;
                }
            }
            cout << components << endl;
        } else if (query == "?longest_cycle_from") {
            string start;
            cin >> start;
            int startIndex = -1;
            for (int i = 0; i < points.size(); ++i) {
                if (points[i].id == start) {
                    startIndex = i;
                    break;
                }
            }
            if (startIndex == -1) {
                cout << "Invalid Point ID" << endl;
                continue;
            }
            memset(visited, false, sizeof(visited));
            maxDepth = 0;
            dfs(startIndex, 0, startIndex);
            cout << maxDepth << endl;
        }
    }
    return 0;
}
