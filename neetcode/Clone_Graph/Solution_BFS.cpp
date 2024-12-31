/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // Traverse the graph using BFS and create a copy for every new node we visit
    Node* cloneGraph(Node* node) {
        // Edge case: the graph is empty
        if(!node){return nullptr;}
        // Hash map to map input node and copy
        unordered_map<Node*, Node*> map;
        // Queue to hold current level
        queue<Node*> queue;
        // -- BFS --
        // Start at the root
        map[node] = new Node(node->val);
        queue.push(node);
        while(queue.size() > 0)
        {
            Node* curr = queue.front();
            queue.pop();
            // Traverse all the neighbors, and make copies if they don't exist yet
            for(Node* neighbor : curr->neighbors)
            {
                if(map.find(neighbor) == map.end())
                {
                    map[neighbor] = new Node(neighbor->val);   // Create a copy
                    queue.push(neighbor);   // Add to next level to be traversed to
                }
                // Add the copied neighbor to the copied node's adjacency list
                map[curr]->neighbors.push_back(map[neighbor]);
            }
        }
        // We've traversed the whole graph, return the copied root
        return map[node];
    }
};
