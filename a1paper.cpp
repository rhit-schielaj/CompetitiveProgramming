#include <bits/stdc++.h>

int arr[30];
std::vector<std::pair<int, int>> dictionary;

double recursive(int i){
    if(i>30){
        return -1;
    }
    if(arr[i] > 0){
        arr[i]--;
        return 0;
    }
    double power;
    if(i%2==1){
        power = ((double)dictionary[i].second)/4.0;
    }
    else{
        power = ((double)dictionary[i].first)/4.0;
    }
    double length = pow(2, power);
    double smaller = recursive(i+1);
    if(smaller == -1){
        return -1;
    }
    length += smaller;
    smaller = recursive(i+1);
    if(smaller == -1){
        return -1;
    }
    length+=smaller;
    return length;
}

int main(){

int n;
scanf("%d", &n);

dictionary.emplace_back(std::make_pair(-1, 1));
for(int i =1; i<=30; i++){
    if(i%2==0){
        dictionary.emplace_back(std::make_pair(dictionary[i-1].first-4, dictionary[i-1].second));
    }
    else{
        dictionary.emplace_back(std::make_pair(dictionary[i-1].first, dictionary[i-1].second-4));
    }
}

for(int i =0; i<n-1; i++){
    scanf("%d", &arr[2+i]); 
}
double length = recursive(1);
if(length == -1){
    printf("impossible\n");
}
else{
    printf("%.5f\n", length);
}
}