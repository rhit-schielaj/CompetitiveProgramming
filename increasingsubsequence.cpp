#include <bits/stdc++.h>
//something is wrong with this code idk what
std::vector<int> lis(std::vector<int>& arr)
{
    int n = arr.size();
    std::vector<int> dp(n, 1);
    std::vector<std::vector<int>> dpMem;

    for(int i =0; i< n; i++){
        std::vector<int> temp {arr[i]};
        dpMem.emplace_back(temp);
    }

    for (int i = 1; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            // printf("Prev: %d | Cur: %d\n", arr[prev], arr[i]);
            if (arr[i] > arr[prev] && dp[i] < dp[prev] + 1) {
                // printf("It liked %d and %d: ", arr[prev], arr[i]);
                dp[i] = dp[prev] + 1;
                std::vector<int> temp = dpMem[prev];
                temp.emplace_back(arr[i]);
                // for(int trythis : temp){
                //     printf(" %d", trythis);
                // }
                // printf("\n");
                dpMem[i] = temp;
            }
            else if (arr[i] > arr[prev] && dp[i] == dp[prev] + 1) {
                int first = dpMem[i][dpMem[i].size()-2];
                int second = dpMem[prev][dpMem[prev].size()-1];
                if(first > second){
                    dpMem[i][dpMem[i].size()-2] = second;
                }
            }
        }
    }
    std::vector<int> max;
    int maxVal = 0;
    for(std::vector<int>& temp : dpMem){
        if(temp.size() > maxVal){
            maxVal = temp.size();
            max = temp;
        }
        if(temp.size() == maxVal){
            if(temp[maxVal-1] < max[maxVal-1]){
                max = temp;
            }
        }
    }
    return max;
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
