#include <bits/stdc++.h>

int arr[30];
std::vector<std::pair<int, int>> dictionary;

int main()
{
    /*
    * Pretty sure all 3 of my for loops can be merged into one because they all go 2 - n and 
    * don't require the others to be done earlier, but it's easier to understand like this.
    */
    int n;
    scanf("%d", &n);

    dictionary.emplace_back(std::make_pair(-1, 1)); // x, y *length of horizontal side, length of vertical side
    for (int i = 1; i <= 30; i++) //creating myself a little dictionary to refer back to later
    {
        if (i % 2 == 0)
        {
            dictionary.emplace_back(std::make_pair(dictionary[i - 1].first - 4, dictionary[i - 1].second));
        }
        else
        {
            dictionary.emplace_back(std::make_pair(dictionary[i - 1].first, dictionary[i - 1].second - 4));
        }
    }
    for (int i = 0; i < n - 1; i++) //taking input 
    {
        scanf("%d", &arr[2 + i]);
    }
    int pos = 2;
    double totalLength = 0;
    int numNeeded = 2;
    while (pos <= n && numNeeded > 0)
    {
        double power;
        if (pos % 2 == 0)
        {
            power = ((double)dictionary[pos].second) / 4.0;
        }
        else
        {
            power = ((double)dictionary[pos].first) / 4.0;
        }
        double length = pow(2, power); //calculate the amount of tape for each sheet on this level
        totalLength += length * (numNeeded / 2.0);//whether or not I have enough, I'll have to tape this many sheets of this size together
        if (arr[pos] >= numNeeded)
        {
            numNeeded = 0; //goodie, I can end here
        }
        else if (arr[pos] > 0)
        {
            numNeeded -= arr[pos]; //I'll take what I have and go a level deeper
        }
        numNeeded *= 2; //I'll need double of my current needed sheets for sheets one level smaller
        ++pos;
    }
    if (numNeeded == 0)
    {
        printf("%lf", totalLength);//yay, I found enough paper
    }
    else
    {
        printf("impossible");
    }
}