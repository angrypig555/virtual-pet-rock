#!/bin/bash

# 1. Define the build directory
BUILD_DIR="out/build/win"
TFILE="windows-toolchain.cmake"

# 2. Create the directory if it doesn't exist
mkdir -p $BUILD_DIR

# 3. Configure the project
# -S . (Source is here) -B (Build goes there)
cmake -S . -B $BUILD_DIR -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=$TFILE

# 4. Build the project
# --build points to the folder containing the generated files
cmake --build $BUILD_DIR 
