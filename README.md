# c-unit-test


``` c++

TestSuite ("Protocol Basic Tests")
{
    UnitTest ("Basic stuff")
    {
        Verify(1 == 1);
        int i = srand(my_seed);
        // Is allowed to fail:
        SoftVerify(i % 2 == 0);

    }
    
    UnitTest ("Anythign else")
    {
        ...
    }
    
}

```