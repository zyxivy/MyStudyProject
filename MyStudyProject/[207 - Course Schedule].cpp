//There are a total of n courses you have to take, labeled from 0 to n - 1.
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses ?
//For example :
//2, [[1, 0]]
//There are a total of 2 courses to take.To take course 1 you should have finished course 0. So it is possible.
//2, [[1, 0], [0, 1]]
//There are a total of 2 courses to take.To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
//Note :
//    The input prerequisites is a graph represented by a list of edges, not adjacency matrices.Read more about how a graph is represented.
//    You may assume that there are no duplicate edges in the input prerequisites.
//
//Hints:
//This problem is equivalent to finding if a cycle exists in a directed graph.If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
//Topological Sort via DFS - A great video tutorial(21 minutes) on Coursera explaining the basic concepts of Topological Sort.
//Topological sort could also be done via BFS.


//https://en.wikipedia.org/wiki/Topological_sorting

/**Kahn's algorithm
L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edges
    while S is non - empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S
if graph has edges then
    return error(graph has at least one cycle)
else
    return L(a topologically sorted order)**/

/** Depth-first search
L ← Empty list that will contain the sorted nodes
while there are unmarked nodes do
    select an unmarked node n
    visit(n)
function visit(node n)
    if n has a temporary mark then stop(not a DAG)
    if n is not marked(i.e.has not been visited yet) then
        mark n temporarily
        for each node m with an edge from n to m do
            visit(m)
        mark n permanently
        unmark n temporarily
        add n to head of L
**/

#include "Header.h";

bool canFinishVisit(vector<vector<int>> graph, vector<int> visited, int i) {
    if (visited[i] == 1) {
        return true;
    }
    if (visited[i] == -1) {
        return false;
    }
    visited[i] = -1;
    for (int k = 0; k < graph[i].size(); k++) {
        if (!canFinishVisit(graph, visited, graph[i][k])) {
            return false;
        }
    }
    visited[i] = 1;
    return true;
}
bool Solution::canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    //BFS
    //vector<vector<bool>> map(numCourses, vector<bool>(numCourses, false));
    //vector<int> ins(numCourses, 0);
    //for (int i = 0; i < prerequisites.size(); i++) {
    //    if (map[prerequisites[i].first][prerequisites[i].second] == false) {
    //        map[prerequisites[i].first][prerequisites[i].second] = true;
    //        ins[prerequisites[i].first]++;
    //    }
    //}
    //vector<int> stack;
    //for (int i = 0; i < numCourses; i++){
    //    if (ins[i] == 0) {
    //        stack.push_back(i);
    //    }
    //}
    //int count = 0;
    //while (!stack.empty()) {
    //    int top = stack.back();
    //    stack.pop_back();
    //    count++;
    //    for (int i = 0; i < numCourses; i++) {
    //        if (map[i][top]) {
    //            ins[i]--;
    //            if (ins[i] == 0) {
    //                stack.push_back(i);
    //            }
    //        }
    //    }
    //}
    //return count < numCourses ? false : true;

    //DFS
    vector<int> visited(numCourses, 0);
    vector<vector<int>> graph(numCourses, vector<int>(0));

    for (int i = 0; i < prerequisites.size(); i++) {
        graph[prerequisites[i].second].push_back(prerequisites[i].first);
    }
    for (int i = 0; i < numCourses; i++) {
        if (!canFinishVisit(graph, visited, i)) {
            return false;
        }
    }
    return true;
}