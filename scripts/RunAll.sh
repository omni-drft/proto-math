#!/bin/bash

echo -e "\nRunning tests for Release_x64...\n"
./test-bin/Release/x64/proto-math-tests

echo -e "\nRunning tests for Release_x86...\n"
./test-bin/Release/x86/proto-math-tests

echo -e "\nRunning tests for Debug_x64...\n"
./test-bin/Debug/x64/proto-math-tests

echo -e "\nRunning tests for Debug_x86...\n"
./test-bin/Debug/x86/proto-math-tests
