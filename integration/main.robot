*** Settings ***
Name             Integration Test Suite
Documentation    A simple test suite that executes the 'main' binary with various inputs.
...              To run this, installation of ``requirements.txt``, typically into a python
...              virtual environment, is required. Run this test suite from the root of the
...              repository via ``robot integration/main.robot``
Library           Process
Library           String

*** Variables ***
# Path to target binary, again, from root of repository
${CLI_CMD}        build/bin/template_bin

*** Test Cases ***
Test Add and Divide Functionality
    [Documentation]    Template test case that tests various inputs for add and divide
    [Template]     Run Target Program
    sum 1 1        a+b == 2
    sum 4 5        a+b == 9
    divide 9 3     a/b == 3
    divide 6 6     a/b == 1

Test Divide By Zero
    [Documentation]    Tests division by zero corner case that is hard to test in UT environment
    ${result}=     Run Process    ${CLI_CMD}    divide    1    0    shell=${True}
    Should Contain    ${result.stderr.strip()}    Floating point exception

*** Keywords ***
Run Target Program
    [Documentation]    Runs 'main' binary, asserts no errors, and verifies output
    [Arguments]    ${args}    ${expected_output}

    # Args is treated as a string here, but if we split them by space, then they will be passed as individual arguments
    ${split_args}=    Split String    ${args}

    # Start a child process that executes our target binary, with the specified args. Capture stdout and stderr
    ${result}=     Run Process    ${CLI_CMD}    @{split_args}    shell=${True}

    # Assert that we see the expected output in stdout.
    # We expect to see the expected output string twice: One for the C++ "Template" class, and one
    # for the C "template_t" structure
    Should Contain X Times    ${result.stdout.strip()}    ${expected_output}    2

    # Assert that return code was 0, indicating no error
    Should Be Equal As Integers    ${result.rc}    0

    # Assert that stderr was empty
    Should Be Empty    ${result.stderr}

