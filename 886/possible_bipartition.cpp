#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

// Given a set of N people (numbered 1, 2, ..., N), we would like to split
// everyone into two groups of any size.
// Each person may dislike some other people, and they should not go into the
// same group.
// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the
// people numbered a and b into the same group.
// Return true if and only if it is possible to split everyone into two groups
// in this way.
class Solution {
public:
  //这是一个二分类问题，可以采用dfs或者bfs
  //图里面相邻的边不能用同一种颜色表示
  // 2表示未访问，1和0表示不同颜色
  //因为这是一个无向图；
  //因此不必用矩阵存储边，要不然在leetcode 886上内存超限
  //每个顶点存储和自己相邻节点的边即可
  bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
    if (N < 2)
      return true;
    vector<int> m_visit(N + 1, 2);
    // vector<vector<int>> graph(N + 1, vector<int>(N + 1));
    vector<vector<int>> graph(N + 1);
    int i;
    //第一步，创建一个图
    for (i = 0; i < dislikes.size(); ++i) {
      // graph[dislikes[i][0]][dislikes[i][1]] = 1;
      // graph[dislikes[i][1]][dislikes[i][0]] = 1;
      graph[dislikes[i][0]].push_back(dislikes[i][1]);
      graph[dislikes[i][1]].push_back(dislikes[i][0]);
    }
    return dfs(graph, m_visit);
  }
  bool dfs(const vector<vector<int>> &graph, vector<int> &m_visit) {
    int i;
    for (i = 1; i < graph.size(); ++i) {
      if (m_visit[i] == 2) { //未访问
        // printf("walk %d\n", i);
        if ((dfs_core(graph, m_visit, i, 1)) == false) //默认划分到第一组
          return false;
      }
    }
    return true;
  }
  bool dfs_core(const vector<vector<int>> &graph, vector<int> &m_visit, int idx,
                int colors) {
    int i;
    m_visit[idx] = colors; //访问该节点
    // printf("color : %d\tidx : %d\n", colors, idx);
    // for (i = 1; i < graph.size(); ++i) {
    //  if (graph[idx][i] == 1 && m_visit[i] == colors) { //邻接点涂了相同颜色
    //    return false;                                   //划分失败
    //  } else if (graph[idx][i] == 1 && m_visit[i] == 2) { //邻接点且未被访问
    //    if ((dfs_core(graph, m_visit, i, 1 - colors)) == false)
    //    //涂另外一种颜色
    //      return false;
    //  }
    //}
    for (i = 0; i < graph[idx].size(); ++i) {
      if (m_visit[graph[idx][i]] == colors) { //邻接点涂了相同的颜色
        // printf("点 %d 与邻接点 %d涂了相同颜色\n", idx, graph[idx][i]);
        return false;
      } else if (m_visit[graph[idx][i]] == 2) { //未访问的邻接点
        // printf("用颜色 %d 涂邻接点 %d\n", 1 - colors, graph[idx][i]);
        if ((dfs_core(graph, m_visit, graph[idx][i], 1 - colors)) ==
            false) //涂另外一种颜色
          return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution sln;
  vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};
  assert(sln.possibleBipartition(4, dislikes) == true);
  dislikes = {{1, 2}, {1, 3}, {2, 3}};
  assert(sln.possibleBipartition(3, dislikes) == false);
  dislikes = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
  assert(sln.possibleBipartition(5, dislikes) == false);
  return 0;
}
