#include <bits/stdc++.h>

int main(){
/**
 * Solution to gearsandaxles problem on kattis (3.9 difficulty)
 */

std::unordered_map<int, std::multiset<double>> gears;
int n = 0;
scanf("%d", &n);
for(int i =0; i<n; i++){
    int size, teeth;
    scanf("%d %d", &size, &teeth);
    if(gears.find(size) == gears.end()){
        gears[size] = std::multiset<double>();
        gears[size].insert(log(teeth));
    }else{
        gears[size].insert(log(teeth));
    }
}
long double ratio = 0; 
for(auto& gear: gears){
    std::multiset<double> teeth = gear.second;
    while(teeth.size() > 1){//logs hurt my brain
        ratio += *teeth.rbegin();
        teeth.erase(--teeth.end());
        ratio -= *teeth.begin();
        teeth.erase(teeth.begin());
    }
}
printf("%.6Lf", ratio);

}