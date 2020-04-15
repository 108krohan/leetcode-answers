For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1 :

Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

Output: [1]

Example 2 :

Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

Output: [3, 4]

Note:

    According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
    The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.



class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> edges) {
        // for case 1, []
        if(leafs.empty()) return {0};

        vector<unordered_set<int>> graph(n);
        for(vector<int> edge : edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        vector<int> leafs;
        for(int i=0;i<n;i++) 
            if(graph[i].size() == 1) 
                leafs.push_back(i);
        auto count = n - leafs.size();
        while(count > 0){
            vector<int> tmp;
            for(int leaf : leafs){
                for(int neighbor : graph[leaf]){
                    graph[neighbor].erase(leaf);
                    if(graph[neighbor].size() == 1) 
                        tmp.push_back(neighbor);
                }
                
            }
            leafs = tmp;
            count -= leafs.size();
        }
        return leafs;
    }
};
    // below solution fails for 5000 long single linked list...
    // what a shame.. passes 63/66 test cases.
    // might pass all with stack implementation instead of recursion.
//     int getHeight(vector<unordered_set<int>> &edgeList, int start, 
//                  unordered_set<int> &visited, int height, int &minimum) {
//         if(height > minimum) {
//             return INT_MAX;
//         }
//         visited.insert(start); 
//         if(visited.size() == edgeList.size()) {
//             return height;
//         }
//         int max_height = height;
//         for(unordered_set<int>::iterator itr = edgeList.at(start).begin(); 
//             itr != edgeList.at(start).end(); 
//             itr++) {
//             int neighbour = *itr;
//             if(visited.find(neighbour) == visited.end() 
//                && visited.size() != edgeList.size()) {
//                 // cout << "neighbour = " << neighbour << endl;
//                 // cout << "visited.size() = " << visited.size() << endl;
//                 int height_of_child = getHeight(edgeList, neighbour, visited, height + 1, minimum);
//                 // cout << "height of child = " << height_of_child << endl;
//                 if(height_of_child == INT_MAX) {
//                     return INT_MAX;
//                 }
//                 max_height = max(
//                     height_of_child,
//                     max_height);
//                 // cout << "max_height = " << max_height << endl; 

//             }
//         }
//         return max_height;
//     }
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<unordered_set<int>> edgeList(n);
//         for(int i = 0; i < edges.size(); i++) {
//             vector<int> edge = edges.at(i);
//             edgeList.at(edge.at(0)).insert(edge.at(1));
//             edgeList.at(edge.at(1)).insert(edge.at(0));
//         }
//         vector<int> result;
//         int minimum = n/2;
//         unordered_set<int> visited;
//         for(int i = 0; i < n; i++) {
//             visited.clear();
//             int height = getHeight(edgeList, i, visited, 0, minimum);
//             // cout << "height = " << height << "at index " << i << endl;
//             // break;
//             if(height == minimum) {
//                 result.push_back(i); 
//             }
//             else if(height < minimum) {
//                 result = {};
//                 minimum = height; 
//                 result.push_back(i);
//             }
//         }
//         return result;
//     }
