#include <bits/stdc++.h>

// std::unordered_set<std::string> graph;
std::unordered_map<std::string, std::set<std::pair<int, std::string>>> graph;
std::unordered_set<std::string> found;

/**
 * Goes backward from target, trying to find the easiest
 */
int shortestPath(std::string target, std::string from = "English")
{
    // std::priority_queue<std::pair<int, std::string>,std::vector<std::pair<int, std::string>> ,std::greater<std::pair<int, std::string>>> queue;
    std::queue<std::pair<int, std::string>> queue;
    std::unordered_set<std::string> seen;
    seen.reserve(graph.size());
    seen.emplace(target);
    queue.emplace(0, target);
    while (!queue.empty())
    {
        std::pair<int, std::string> curr = queue.front();
        queue.pop();
        // std::cout << "Node: " << curr.second << " | weight: " << curr.first << std::endl;
        if (curr.second == from)
        {
            found.insert(target);
            return curr.first;
        }
        if (found.find(curr.second) != found.end())
        {
            queue.emplace(curr.first, "English");
        }
        else
        {
            for (std::pair<int, std::string> edge : (graph.at(curr.second)))
            {
                if (seen.find(edge.second) == seen.end())
                {
                    queue.emplace(curr.first + edge.first, edge.second);
                    seen.emplace(edge.second);
                }
                // }
                // else
                // {
                //     queue.emplace(curr.first);
                // }
            }
        }
    }

    return -1;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> targets;
    targets.resize(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> targets[i];
        std::set<std::pair<int, std::string>> temp;
        graph.emplace(targets[i], temp);
    }

    for (int i = 0; i < m; i++)
    {
        std::vector<std::string> temp;
        temp.resize(3);
        std::cin >> temp[0] >> temp[1] >> temp[2];
        int weight = atoi(temp[2].c_str());

        for (int j = 0; j < 2; j++)
        {
            std::pair<int, std::string> pi;
            pi.first = weight;
            pi.second = temp[(j + 1) % 2];
            if (graph.find(temp[j]) == graph.end())
            {
                std::set<std::pair<int, std::string>> edges;
                edges.emplace(pi);
                graph[temp[j]] = edges;
            }
            else
            {
                graph[temp[j]].emplace(pi);
            }
        }
    }

    int total = 0;
    for (int i = 0; i < targets.size(); i++)
    {
        int temp = shortestPath(targets[i]);
        // std::cout << "temp: " << temp << std::endl;
        if (temp == -1)
        {
            total = -1;
            break;
        }
        total += temp;
    }
    if (total == -1)
    {
        std::cout << "Impossible";
    }
    else
    {
        std::cout << total;
    }

    // Code to print out the graph (check to make sure its correct)
    //  for (std::pair<std::string, std::set<std::pair<int, std::string>>> pi : graph)
    //  {
    //      std::cout << pi.first << " | ";
    //      for (std::pair<int, std::string> pi2 : pi.second)
    //      {
    //          std::cout << pi2.first << ":" << pi2.second << ", ";
    //      }
    //      std::cout << std::endl;
    //  }
}