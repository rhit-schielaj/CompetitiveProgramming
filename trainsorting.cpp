#include <bits/stdc++.h>

int main(){
int n = 0;
scanf("%d", &n);
std::priority_queue<int, std::vector<int>, std::less<int>> pqMax; //biggest at the top
std::priority_queue<int, std::vector<int>, std::greater<int>> pqMin;//smallest at the top
std::set<int> dict;
std::vector<int> order;
int sum = 0;

for(int i=0; i<n; i++){
int temp;
scanf("%d", &temp);
// dict.push_back(temp);
dict.insert(temp);
order.push_back(temp);
}

// std::sort(dict.begin(), dict.end());

for(int i=0; i<n; i++){
    
    int temp = order[i];
    std::pair<std::set<int>::iterator, bool> insertedmax = dict.insert(pqMax.top());
    std::pair<std::set<int>::iterator, bool> insertedmin = dict.insert(pqMin.top()); 
    std::set<int>::iterator it = dict.find(temp);
    
    
    // printf("1");
    int infront = std::distance(insertedmax.first, it);
    int behind = std::distance(it, insertedmin.first);
    dict.erase(temp);
    // printf("2");
    
    // printf("4");
    if((pqMax.empty() || pqMax.top() < temp) && (infront<1)){
        // printf("6");
        pqMax.push(temp);
        pqMin.push(temp);
        ++sum;
    }
    else if((pqMin.empty() || pqMin.top() > temp) && (behind <=1)){
        // printf("7");
        pqMax.push(temp);
        pqMin.push(temp);
        ++sum;
    }
    // printf("8");

}

printf("%d", sum);
}