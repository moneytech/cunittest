
#include "foo.h"
#include "cunittest.h"

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
