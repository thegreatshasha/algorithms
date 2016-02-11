#include <stdio.h>

static char symbols[] = {'+', '-', '*', '/'};
static float getSum(float test[], float ans, int operators[], int count)
{
        float prev, result = 0.0;
        int i;
        for (i = 0; i < count; ++i)
        {
            if (0 == operators[i])
            {
                prev = test[i];
                result += prev;
            }
            else if (1 == operators[i])
            {
                prev = -test[i];
                result += prev;
            }
            else if (2 == operators[i]) // multiplication
            {
                result -= prev;
                prev = prev*test[i];
                result += prev;
            }
            else // division
            {
                result -= prev;
                prev = prev/test[i];
                result += prev;
            }
        }
        return result;
}

static void findAnswerRecur(float test[], float ans, int len, int operators[], int count)
{
    float result = 0.0;
    int i;
    if (count == len)
    {
        float result = getSum(test, ans, operators, count);
        if (ans == result)
        {
            for (i = 0; i < len; ++i)
                printf("%c %.0f ", symbols[operators[i]], test[i]);
            printf(" = %.2f\n", ans);
        }
        return;
    }

    for  (i = 0; i < 4; ++i)
    {
        operators[count] = i;
        findAnswerRecur(test, ans, len, operators, count+1);
    }
 }


static void findAnswer(float test[], float ans, int len)
{
    int operators[4];
    int count = 0;
    int i;
    // only apply +/- at the very first
    for (i = 0; i < 2; ++i)
    {
        operators[count] = i;
        findAnswerRecur(test, ans, len, operators, count+1);
    }
}
