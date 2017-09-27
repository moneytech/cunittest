#ifndef CUNITTEST_H

/**
 * C99 Unit Test
 *
 * This code can be used as whole or parts of it in any way you want. There are 
 * totally NO restrictions to it.
 * 
 * Yes really!
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//-----------------------------------------------------
//-- Configuration

#ifndef NULL
#define NULL 0
#endif

//-----------------------------------------------------
//-- Constants

const int cunittest_TestSuccess = 1;
const int cunittest_TestError = 0;

int __TestResult = 1;


//-----------------------------------------------------
//-- Macros

#define TestErrorExit __TestResult = cunittest_TestError; return

#define TestSuite(name) \
int __test_main(int argc, char *argv[], int *__test_result, int *__failed_tests, int *__test_count); \
int main(int argc, char *argv[]) \
{ \
    int __cunittest_error_code = 0; \
    char *__cunittest_error; \
    __cunittest_error_code = __cunittest_init(argc, argv, &__cunittest_error); \
    if (__cunittest_error_code != cunittest_TestSuccess) \
    { \
        printf("Error while initializing cunittest: %s\n", __cunittest_error); \
        return -1; \
    } \
    __cunittest_intro(#name); \
    int testResult = 0; \
    int failedTests = 0; \
    int testCount = 0; \
    __test_main(argc, argv, &testResult, &failedTests, &testCount); \
    __cunittest_error_code = __cunittest_cleanup(&__cunittest_error); \
    if (__cunittest_error_code != cunittest_TestSuccess) \
    { \
        printf("Error while initializing cunittest: %s\n", __cunittest_error); \
        return -1; \
    } \
    __cunittest_stats(testResult, failedTests, testCount); \
    \
} \
int __test_main(int argc, char *argv[], int *__test_result, int *__failed_tests, int *__test_count) \


#define UnitTest(name) printf("Testing %s\n", #name); if (__cunittest_is_test_enabled(argc, argv, #name) == 1) { (*__test_count)++; } \
if (__cunittest_is_test_enabled(argc, argv, #name) == 1)

//-- Verify and fail if false
#define Verify(condition) if ( ! condition ) { (*__failed_tests)++; printf("Verify failed: %s\n", #condition); }
#define VerifyPrint(condition, message) if ( ! condition ) { (*__failed_tests)++; printf("Verify failed: %s\n%s\n", #condition, message); }

//-- Verify without failing test
#define SoftVerify(condition) if ( ! condition ) { (*__failed_tests)++; printf("Soft verify failed: %s\n", #condition); }
#define SoftVerifyPrint(condition, message) if ( ! condition ) { (*__failed_tests)++; printf("Soft verify failed: %s\n%s\n", #condition, message); }

#ifndef SKIP_MAIN


//-----------------------------------------------------
//-- Implementation

int __cunittest_init(int argc, char *argv[], char **__cunittest_error)
{
    // Nothing yet
    return cunittest_TestSuccess;
}

int __cunittest_intro(char *name)
{
    printf("Init test suite %s\n", name);
    return cunittest_TestSuccess;
}

int __cunittest_cleanup(char **__cunittest_error)
{
    // Nothing yet
    return cunittest_TestSuccess;
}

int __cunittest_stats(int __test_result, int __failed_tests, int __test_count)
{
    printf("%d of %d passed. %d failed.\n", __test_count - __failed_tests, __test_count, __failed_tests);

    return 1;
}


int __cunittest_is_test_enabled(int argc, char *argv[], char *name)
{
    int i = 0;
    
    if (argc < 2 || (argc == 2 && argv[1][0] == '*'))
    {
        return 1;
    }
    else
    {
        for (i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], name) == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

#endif // SKIP_MAIN

#ifdef CUNITTEST_TEST

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

#endif 

#endif // CUNITTEST_H
