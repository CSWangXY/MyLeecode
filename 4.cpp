#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int getkth(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int end1, int end2, int k);
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int n = nums1.size();
    int m = nums2.size();
    if(n==0)
    return (nums2[(m-1)/2]+nums2[(m)/2])*0.5;
    if(m==0)
    return (nums1[(n-1)/2]+nums1[(n)/2])*0.5;
    int l = (m+n+1)/2;
    int r = (m+n+2)/2;
    int a = getkth(nums1,nums2,0,0,n-1,m-1,l);
    int b = getkth(nums1,nums2,0,0,n-1,m-1,r);
    return (a+b)*0.5;
}

int getkth(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int end1, int end2, int k)
{
    int len1 = end1 - start1 +1;
    int len2 = end2 - start2 +1;
    
    if(len1 > len2)
    {
        return getkth(nums2, nums1, start2, start1, end2, end1, k);
    }
    if(len1==0)
    return nums2[start2+k-1];
    if(k == 1)
    return min(nums1[start1],nums2[start2]);

    int i = start1 + min(k/2 , len1)-1;
    int j = start2 + min(k/2 , len2)-1;
    if(nums1[i] <= nums2[j])
    {
        return getkth(nums1, nums2, i+1,start2,end1,end2, k-(i-start1+1));
    }
    else
    {
        return getkth(nums1, nums2, start1,  j+1,end1, end2, k-(j-start2+1));
    }
}

int main()
{
    vector<int> nums1={},nums2={3,4};
    double a = findMedianSortedArrays(nums1,nums2);
    cout<<a;
}