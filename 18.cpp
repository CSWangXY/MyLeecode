 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 
 int main() 
{
        int a[] = {-1,0,1,2,-1,-4};
        vector<int> nums(a,a+6);
        int target = -1;
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if((long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)
            break;
            if((long)nums[i]+nums[n-1]+nums[n-2]+nums[n-3]<target)
            break;
            if(i==0 || nums[i]!=nums[i-1])
            {
                for(int j=i+1;j<n-2;j++)
                {
                    int p = j+1;
                    int q = n-1;
                    if((long)nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)
                    continue;
                    if((long)nums[i]+nums[j]+nums[n-1]+nums[n-2]<target)
                    continue;
                    if(j==i+1 || nums[j]!=nums[j-1])
                    {
                        while(p<q)
                        {
                            if((long)nums[i]+nums[j]+nums[q]+nums[p]==target)
                            {
                                vector<int> tmp;
                                tmp.push_back(nums[i]);
                                tmp.push_back(nums[j]);
                                tmp.push_back(nums[p]);
                                tmp.push_back(nums[q]);
                                result.push_back(tmp);
                                 while(p<q&&nums[p+1]==nums[p])
                                p++;
                                
                                while(p<q&&nums[q-1]==nums[q])
                                q--;
                                if(p<q)
                                {
                                    p--;q--;
                                }
                            }
                           
                            if((long)nums[i]+nums[j]+nums[q]+nums[p]>target)
                            q--;
                            else if((long)nums[i]+nums[j]+nums[q]+nums[p]<target) 
                            p++;
                            
                        }
                    }
                }
            }
        }
    for(int i = 0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<"  ";
        }
        cout<<endl;
    }
}  
    