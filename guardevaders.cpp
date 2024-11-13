#include <bits/stdc++.h>
using namespace std;

string g;
vector<bool> pos;

void changePos(){
    for(size_t i = 0; i<pos.size(); i++){
        if(g[i]!='R' && g[i+1]!='L') pos[i] = 1;
        else pos[i] = 0;
    }
    // fprintf(stderr, "g: %s\n",g.c_str());
}

void takePos(int ind){
    g[ind] = 'R';
    g[ind+1] = 'L';
    changePos();
    
}

int main(){
int n, p;
cin >> n >> p;
getline(cin, g);
getline(cin, g);
pos.assign(n-1, 0);
changePos();

int ind = (n/2) - 1;
while (p > 0){
    bool taken = false;
    for(int i=0; i<(n)/2; i++){
        // printf("INd: %d\n", ind+i);
        if(pos[ind + i]==1){
            takePos(ind + i);
            p--;
            taken = true;
            break;
        }
        if(!taken && pos[ind - i]==1){
            takePos(ind - i);
            p--;
            taken = true;
            break;
        }
    }
    if(!taken && n%2 == 1){
        if(pos[pos.size()-1]==1){
            takePos(pos.size()-1);
            p--;
            taken = true;
        }
        else{
            printf("0");
            return 0;
        }
    }
    else if(!taken){
        printf("0");
        // fprintf(stderr, "p: %d | g: %s\n", p, g.c_str());
        return 0;
    }
    // --p;
}
printf("1");

}