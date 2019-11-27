#include <iostream>
#include <vector>
#include <list>
#include <set>

int main(void)
{
  //freopen("601_div_2/c.txt", "r", stdin);
  int sizeOfP;
  std::vector<std::vector<std::set<int> > > triples;
  std::vector<int> elemCnt;
  std::vector<bool> isElemInResult;
  std::vector<int> result;

  std::cin >> sizeOfP;
  isElemInResult.resize(sizeOfP+1);
  triples.resize(sizeOfP+1);
  elemCnt.resize(sizeOfP+1);

  for(int i = 1; i < sizeOfP-1; i++)
  {
    std::set<int> s;
    int ele[3];
    for(int j = 0; j < 3; j++)
    {
      std::cin >> ele[j];
      s.insert(ele[j]);
      elemCnt[ele[j]]++;
    }
    for(int j = 0; j < 3; j++)
    {
      triples[ele[j]].push_back(s);
    }
  }

  std::vector<int> elemUseOnce, elemUseTwice;
  for(int i = 1; i < elemCnt.size(); i++)
  {
    switch(elemCnt[i])
    {
      case 1:
        elemUseOnce.push_back(i);
        break;
      case 2:
        elemUseTwice.push_back(i);
        break;
    }
  }

  int tripleElems[3];
  tripleElems[0] = elemUseOnce[0];
  std::set<int> s = triples[tripleElems[0]][0];
  s.erase(tripleElems[0]);
  for(int i = 0; i < s.size(); i++)
  {
    if(s.find(elemUseTwice[i]) != s.end())
    {
      tripleElems[1] = elemUseTwice[i];
      s.erase(tripleElems[1]);
      tripleElems[2] = *(s.begin());
      s.erase(tripleElems[2]);
      break;
    }
  }

  for(int i = 0; i < 3; i++)
  {
    result.push_back(tripleElems[i]);
    isElemInResult[tripleElems[i]] = true;
  }

  while(tripleElems[2] != elemUseOnce[1])
  {
    tripleElems[0] = tripleElems[1];
    tripleElems[1] = tripleElems[2];

    for(int i = 0; i < triples[tripleElems[0]].size(); i++)
    {
      std::set<int> s = triples[tripleElems[0]][i];
      if(s.find(tripleElems[1]) != s.end())
      {
        s.erase(tripleElems[0]);
        s.erase(tripleElems[1]);
        if(isElemInResult[*(s.begin())] == false)
        {
          isElemInResult[*(s.begin())] = true;
          tripleElems[2] = *(s.begin());
          result.push_back(tripleElems[2]);
          break;
        }
      }
    }
  }

  for(std::vector<int>::iterator it=result.begin(); it!=result.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}