/*
 * 프린터
 * https://programmers.co.kr/learn/courses/30/lessons/42587
 */
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
  int answer = 0;
  priority_queue<int, vector<int>> q;
  for(auto& v: priorities)
  {
    q.push(v);
  }

  while(!q.empty())
  {
    for(int i = 0; i < priorities.size(); i++)
    {
      if(priorities[i] == q.top())
      {
        if(i == location)
        {
          answer++;
          return answer;
        }

        q.pop();
        answer++;
      }
    }
  }
  return answer;
}

int main()
{
  cout << solution({2, 1, 3, 2}, 2) << endl;
  cout << solution({1, 1, 9, 1, 1, 1}, 0) << endl;
}
