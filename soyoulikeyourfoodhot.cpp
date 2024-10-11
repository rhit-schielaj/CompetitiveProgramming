#include <bits/stdc++.h>

/**
 * Solution for soyoulikeyourfoodhot problem on kattis (I hate this problem)
 */
int main(){
    double t1, pit, piz;
    scanf("%lf %lf %lf", &t1, &pit, &piz);
    int64_t t = (int64_t)std::ceil(10000*t1)/100;//Kill me now I hate floats
    int64_t p1 =(int64_t)std::ceil(10000*pit)/100;
    int64_t p2 = (int64_t)std::ceil(10000*piz)/100;
    int count = 0;

    if((p1 > t && p2 > t) && t>0){
        printf("none\n");
        return 0;
    }

    for(long long i=0; (p1*i)<=t; i++){//originally had a mod solution, but chose to be verbose instead
        int64_t temp = (t - i*p1);
        long long j = 0;
        while(p2*j < temp){
            j++;
        }
        if(temp==p2*j){
            count++;
            printf("%lld %lld\n", i, j);
        }
    }
    if(count == 0){
        printf("none");
    }
}