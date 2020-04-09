/*
 * 완주하지 못한 선수
 * https://programmers.co.kr/learn/courses/30/lessons/42576
 * */
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";
  map<string, int> m;

  for(auto& v: participant)
  {
    m[v]++;
  }
  for(auto& v: completion)
  {
    m[v]--;
  }

  for(auto& elem: m)
  {
    if(elem.second != 0)
    {
      answer = elem.first;
      break;
    }
  }

  return answer;
}

int main()
{
  std::cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"}) << std::endl;
  std::cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"},
          {"josipa", "filipa", "marina", "nikola"}) << std::endl;
  std::cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << std::endl;

}