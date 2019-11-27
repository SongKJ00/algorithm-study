#include <iostream>
#include <vector>
#include <string>

int main(void)
{
    //freopen("input.txt", "r", stdin);
  bool isInvalidCharFound = false;
  long long contN = 1, contU = 1;
  char prevChar = ' ';
  long long caseNumOfN = -1, caseNumOfU = -1;
  long long result = 1;
  const long long n = 1000000000 + 7;
  std::string str;
  std::cin >> str;
  
  std::vector<long long> p[2];
  p[0].resize(str.size()+1);
  p[1].resize(str.size()+1);

  long long size = p[0].size();

  p[0][0] = 0;
  p[1][0] = 0;
  p[0][1] = 1;
  p[1][1] = 0;

  for(long long i = 2; i < size; i++)
  {
    p[0][i] = (p[0][i-1] + p[1][i-1]) % n;
    p[1][i] = p[0][i-1];
  }

  if(str[0] == 'w' || str[0] == 'm')
  {
    isInvalidCharFound = true;
  }
  else
  {
    for(int i = 1; i < str.size(); i++)
    {
      if(str[i] == 'w' || str[i] == 'm')
      {
        isInvalidCharFound = true;
        break;
      }

      if(str[i] == str[i-1])
      {
        if(str[i] == 'n') 
        {
          contN++; 
          caseNumOfN = p[0][contN] + p[1][contN];
          caseNumOfN = caseNumOfN >= n ? caseNumOfN % n : caseNumOfN;
        }
        else if(str[i] == 'u') 
        {
          contU++; 
          caseNumOfU = p[0][contU] + p[1][contU];
          caseNumOfU = caseNumOfU >= n ? caseNumOfU % n : caseNumOfU;
        }
      }
      else
      {
        if(contN != 1)
        {
          result = (result * caseNumOfN) % n;
          caseNumOfN = -1;
          contN = 1;
        }
        else if(contU != 1)
        {
          result = (result * caseNumOfU) % n;
          caseNumOfN = -1;
          contU = 1;
        }
      }
    }
  }

  if(isInvalidCharFound)
  {
    result = 0;
  }
  else if(contN > 1)
  {
    caseNumOfN = p[0][contN] + p[1][contN];
    caseNumOfN = caseNumOfN >= n ? caseNumOfN % n : caseNumOfN;
    result = (result * caseNumOfN) % n;
  }
  else if(contU > 1)
  {
    caseNumOfU = p[0][contU] + p[1][contU];
    caseNumOfU = caseNumOfU >= n ? caseNumOfU % n : caseNumOfU;
    result = (result * caseNumOfU) % n;
  }

  std::cout << (result % n) << std::endl;

  return 0;
}