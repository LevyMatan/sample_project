long long int maxSumLCM(int n)
{
    // LCM - Least Common Multiple
    // denote as lcm(a, b)
    // What does it mean?
    // There are p and k such that
    // a * p == b * k
    // those p and k are the minimal they can be.

    // I need to understand how derive numbers that their LCM is n....
    // Then just need to search for the maximum sum.
    // Lets do an example
    // Lets take n = 9
    // [1, 9], [3, 9]
    // Lets take n = 10
    // [1, 10], [2, 5]
    //
    // I am not sure how to do it
    // So I will iterate over all numbers upto sqrt(n)
    // why sqrt(n)?  because of
    long long int sum_of_distinct_nums = 0;
    int i = 1;
    while(i*i < n) // Case when n is odd
    {
        if(n % i == 0)
        {
            sum_of_distinct_nums += i;
            sum_of_distinct_nums += n/i;
        }
        i++;
    }
    if(i*i == n)
    {
        sum_of_distinct_nums += i;
    }
    return sum_of_distinct_nums;

}