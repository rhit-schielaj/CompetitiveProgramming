#include <bits/stdc++.h>

int main(){
int n = 0;
scanf("%d", &n);
for(int i=0; i<n; i++){
    int num = 0;
    scanf("%d", &num);
    int arr[num];
    for(int i =0; i < num; i++){
        scanf("%d", arr+i);
    }
    int sum = arr[0];
    char returnVal[num+1];
    memset(returnVal, num+1, 0);
    returnVal[0] = 'U';
    int ind = 1;
    while(true){
    int temp = sum;
    for(int i=ind; i<num; i++){
        temp = sum - arr[i];
        if(temp > 0){
            sum = temp;
            continue;
        }
    }
    if temp = 0;
    }
}
}