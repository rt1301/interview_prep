class Solution
{
public:
    int numSquares(int n)
    {
        if (ceil(sqrt(n)) == floor(sqrt(n)))
            return 1; //num is already a perfect square

        while (n % 4 == 0)
            n /= 4;

        if (n % 8 == 7)
        {             //the number will be of the form 4^a(8b+7) and will be sum of
            return 4; // 4 square numbers
        }

        for (int i = 1; i * i <= n; i++)
        {
            int temp = sqrt(n - (i * i)); //checking if the number is sum of 2 perfect squares
            if (temp * temp == n - (i * i))
            {
                return 2;
            }
        }
        return 3; // else return 3
    }
};