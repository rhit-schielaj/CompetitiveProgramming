#include <bits/stdc++.h>
//this one only works for finding size, fidnding the actual array it does wrong (potentially)
std::vector<int> lis(std::vector<int>& nums)
{
    // Binary search approach
    int n = nums.size();
    std::vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        }
        else {
            int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[low] = nums[i];
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n!=0){
        int num;
        std::vector<int> arr;
        arr.reserve(n);
        for(int i=0; i<n; i++){
            // printf("stuck");
            scanf("%d", &num);
            arr.emplace_back(num);
        }
        // printf("got here");
        std::vector<int> max = lis(arr);
        printf("%d", max.size());
        for(int i=0; i<max.size(); i++){
            printf(" %d", max[i]);
        }
        printf("\n");
        scanf("%d", &n);
    }
}
