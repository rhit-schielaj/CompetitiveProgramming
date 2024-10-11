#include <bits/stdc++.h>


/**
 * Solution for blueberrywaffle problem on kattis (Elegant solution)
 */
int main(){
    uint64_t f, r;
    scanf("%llu %llu", &r, &f);
    int mod = f % r;
    int up = (f/r)%2;
    double amount = (double)r/2.0;
    
    if(mod > amount){
        up = (up+1)%2;
    }
    if(up){
        printf("down");
    }
    else{
        printf("up");
    }
}