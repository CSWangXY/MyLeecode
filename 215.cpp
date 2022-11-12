#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &nums, int l, int r, int kk)
{
    if (l < r)
    {
        // int k = rand()%(r-l+1)+l;
        // swap(nums[r] , nums[k]);
        int mid = (l + r) / 2;
        int k;
        if (nums[mid] >= nums[l] && nums[mid] <= nums[r])
            k = mid;
        else if (nums[mid] < nums[l] && nums[l] < nums[r])
            k = l;
        else
            k = r;
        swap(nums[r], nums[k]);
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; j++)
        {
            if (nums[j] > pivot)
            {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        if (kk == i + 2)
            return nums[r];
        swap(nums[i + 1], nums[r]);
        partition(nums, l, i, k);
        partition(nums, i + 2, r, k);
    }
    return -1;
}

int findKthLargest(vector<int> &nums, int k)
{
    int n = partition(nums, 0, nums.size() - 1, k);
    if (n != -1)
        return n;
    else
        return nums[k - 1];
}

int main()
{
    int kk = 1;
    vector<int> a{3, 3, 3, 3, 4, 3, 3, 3, 3};
    cout << findKthLargest(a, kk);
}