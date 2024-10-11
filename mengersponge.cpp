#include <bits/stdc++.h>

int recursive(int L, int xnum, int xden, int ynum, int yden, int znum, int zden);

/*
* Solution to mengersponge problem on kattis (Fastest Solution)
*/
int main(){
    int L, xnum, xden, ynum, yden, znum, zden;
    scanf("%d %d %d %d %d %d %d", &L, &xnum, &xden, &ynum, &yden, &znum, &zden);
    xnum*=3;
    xden*=3;
    ynum*=3;
    yden*=3;
    znum*=3;
    zden*=3;
    printf("%d", recursive(L, xnum, xden, ynum, yden, znum, zden));
    return 0;
    
}

int recursive(int L, int xnum, int xden, int ynum, int yden, int znum, int zden){
    if(L==0){return 1;}
    int x3 = 3*xnum;
    int y3 = 3*ynum;
    int z3 = 3*znum;
    int x=0, y=0, z = 0;
    x = (x3)/xden;
    y = (y3)/yden;
    z = (z3)/zden;
    double dx = ((double)xnum)/((double)xden);
    double dy = ((double)ynum)/((double)yden);
    double dz = ((double)znum)/((double)zden);
    if(((dy>1.0/3.0 && dy<2.0/3.0) && (dx>1.0/3.0 && dx<2.0/3.0))||
    ((dz>1.0/3.0 && dz<2.0/3.0) && (dx>1.0/3.0 && dx<2.0/3.0))||
    ((dy>1.0/3.0 && dy<2.0/3.0) && (dz>1.0/3.0 && dz<2.0/3.0))){
        return 0;
    }

    xnum -= x*((double)xden/3.0);
    ynum -= y*((double)yden/3.0);
    znum -= z*((double)zden/3.0);
    znum*=3;
    xnum*=3;
    ynum*=3;
    L-=1;
    return recursive(L, xnum, xden, ynum, yden, znum, zden);
}