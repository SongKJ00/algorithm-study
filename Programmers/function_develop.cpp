/*
 * 기능개발
 * https://programmers.co.kr/learn/courses/30/lessons/42586
 * */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  vector<int> days;

  days.resize(progresses.size());
  for(int i = 0; i < progresses.size(); i++)
  {
    int quot = (100-progresses[i]) / speeds[i];
    int rem = (100-progresses[i]) % speeds[i];
    if(rem != 0)
    {
      days[i] = quot + 1;
    }
    else
    {
      days[i] = quot;
    }
  }

  for(int i = 0; i < days.size()-1; i++)
  {
    if(days[i] > days[i+1])
    {
      days[i+1] = days[i];
    }
  }

  int prev = -1;
  int temp = 1;
  for(int i = 0; i < days.size()-1; i++)
  {
    if(days[i] == days[i+1])
    {
      temp++;
    }
    else
    {
      answer.push_back(temp);
      temp = 1;
    }
  }
  answer.push_back(temp);

  return answer;
}

int main()
{
  vector<int> progresses{93, 30, 55};
  vector<int> speeds{1, 30, 5};

  auto ret = solution(progresses, speeds);
  for(auto& r: ret)
  {
    std::cout << r << std::endl;
  }
  return 0;
}