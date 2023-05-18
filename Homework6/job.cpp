#include "job.h"
#include <vector>

using namespace std;
// watched youtube videos to learn that DFS and topological order is the method for the dependent events
// also geeks for geeks website for more stuff on graphs
bool dfs(vector<vector<int>> &graph, vector<int> &visited, int node) {

  visited[node] = 1; // in the vector storing the node status, make the one indexed at be visited
  for (int neighbor : graph[node]) { // index through all the neighbors of the current node
      if (visited[neighbor] == 1) { // if the neighbor is already visited then...
          return false;  // ... a cycle is detected
      } 
      else if (visited[neighbor] == 0) { // if the neighbor is not visited then ...
          if (dfs(graph, visited, neighbor) == false) { // ... recursively check the neighbor's neighbor by looking for a false
              return false;  // cycle detected
          }
      }
  }

  visited[node] = 10; // now that all of the nodes respective neighbors have been visited then it can count as completed

  return true; // since no cycle was detected then return true
}

bool canFinish(int n, vector<pair<int, int>> &dependencies) {
  vector<vector<int>> graph(n); // create an adjacency list to represent the dependencies

  for (auto &dep : dependencies) {  // index through the given dependencies 
      int jStart = dep.first - 1; // -1 to get rid of the offset of the given index to the graph made
      int jNext = dep.second - 1; 
      graph[jStart].push_back(jNext); // this is where edges are created to establish dependcies in jobs
  }

  // perform DFS on each node to detect cycles bc if a cycle is detected then its automatically false
  vector<int> visited(n, 0);  // the visited vector has 3 states, 0 (unvisited), 1(vististed), 10(complete)

  for (int i = 0; i < n; i++) { 
      if (visited[i] == 0 && (dfs(graph, visited, i) == false)) { // if an unvisited node is needed and there is a cycle detected (typically return false) 
          return false;  // a cycle is detected
      }
  }

  return true; // no cycle then all good
}

bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i) {
  // check if job j can be run in time slot i
  vector<vector<int>> graph(n); // create an adjacency list to represent the dependencies

  for (auto &dep : dependencies) {
      if ((dep.first == j && dep.second == j) || (dep.second == j)) {
          return false; // job j has a dependency on itself, so it cannot be run
      }
  }
  for (auto &dep : dependencies) {  // index through the given dependencies 
      int jStart = dep.first - 1; // -1 to get rid of the offset of the given index to the graph made
      int jNext = dep.second - 1; 
      graph[jStart].push_back(jNext); // this is where edges are created to establish dependcies in jobs
  }

  // perform DFS on the graph to detect cycles and see if job j can be run in time slot i
  vector<int> visited(n, 0);  // the visited vector has 3 states, 0 (unvisited), 1(vististed), 10(complete)
  visited[j-1] = 10; // mark job j as complete

  for (int node = 0; node < n; node++) {
      if ((visited[node] == 0)||(dfs(graph, visited, node) == false)) { // if a cycle is detected and if an unvisited node is needed
              return false; // job j cannot be run in time slot i
          }
      }

  return true;
}
