class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        //bool ans = false;
        for(int i=0; i<m; i++)
        {
            //ans = binarysearch(0,n-1,matrix[i],target);
            int l=0, r=n-1;
            while(l<=r)
            {
            int mid = (l+r)/2;
            if(matrix[i][mid]==target)
            return true;
            else if(matrix[i][mid]<target)
            l = mid+1;
            else r = mid-1;
            }
            
        }
        return false;
    }

   
};