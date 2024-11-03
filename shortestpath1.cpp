#include <bits/stdc++.h>

std::unordered_map<int, std::set<std::pair<int, int>>> graph; // first int of a pair is always weight
const int INF = std::numeric_limits<int>::max();
std::vector<int> shortestPath(int start, int n)
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;
    std::vector<int> dp(n, INF);
    std::unordered_set<int> seen;
    seen.reserve(graph.size());
    seen.emplace(start);
    queue.emplace(0, start);
    while (!queue.empty())
    {
        std::pair<int, int> curr = queue.top();
        queue.pop();
        if (dp[curr.second] < curr.first)
        {
            continue;
        }
        for (std::pair<int, int> edge : (graph.at(curr.second)))
        {
            int total = edge.first + curr.first;
            if (dp[edge.second] > total)
            {
                dp[edge.second] = total;
                queue.emplace(total, edge.second);
            }
        }
    }

    return dp;
}

int main()
{
    int n, m, q, s;
    int count = 0;
    while (true)
    {
        std::cin >> n >> m >> q >> s;
        if (n == 0 && m == 0 && q == 0 && s == 0)
        {
            return 0;
        }
        if (count != 0)
        {
            std::cout << std::endl;
        }
        std::vector<std::string> targets;
        graph.clear();
        for (int i = 0; i < n; i++)
        {
            std::set<std::pair<int, int>> edges;
            graph[i] = edges;
        }
        for (int i = 0; i < m; i++)
        {
            std::vector<std::string> temp;
            temp.resize(3);
            std::cin >> temp[0] >> temp[1] >> temp[2];
            int weight = atoi(temp[2].c_str());
            int first = atoi(temp[0].c_str());
            int second = atoi(temp[1].c_str());
            std::pair<int, int> pi = {weight, second};
            if (graph.find(first) == graph.end())
            {
                std::set<std::pair<int, int>> edges;
                edges.emplace(pi);
                graph[first] = edges;
            }
            else
            {
                graph[first].emplace(pi);
            }
        }
        std::vector<int> list = shortestPath(s, n);
        for (int i = 0; i < q; i++)
        {
            int to = 0;
            std::cin >> to;
            int result = list[to];
            if (to == s)
            {
                std::cout << 0 << std::endl;
            }
            else if (result == INF)
            {
                std::cout << "Impossible" << std::endl;
            }
            else
            {
                std::cout << result << std::endl;
            }
        }
    }
    return 0;
}