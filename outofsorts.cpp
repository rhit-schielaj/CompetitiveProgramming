#include <bits/stdc++.h>


std::vector<int> arr;

int checkBS(int index, int step){


return 0;
}

int main(){
int n, m, a, c, x;

scanf("%d %d %d %d %d", &n, &m, &a, &c, &x);
arr.reserve(n+1);
a = a%m;
c = c%m;
arr[0] = x;
for(int i=1; i<n+1; i++){
    long temp = ((long)((long)arr[i-1]*(long)a) + (long)c) % m;
    arr[i] = (int)temp;
}
fprintf(stderr, "&d\n", checkBS((n/2)+1, std::round(n/4)));
// for(int i=0; i<n+1; i++){
//     fprintf(stderr, "%d ", arr[i]);
// }

}