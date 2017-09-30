# C Unit Test

This is very a lightweight and easy-to-use library for writing C unit tests.

# Install
Download the source with 

```
$ git clone https://github.com/ToolsDevler/cunittest.git
```

Include the cunittest.h into your main file and write your unit tests.

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
    UnitTest("multiply")
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

# Are there any limitations?
Yes. The TestSuite macro inserts an implementation of the main function which limits the number of suites to one per file.
