#include <iostream>
#include <vector>
#include <map>

using namespace std;
std::vector<int> counts;

void domainAuction(std::vector<std::string> websites) 
{
  std::vector<std::string> domains;
  std::map<std::string, int> domainCount;
  for (auto website : websites) 
  {
    cout<<website<<endl;
    cout<<websites.size()<<endl;
    size_t i = 0;
    cout<<"uno "<<website<<endl;
    while (website.substr(i, 2) != "://") 
    {
      i++;
    }
    cout<<"uno .."<<website<<endl;
    i += 3;
    while (i < website.size() && website[i] != '/') 
    {
      i++;
    }
    size_t j = i - 1;
    int cnt = 0;
    while (website[j] != '/') 
    {
      cnt += website[j] == '.';
      if (cnt == 2) 
      {
        break;
      }
      j--;
    }
    cout<<website<<endl;
    std::string domain = website.substr(j+1, i - j  +1);
    domains.push_back(domain);
    domainCount[domain]++;
    cout<<domain<<endl;
  }
  
  for (const std::string& domain : domains) {
    counts.push_back(domainCount[domain]);
  }
  //return counts;
}

int main()
{
  vector <string> websites={"http://codefights.com","https://uk.domainmaster.com","https://uk.domainmaster.com/websites/website-builder","https://in.domainmaster.com"};
  domainAuction(websites);
  for( auto e: counts)
    cout<<e<<" ";
  cout<<endl;
  return 0;
}
