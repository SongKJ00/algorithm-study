/*
 * 스킬트리
 * https://programmers.co.kr/learn/courses/30/lessons/49993
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
  int answer = 0;
  int skillIdx = 0;

  for(int i = 0; i < skill_trees.size(); i++)
  {
    skillIdx = 0;
    bool flag = true;
    for(int j = 0; j < skill_trees[i].size(); j++)
    {
      if(skillIdx >= skill.size()) { break; }
      char searchSkill = skill[skillIdx];
      for(int k = skillIdx+1; k < skill.size(); k++)
      {
        if(skill_trees[i][j] == searchSkill)
        {
          skillIdx++;
          break;
        }
        else if(skill_trees[i][j] == skill[k])
        {
          flag = false;
          break;
        }
      }
      if(!flag) { break; }
    }
    if(flag)
    {
      answer++;
    }
  }
  return answer;
}

int main()
{
  vector<string> v;
  v.push_back("BACDE");
  v.push_back("CBADF");
  v.push_back("AECB");
  v.push_back("BDA");
  std::cout << solution("CBD", v) << std::endl;
}