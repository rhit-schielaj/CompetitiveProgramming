#include <bits/stdc++.h>

struct House
{
    std::vector<House *> connected;
    int isConnected = 0;
    int num;

    House(int number)
    {
        num = number;
    }

    void addHouse(House &toConnect)
    {
        connected.emplace_back(&toConnect);
        toConnect.connected.emplace_back(this);
        if (isConnected)
        {
            toConnect.connect();
        }
        else if (toConnect.isConnected)
        {
            connect();
        }
    }

    void connect()
    {
        if (!isConnected)
        {
            isConnected = 1;
            for (House *temp : connected)
            {
                temp->connect();
            }
        }
    }
};

int main()
{
    std::vector<House> houses;
    int n, m;
    scanf("%d %d", &n, &m);
    houses.reserve(n);
    for (int i = 0; i < n; i++)
    {
        houses.emplace_back(House(i + 1));
    }

    houses[0].connect();
    for (int i = 0; i < m; i++)
    {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        houses[num1 - 1].addHouse(houses[num2 - 1]);
    }

    int numDisconnected;
    for (int i = 0; i < houses.size(); i++)
    {
        if (!houses[i].isConnected)
        {
            numDisconnected++;
            printf("%d\n", i + 1);
        }
    }
    if (numDisconnected == 0)
    {
        printf("Connected");
    }
}
