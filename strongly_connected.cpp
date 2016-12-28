#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int coun = 1;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  //write your code here
  used[x] = coun++;
  for(int j = 0; j < adj[x].size(); j++) {
    if(!used[adj[x][j]]) {
        dfs(adj, used, order, adj[x][j]);
    }
  }
  used[x] = coun++;
  order.push_back(x);
}

void dfs_2(vector<vector<int> > &adj, vector<int> &used, int x) {
  //write your code here
  used[x] = 1;
  for(int j = 0; j < adj[x].size(); j++) {
    if(!used[adj[x][j]]) {
        dfs_2(adj, used, adj[x][j]);
    }
  }
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  vector< vector<int> > reverseAdj;
  for(int i = 0; i < adj.size(); i++) {
    vector<int> temp;
    reverseAdj.push_back(temp);
  }
  for(int i = 0; i < adj.size(); i++) {
    for(int j = 0; j < adj[i].size(); j++) {
        /*if(std::find(reverseAdj.begin(), reverseAdj.end(), adj[i][j]) != reverseAdj.end()) {
            reverseAdj[adj[i][j]].push_back(i);
        } else {
            vector<int> temp;
            reverseAdj.push_back(temp);*/
        reverseAdj[adj[i][j]].push_back(i);
    }
  }
  /*std::cout << "\nlets check the reverse graph: ";
  for(int i = 0; i < reverseAdj.size(); i++) {
    std::cout << "\nfor " << i;
    for(int j = 0; j < reverseAdj[i].size(); j++) {
        std::cout << " " << reverseAdj[i][j];
    }
  }*/

  vector<int> order;
  vector<int> used(adj.size(),0);
  for(int i = 0; i < reverseAdj.size(); i++) {
    if(!used[i]) {
        // dfs for this node
        dfs(reverseAdj, used, order, i);
    }
  }
  /*std::cout << "\ncheck the order: ";
  for(int i = 0; i < order.size(); i++) {
    std::cout << " " << order[i];
  }*/
  //write your code here
  std::vector<int> used_rev(reverseAdj.size(), 0);
  for(int i = order.size()-1; i >= 0; i--) {
    // reverse order
    //std::cout << "\nconsidering " << order[i];
    if(!used_rev[order[i]]) {
        dfs_2(adj, used_rev, order[i]);
        result++;
    }
    std::cout << "Just for the sake of editing";
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
