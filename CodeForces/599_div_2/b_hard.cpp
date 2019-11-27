#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<bool> isSame;
std::vector<int> switchCnt;
std::vector<std::vector<std::pair<int, int> > > switchList;

void swap(int caseNum, std::string& str1, std::string& str2, int str1Idx, int str2Idx)
{
  char temp = str1[str1Idx];
  str1[str1Idx] = str2[str2Idx];
  str2[str2Idx] = temp;

  switchCnt[caseNum]++;
  switchList[caseNum].push_back(std::make_pair(str1Idx+1, str2Idx+1));
}

void solution(int caseNum, int strLen, std::string& str1, std::string& str2)
{
  for(int setIdx = 0; setIdx < strLen-1; setIdx++)
  {
    if(str1[setIdx] != str2[setIdx])
    {
      for(int switchIdx = setIdx+1; switchIdx < strLen; switchIdx++)
      {
        if(str1[setIdx] == str1[switchIdx])
        {
          swap(caseNum, str1, str2, switchIdx, setIdx);
          break;
        }
        else if(str1[setIdx] == str2[switchIdx])
        {
          swap(caseNum, str1, str2, switchIdx, switchIdx);
          swap(caseNum, str1, str2, switchIdx, setIdx);
          //swap(caseNum, str1, str2, setIdx+1, switchIdx);
          //swap(caseNum, str1, str2, setIdx+1, setIdx);
          break;
        }
      }
    }
  }

  if(str1.compare(str2) == 0)
  {
    isSame[caseNum] = true;
  }
  else
  {
    isSame[caseNum] = false;
  }
}

int main(void)
{
  int numTestCase;
  int strLen;
  std::string str1, str2;
  std::stringstream result;
  
  std::cin >> numTestCase;
  isSame.resize(numTestCase);
  switchCnt.resize(numTestCase);
  switchList.resize(numTestCase);

  for(int i = 0; i < numTestCase; i++)
  {
    std::cin >> strLen;
    std::cin >> str1;
    std::cin >> str2;

    solution(i, strLen, str1, str2);
  }

  for(int i = 0; i < numTestCase; i++)
  {
    if(isSame[i] == true)
    {
      std::cout << "Yes" << std::endl;
      std::cout << switchCnt[i] << std::endl;
      for(int j = 0; j < switchList[i].size(); j++)
      {
        std::cout << switchList[i][j].first << " " << switchList[i][j].second << std::endl;
      }
    }
    else
    {
      std::cout << "No" << std::endl;
    }
    
  }

  return 0;
}