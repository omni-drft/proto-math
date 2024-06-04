@echo off
REM Script to run a program from a specified path

echo Compiling debug version...
CALL make config=debug_x64
echo Compiling complete!
echo Compiling release version...
CALL make
echo Compiling complete!

REM Set the path to the executable
SET PROGRAM_PATH1="test-bin\Debug\x64\proto-math-tests.exe"
SET PROGRAM_PATH2="test-bin\Release\x64\proto-math-tests.exe"

REM Check if the program exists
IF EXIST "%PROGRAM_PATH1%" (
    echo Running debug version...
    CALL "%PROGRAM_PATH1%"
) ELSE (
    echo Release version not found
)

IF EXIST "%PROGRAM_PATH2%" (
    echo Running release version...
    CALL "%PROGRAM_PATH2%"
) ELSE (
    echo Debug version not found
)