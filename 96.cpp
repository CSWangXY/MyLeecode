class Solution {
public:
   
    /*int numTrees(int n)
   {
       vector<int> G;
       G.push_back(1);
       G.push_back(1);
       for(int i=2;i<=n;i++)
       {
           int num = 0;
           for(int j = 1;j<=i;j++)
           {
               num = num + G[j-1]*G[i-j];
           }
           G.push_back(num);
       }
       return G[n];
   }*/

   int numTrees(int n)
   {
       if(n==0||n==1)
       return 1;
       else 
       {
           int num = 0;
           for(int i=1;i<=n;i++)
           {
               num = num + numTrees(i-1)*numTrees(n-i);
           }
           return num;
       }

   }
};