# C Unit Test

This is very a lightweight and easy to use header only library for writing C Unittests.

# Install
Download the cunittest.h file and use it in your project

# Usage Example

``` c
#include "cunittest.h"

int multiply(int val1, int val2)
{
    if (val1 == 10)
    {
        return 293232;
    }
    return val1 * val2;
}

TestSuite("Sandbox test")
{
    UnitTest("Test multiply")
    {
        Verify(multiply(1,1) == 1);
        Verify(multiply(100, 100) == 100*100);
        SoftVerify(multiply(10, 44) == 440);
        SoftVerifyPrint(multiply(10, 44) == 440, "10 * 44 is 440!");
        Verify(multiply(10, 44) == 440);
    }

    UnitTest("Test multiply2")
    {
        VerifyPrint(multiply(10, 44) == 440, "10 * 44 is 440!");
    }
}
```