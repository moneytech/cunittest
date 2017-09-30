#ifndef CUNITTEST_H

/**
 * Lightweight unit test library for C
 *
 * This code can be used as whole or parts of it in any way you want. There are 
 * totally NO restrictions to it.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
 * SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//-----------------------------------------------------
//-- Configuration

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif // TRUE

//-----------------------------------------------------
//-- Constants

const int cunittest_TestSuccess = 1;
const int cunittest_TestError = 0;

//-----------------------------------------------------
//-- Messages

const char *cunittest_Message_Intro = "Initialize test suite: %s\n";
const char *cunittest_Message_Stats = "%d of %d passed. %d failed.\n";

const char *cunittest_Message_ExecuteUnitTest = "Unit test: %s\n";

const char *cunittest_Message_VerifyFailed = "Verify failed %s\n";
const char *cunittest_Message_VerifyFailedWithMessage = "Verify failed %s\n%s\n";
const char *cunittest_Message_SoftVerifyFailed = "Soft verify failed %s\n";
const char *cunittest_Message_SoftVerifyFailedWithMessage = "Soft verify failed %s\n%s\n";


//-----------------------------------------------------
//-- API

// Sets the error state and returns from the test function.
#define TestErrorExit *__test_result = cunittest_TestError; return

// Initializes a test suite (only one per file!) where unit tests can be spawned.
#define TestSuite(name) \
void __test_main(int argc, char *argv[], int *__test_result, int *__failed_tests, int *__test_count); \
int main(int argc, char *argv[]) \
{ \
    int cunittest_error_code = 0; \
    char *cunittest_error; \
    printf(cunittest_Message_Intro, #name); \
    int testResult = 0; \
    int failedTests = 0; \
    int testCount = 0; \
    __test_main(argc, argv, &testResult, &failedTests, &testCount); \
    printf(cunittest_Message_Stats, testCount - failedTests, testCount, failedTests); \
    \
} \
void __test_main(int argc, char *argv[], int *__test_result, int *__failed_tests, int *__test_count) \

// Creates a new unit test which is only executed if it is enabled.
#define UnitTest(name) printf(cunittest_Message_ExecuteUnitTest, #name); if (cunittest_is_test_enabled(argc, argv, #name) == 1) { (*__test_count)++; } \
if (cunittest_is_test_enabled(argc, argv, #name) == 1)

// Verify and fail if false
#define Verify(condition) if ( ! (condition) ) { (*__failed_tests)++; printf(cunittest_Message_VerifyFailed, #condition); }

// Verify and fail with defined message
#define VerifyPrint(condition, message) if ( ! (condition) ) { (*__failed_tests)++; printf(cunittest_Message_VerifyFailedWithMessage, #condition, message); }

// Verify without failing
#define SoftVerify(condition) if ( ! (condition) ) { (*__failed_tests)++; printf(cunittest_Message_SoftVerifyFailed, #condition); }

// Verify without failing with defined message
#define SoftVerifyPrint(condition, message) if ( ! (condition) ) { (*__failed_tests)++; printf(cunittest_Message_SoftVerifyFailedWithMessage, #condition, message); }

/**
 * Checks if the name of a unit test has been activated by passing it as command line argument.
 * 
 * If no argument has been passed, all tests are enabled by default.
 */
static int cunittest_is_test_enabled(int argc, char *argv[], char *name)
{
    int i = 0;
    if (argc < 2 || (argc == 2 && argv[1][0] == '*'))
    {
        return TRUE;
    }
    else
    {
        for (i = 1; i < argc; i++)
        {
            if (argv[i][0] != '-' && strcmp(argv[i], name) == 0)
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

#endif // CUNITTEST_H
