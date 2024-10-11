#include <bits/stdc++.h>

/*
*Solution for areyoulistening problem on kattis (Fastest Solution)
*/
struct tower{
    long long x;
    long long y;
    long long r;
    long long d;
};

int main(){
    long long x, y, n;
    scanf("%lld %lld %lld", &x, &y, &n);
    struct tower towers[n];
    for(int i=0; i<n; i++){
        scanf("%lld %lld %lld", &towers[i].x, &towers[i].y, &towers[i].r);
    }
    long long smallest1 = LLONG_MAX;
    long long smallest2 = LLONG_MAX;
    long long smallest3 = LLONG_MAX;
    for(struct tower t : towers){
        t.d = (long long)sqrt(pow(x-t.x,2)+pow(y-t.y,2));
        long long dis = t.d - t.r;
        if(dis < smallest1){
            smallest3 = smallest2;
            smallest2 = smallest1;
            smallest1 = t.d-t.r;
        }
        else if(dis < smallest2){
            smallest3 = smallest2;
            smallest2 = t.d-t.r;
        }
        else if(dis < smallest3){
            smallest3 = t.d - t.r;
        }
    }
    if(smallest3 < 0){smallest3 = 0;}
    printf("%lld", smallest3);

}