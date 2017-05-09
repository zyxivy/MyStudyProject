//Clone an undirected graph.Each node in the graph contains a label and a list of its neighbors.
//
//OJ's undirected graph serialization: 
//Nodes are labeled uniquely.
//We use # as a separator for each node, and, as a separator for node label and each neighbor of the node.
//
//As an example, consider the serialized graph{ 0,1,2#1,2#2,2 }.
//The graph has a total of three nodes, and therefore contains three parts as separated by #.
//First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//Second node is labeled as 1. Connect node 1 to node 2.
//Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self - cycle.
//
//Visually, the graph looks like the following :
//1
/// \
/// \
//0 -- - 2
/// \
//\_ /

#include "Header.h";

//struct UndirectedGraphNode {
//    int label;
//    vector<UndirectedGraphNode *> neighbors;
//    UndirectedGraphNode(int x) : label(x) {};
//};

UndirectedGraphNode* Solution::cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL) {
        return NULL;
    }
    map<UndirectedGraphNode*, UndirectedGraphNode*> map;
    UndirectedGraphNode* newHead = new UndirectedGraphNode(node->label);
    vector<UndirectedGraphNode*> q;
    q.push_back(node);
    map[node] = newHead;

    while (!q.empty()) {
        UndirectedGraphNode* curr = q.back();
        q.pop_back();

        vector<UndirectedGraphNode *> curNeighbors = curr->neighbors;
        for (int i = 0; i < curNeighbors.size(); i++) {
            if (!map[curNeighbors[i]]) {
                UndirectedGraphNode* newCurNeighbor = new UndirectedGraphNode(curNeighbors[i]->label);
                map[curNeighbors[i]] = newCurNeighbor;
                map[curr]->neighbors.push_back(newCurNeighbor);
                q.push_back(curNeighbors[i]);
            }
            else {
                map[curr]->neighbors.push_back(map[curNeighbors[i]]);
            }
        }
    }
    return newHead;
}

