#include <bits/stdc++.h>

// // std::set<Computer> notInfected;

// struct Computer{
// std::vector<Computer*> connections;
// std::forward_list<Computer*>* notInfected;
// int isInfected = 0;
// int num;

// Computer(std::forward_list<Computer*>& list, int n){
//  notInfected = &list;
//  num = n;
// }

// bool matchComp(const Computer& comp){
//     return comp.num==num;
// }

// void addConnection(Computer& cmp){
//     connections.emplace_back(&cmp);
//     cmp.connections.emplace_back(this);
// }

// void infectNeighbors(){
//     for(Computer* temp : connections){
//         temp->infect();
//     }
// }

// void infect(){
//     if(!isInfected){
//         // fprintf(stderr, "Infecting: %d\n", num);
//         isInfected = 1;
//         notInfected->remove(this);
//         // for(Computer* temp : *notInfected){
//         //     fprintf(stderr, "Num in forward_list: %d\n", temp->num);
//         // }
//         // notInfected->remove_if(matchComp);
//         for(Computer* temp : connections){
//             temp->infectNeighbors();
//         }
//     }
// }

// };

// std::forward_list<Computer*> notInfected;

// int main(){
//     // std::set<Computer> temp;
//     // notInfected = temp;
//     std::vector<Computer> computers;
//     int n, m;
//     scanf("%d %d", &n, &m);
//     computers.reserve(n);
//     for(int i=0; i<n; i++){
//         Computer temp(notInfected, i+1);
//         computers.emplace_back(temp);
//     }

//     for(int i=0; i<computers.size(); i++){
//         notInfected.emplace_front(&computers[i]);
//     }

//     for(int i=0; i<m; i++){
//         int num1, num2;
//         // fprintf(stderr, "here2");
//         scanf("%d %d", &num1, &num2);
//         // fprintf(stderr, "here1");
//         computers[num1-1].addConnection(computers[num2-1]);
//     }
//     // fprintf(stderr, "here");
//     computers[0].infect();
//     // fprintf(stderr, "%d", notInfected.());
//     // fprintf(stderr, "Size of computers: %d\n", computers.size());
//     // for(auto i=0; i<computers.size(); i++){
//     //     fprintf(stderr, "Num in list: %d\n", computers[i].num);
//     // }
//     // for(Computer* temp : notInfected){
//     //     fprintf(stderr, "Num in forward_list: %d\n", temp->num);
//     // }
//     int numRequests = 0;
//     while(!notInfected.empty()){
//         Computer* temp = (*(notInfected.begin()));
//         // fprintf(stderr, "First not infected: %d\n", temp->num);
//         temp->infect();
//         numRequests++;
//     }
//     printf("%d", numRequests);
// }

const int MAX = 500001;
std::vector<std::vector<int>> adj(MAX);
std::vector<int> color(MAX, -1);

bool bfs(int v)
{
    std::queue<int> q;
    q.push(v);
    color[v] = 0;
    bool odd_cycle = false;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto u : adj[cur])
        {
            if (color[u] == -1)
            {
                color[u] = color[cur] == 0 ? 1 : 0;
                q.push(u);
            }
            else if (color[u] == color[cur])
            {
                odd_cycle = true;
            }
        }
    }
    return odd_cycle;
}

int main()
{
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;
    bool odd_cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            count++;
            if (bfs(i))
                odd_cycle = true;
        }
    }

    if (odd_cycle)
        printf("%d", count - 1);
    else
        printf("%d", count);
    return 0;
}