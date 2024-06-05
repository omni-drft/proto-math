#!/bin/bash

echo -e "Creating Makefiles...\n"
premake5 gmake

echo -e "\nCompiling Release_x64...\n"
make config=release_x64

echo -e "\nCompiling Release_x86...\n"
make config=release_x86

echo -e "\nCompiling Debug_x64...\n"
make config=debug_x64

echo -e "\nCompiling Debug_x86...\n"
make config=debug_x86
