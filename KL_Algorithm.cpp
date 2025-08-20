#include<bits/stdc++.h>
#include<chrono>

using namespace std;
auto start = chrono::steady_clock::now();

#define ll long long

#define GOD ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

class KernighanLin {
private:
    unordered_map<ll, unordered_set<ll>> graph; // Adjacency list representation
    unordered_map<ll, ll> partition; // Node partition mapping
    vector<ll> nodes; // List of nodes

public:
    // Constructor: Builds the graph from a given netlist
    KernighanLin(const vector<pair<ll, ll>>& netlist) {
        buildGraph(netlist);
        initializePartition();
    }

    // Function to construct the adjacency list
    void buildGraph(const vector<pair<ll, ll>>& netlist) {
        for (const auto& connection : netlist) {
            ll src = connection.first;
            ll dst = connection.second;
            graph[src].insert(dst);
            graph[dst].insert(src); // Undirected graph
        }
    }

    // Function to randomly partition nodes llo two nearly equal groups
    void initializePartition() {
        for (const auto& entry : graph) {
            nodes.push_back(entry.first);
        }
        shuffle(nodes.begin(), nodes.end(), default_random_engine(random_device{}()));
        size_t mid = nodes.size() / 2;
        
        for (size_t i = 0; i < mid; ++i) partition[nodes[i]] = 0;
        for (size_t i = mid; i < nodes.size(); ++i) partition[nodes[i]] = 1;
    }

    // Function to compute the number of edges crossing partitions
    ll computeCutSize() {
        ll cut_size = 0;
        for (const auto& entry : graph) {
            ll node = entry.first;
            for (ll neighbor : entry.second) {
                if (partition[node] != partition[neighbor]) {
                    cut_size++;
                }
            }
        }
        return cut_size / 2; // Each edge counted twice
    }

    // Kernighan-Lin algorithm to optimize partitioning
    pair<unordered_map<ll, ll>, ll> kernighanLin() {
        unordered_map<ll, ll> best_partition = partition;
        ll best_cut_size = computeCutSize();
        bool improved = true;

        while (improved) {
            improved = false;
            for (ll node1 : nodes) {
                for (ll node2 : nodes) {
                    if (partition[node1] != partition[node2]) { // Only swap across partitions
                        swap(partition[node1], partition[node2]);
                        
                        ll new_cut_size = computeCutSize();
                        
                        if (new_cut_size < best_cut_size) {
                            best_cut_size = new_cut_size;
                            best_partition = partition;
                            improved = true;
                        } else {
                            swap(partition[node1], partition[node2]); // Revert swap
                        }
                    }
                }
            }
        }
        partition = best_partition;
        return {best_partition, best_cut_size};
    }

    // Function to display the optimized partition and cut size
    void displayResult() {
        vector<ll> partition_A, partition_B;
        for (const auto& entry : partition) {
            if (entry.second == 0)
                partition_A.push_back(entry.first);
            else
                partition_B.push_back(entry.first);
        }

        cout << "\nOptimized Partition:\n";
        cout << "Group A: ";
        for (ll node : partition_A) cout << node << " ";
        cout << "\nGroup B: ";
        for (ll node : partition_B) cout << node << " ";
        cout << "\nFinal Cut Size: " << computeCutSize() << endl;
    }
};

// Function to get user input for the netlist
vector<pair<ll, ll>> getNetlist() {
    ll num_connections;
    cout << "Enter the number of connections in the netlist: ";
    cin >> num_connections;
    
    vector<pair<ll, ll>> netlist;
    cout << "Enter connections (e.g., '0 1' for a connection between gates 0 and 1):\n";
    for (ll i = 0; i < num_connections; ++i) {
        ll src, dst;
        cin >> src >> dst;
        netlist.emplace_back(src, dst);
    }
    return netlist;
}

void solve() {
    // Get user input for the netlist
    vector<pair<ll, ll>> netlist = getNetlist();
    
    // Run Kernighan-Lin Algorithm
    KernighanLin kl(netlist);
    
    cout << "\nInitial Cut Size: " << kl.computeCutSize() << endl;
    
    kl.kernighanLin();
    kl.displayResult();
}

int32_t main() {
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}