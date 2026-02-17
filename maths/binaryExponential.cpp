class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0) return 1;
        if (x == 0) return 0;

        long long pow = n;
        double num = 1;

        if (pow < 0) pow = -pow;

        while (pow > 0)
        {
            if (pow % 2 == 0)
            {
                pow /= 2;
                x = x * x;
            }
            else
            {
                pow -= 1;
                num = num * x;
            }
        }

        return (n > 0) ? num : 1 / num;
    }
};
