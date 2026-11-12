s32 int_sqrt();

/* One Newton-Raphson step for the integer square root of `value`: refines the initial estimate
 * from int_sqrt() as guess + (value - guess*guess) / (2*guess). Returns 0 if the estimate is 0. */
s32 func_8002EA18(s32 value)
{
    s32 guess;

    guess = int_sqrt();
    if (guess == 0)
    {
        return 0;
    }
    if (guess)
    {
        return guess + (value - guess * guess) / (guess * 2);
    }
    else
    {
        return guess + (value - guess * guess) / (guess * 2);
    }
}
