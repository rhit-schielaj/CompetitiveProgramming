#include <bits/stdc++.h>
using namespace std;

// Basic rectangle class
struct rect
{
    long long W, H;

    rect(long long width, long long height)
    {
        W = width;
        H = height;
    }
};

// Basic rectangle comparator for max-heap based off the smallest rectangle side
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
    // place original large rectangle
    rects.emplace(W, H);
    vector<long long> squares(N, 0); // create my array of squares
    // fill array of squares
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &squares[i]);
    }
    int ind = N - 1;
    long long num_used_squares = 0;
    // Begin filling rectangles with squares
    while (ind >= 0 && !rects.empty())
    {   
        //peek at the top rectangle to see some stuff about it (will be the largest rectangle)
        rect temp = rects.top();
        long long size = 1;
        size = size << ind; //create size of current squares based off index in array

        // keep lowering index until squares that can fit in the current largest rectangle
        if (size > temp.W || size > temp.H || squares[ind] == 0)
        {
            --ind;
            continue;
        }

        rects.pop(); //we now have a rectangle and a square that can fit in it so we pop it off the queue

        //if current square is the same size as the rectangle we popped
        if (size == temp.W && size == temp.H)
        {
            ++num_used_squares;
            --squares[ind];
            continue;
        }


        //if Width is the smaller side
        if (temp.W <= temp.H)
        {
            if (size == temp.W)//squares are the size of width, will be a line of squares
            {   

                long long amount = min(temp.H / size, squares[ind]); //find amount of squares in line (min of 1)
                long long new_height = temp.H - size * amount;
                if (new_height != 0) //check to make sure that the line of squares didn't completely fill up rectangle
                {
                    rects.emplace(temp.W, new_height);
                }
                squares[ind] -= amount; //adjust num of squares we have
                num_used_squares += amount; //adjust num of squares used
                if (squares[ind] == 0) //if we have no more squares of this size, we will go down in index
                {
                    --ind;
                }
                continue; //we filled this rectangle as much as possible, so continue to next rectangle
            }

            long long amount = min(temp.W / size, squares[ind]); //find num of squares that fit in the width
            long long temp_width = temp.W - size * amount;
            if (temp_width != 0) //if squares didn't fill up the whole width, then there will be a long rectangle of the entire height added back to queue
            {
                rects.emplace(temp_width, temp.H);
            }

            long long amount2 = min((temp.H / size) * amount, squares[ind] / amount); //find if multiple of these squares can also fit in the height
            long long temp_height = temp.H - size * amount2;
            if (temp_width != temp.W && temp_height != 0) //if squares didn't full fill up the height and we placed some on the width, then add the rectangle left over
            {
                rects.emplace(temp.W - temp_width, temp_height); //rectangle added that is the left over height and the original width minus the width of the other rectangle we added
            }

            squares[ind] -= amount2 * amount; //count up all the squares we used and subtract/add them from the counters
            num_used_squares += amount2 * amount;

            if (squares[ind] == 0) //check to see if we have squares left at this index
            {
                --ind;
            }
            continue; //we done with this rectangle, so continue to next one
        }
        //if height is the smaller side (mirror of width)
        else
        {
            if (size == temp.H)
            {
                long long amount = min(temp.W / size, squares[ind]);
                long long new_width = temp.W - size * amount;
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

    if (rects.empty()) // if we filled all the rectangles
    {
        printf("%lld", num_used_squares);
    }
    else
    {
        printf("-1");
        // fprintf(stderr, "rects topW = %lld, topH = %lld", rects.top().W, rects.top().H);
    }
}