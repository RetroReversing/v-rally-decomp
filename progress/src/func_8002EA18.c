s32 func_8002D2A0();

/* One Newton-Raphson step for the integer square root of `value`: refines the initial estimate
 * from func_8002D2A0() as guess + (value - guess*guess) / (2*guess). Returns 0 if the estimate is 0. */
s32 func_8002EA18(s32 value)
{
    s32 guess;

    guess = func_8002D2A0();
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
