/*
 * 다리를 지나는 트럭
 * https://programmers.co.kr/learn/courses/30/lessons/42583
 */
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;

  queue<int> beforeTrucks;
  for(int i = 0; i < truck_weights.size(); i++)
  {
    beforeTrucks.push(truck_weights[i]);
  }

  queue<pair<int, int>> onTrucks;
  int onWeight = 0;
  int time = 0;
  while(!beforeTrucks.empty() || !onTrucks.empty())
  {
    time++;

    if(!beforeTrucks.empty())
    {
      int beforeFront = beforeTrucks.front();
      if (onWeight + beforeFront <= weight)
      {
        //std::cout << time << std::endl;
        onTrucks.push(make_pair(beforeFront, time));
        onWeight += beforeFront;
        beforeTrucks.pop();
      }
    }

    if(!onTrucks.empty())
    {
      auto onFront = onTrucks.front();
      if((time - onFront.second)+1 >= bridge_length)
      {
        onWeight -= onFront.first;
        onTrucks.pop();
      }
    }
  }
  time++;

  answer = time;
  return answer;
}

int main()
{
  vector<int> v;
  v.push_back(7);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);

  std::cout << solution(2, 10, v) << std::endl;
}