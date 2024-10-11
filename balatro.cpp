#include <bits/stdc++.h>

/**
 * Pause on this - I'm not smart enough on my own
 */

std::vector<Card> cards;
int k = 0;

struct Card{
    char type;
    int value;

    Card(char type, int value){
        this->type = type;
        this->value = value;
    }
};

struct CompareCard{
    bool operator()(Card const& c1, Card const& c2){
        return c1.value < c2.value;
    }
};

long long maxSequence(int ind, int len){
    long long sum = 0;
    int mults = 0;

    for(int i = ind; i<ind+len; i++){
        if(cards[i].type == 'a'){
            sum += cards[i].value;
        }
        else{
            if(mults < k){
                sum *= cards[i].value;
                ++mults;
            }
        }
    }
    
    return sum;
}

int main(){

int n=0;
scanf("%d %d", &n, &k);

cards.reserve(n);

for(int i =0; i<n; i++){
    char type;
    int value;
    scanf("%c %d", &type, &value);
    cards.emplace_back(Card(type, value));
}

for(int i =1; i<n; i++){
    long long max = 0;
    for(int j = 0; j+i<n; j++){
        long long temp = maxSequence(j, j+i);
        if ( temp > max){
            max = temp;
        }
    }
    printf("%lld\n", max);
}


}