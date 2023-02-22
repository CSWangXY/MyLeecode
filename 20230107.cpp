/*
#include<iostream>
#include<vector>
using namespace std;
int findProphet(int n, vector<vector<int>>& trust) 
    {
		vector<int>  f(n+1);
      	vector<bool>  havechild(n+1);
      	for(int i=0; i<trust.size(); i++)
        {
          havechild[trust[i][0]] = true;
          
          f[trust[i][1]]++;
          
        }
      	for(int i=1; i<=n; i++)
        {
        	if(f[i]== n-1 && havechild[i] == false)
              return i;
        }
        return -1;
    }

int main()
{
    int n = 2;
    vector<vector<int>> trust{{1,2}};
    int ans = findProphet(n , trust);
    cout<<ans;
}*/

#include<iostream>
#include<string>
using namespace std;
int solution(int n, string s) 
{
  // 请添加具体实现
  int Mnum = 0;
  for(int i=0; i<n; i++)
  {
    if(s[i]=='M')
      Mnum++;
  }
  int x = 0;
  int j=0;
  for(; j<Mnum; j++)
  {
    if(s[j] == 'M')
      x++;
  }
  for(int k=Mnum; k<n; k++)
  {
  	int tmp = x;
    if(s[k-Mnum] == 'M' )
      tmp--;
    if(s[k] == 'M')
      tmp++;
    if(tmp > x)
      x = tmp;
  }
  return Mnum-x;
}

int main()
{
    int n= 4;
    string s = "FMFM";
    int ans = solution( n, s) ;
    cout<<ans;
}