#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {
    public:
    vi p, rank, setSize;
    int numSets;

    UnionFind(int N) {
        p.assign(N, 0); for(int i=0; i<N; i++) p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
    }

    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
    int numDisjointSets () {return numSets;}
    int sizeOfSet(int i){return setSize[findSet(i)];}

    void unionSet(int i, int j){
        if(isSameSet(i, j)){return;}
        int x = findSet(i), y=findSet(j);
        if(rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if(rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    UnionFind UF(n);
    int count = 0;
    int flag = 0;
    for(int i = 0; i<m; i++){
        if(UF.numSets == 1 && !flag){
            printf("%d\n", count);
            flag = 1;
        }
        int e1, e2;
        scanf("%d %d", &e1, &e2);
        UF.unionSet(--e1, --e2);
        count++;
    }
    if(!flag){
        if(UF.numSets == 1){
        printf("%d\n", count);
    }
    else{
        printf("-1\n");
    }
    }
}