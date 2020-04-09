/*
 * 네트워크
 * https://programmers.co.kr/learn/courses/30/lessons/43162
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(int comNum, vector<bool>& visited, vector<vector<int>>& computers, int n)
{
  visited[comNum] = true;

  for(int i = 0; i < n; i++)
  {
    if(!visited[i] && computers[comNum][i] == 1)
    {
      dfs(i, visited, computers, n);
    }
  }
}

int solution(int n, vector<vector<int>> computers)
{
  vector<bool> visited(n);
  int answer = 0;

  for(int i = 0; i < n; i++)
  {
    if(!visited[i])
    {
      dfs(i, visited, computers, n);
      answer++;
    }
  }
  return answer;
}

int main()
{
  cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << endl;
  cout << solution(3, 	{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << endl;
}