#include <bits/stdc++.h>
using namespace std;

struct rect
{
    long long W, H;

    rect(long long width, long long height)
    {
        W = width;
        H = height;
    }
};

struct rectComp
{
    bool operator()(rect a, rect b) const
    {
        // Custom comparison logic
        long long aBase = min(a.W, a.H);
        long long bBase = min(b.W, b.H);
        return aBase < bBase; // this sorts in ascending order
    }
};

priority_queue<rect, std::vector<rect>, rectComp> rects;

int main()
{
    long long W, H;
    int N;
    scanf("%lld %lld %d", &W, &H, &N);
    rects.emplace(W, H);
    // fprintf(stderr, "W: %lld, H: %lld, N:%d\n", W, H, N);
    vector<long long> squares(N, 0);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &squares[i]);
    }
    // for (int i = 0; i < N; i++)
    // {
    //     // fprintf(stderr, "%d: %lld | ", i, squares[i]);
    // }
    // fprintf(stderr, "\n");

    int ind = N - 1;
    long long num_used_squares = 0;
    while (ind >= 0 && !rects.empty())
    {
        // fprintf(stderr, "num squares: %lld\n", num_used_squares);
        rect temp = rects.top();
        long long size = 1;
        size = size << ind;
        if (size > temp.W || size > temp.H || squares[ind] == 0)
        {
            --ind;
            continue;
        }

        rects.pop();
        if (size == temp.W && size == temp.H)
        {
            ++num_used_squares;
            --squares[ind];
            continue;
        }
        if (temp.W <= temp.H)
        {
            if (size == temp.W)
            {
                long long amount = min(temp.H / size, squares[ind]);
                long long new_height = temp.H - size*amount;
                if (new_height != 0)
                {
                    rects.emplace(temp.W, new_height);
                }
                squares[ind] -= amount;
                num_used_squares += amount;
                if (squares[ind] == 0)
                {
                    --ind;
                }
                continue;
            }

            long long amount = min(temp.W / size, squares[ind]);
            long long temp_width = temp.W - size * amount;
            if (temp_width != 0)
            {
                rects.emplace(temp_width, temp.H);
            }
            // squares[ind] -= amount;
            // num_used_squares += amount;

            long long amount2 = min((temp.H / size) * amount, squares[ind] / amount);
            long long temp_height = temp.H - size * amount2;
            if (temp_width != temp.W && temp_height != 0)
            {
                rects.emplace(temp.W - temp_width, temp_height);
            }

            squares[ind] -= amount2 * amount;
            num_used_squares += amount2 * amount;

            if (squares[ind] == 0)
            {
                --ind;
            }
            continue;
        }
        else
        {
            if (size == temp.H)
            {
                long long amount = min(temp.W / size, squares[ind]);
                long long new_width = temp.W - size*amount;
                if (new_width != 0)
                {
                    rects.emplace(new_width, temp.H);
                }

                num_used_squares += amount;
                squares[ind] -= amount;
                if (squares[ind] == 0)
                {
                    --ind;
                }
                continue;
            }
            long long amount = min(temp.H / size, squares[ind]);
            long long temp_height = temp.H - size * amount;
            if (temp_height != 0)
            {
                rects.emplace(temp.W, temp_height);
            }

            // num_used_squares += amount;
            // squares[ind] -= amount;

            long long amount2 = min((temp.W / size) * amount, squares[ind] / amount);
            long long temp_width = temp.W - size * amount2;
            if (temp_height != temp.H && temp_width != 0)
            {
                rects.emplace(temp.H - temp_height, temp_width);
            }
            squares[ind] -= amount2 * amount;
            num_used_squares += amount2 * amount;

            if (squares[ind] == 0)
            {
                --ind;
            }
            continue;
        }
    }

    if (rects.empty())
    {
        printf("%lld", num_used_squares);
    }
    else
    {
        printf("-1");
        // fprintf(stderr, "rects topW = %lld, topH = %lld", rects.top().W, rects.top().H);
    }
}