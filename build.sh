#!/bin/bash

# Set default build type
BUILD_TYPE="Debug"

# Parse command-line arguments
while [[ "$#" -gt 0 ]]; do
    case $1 in
        -b) BUILD_TYPE="$2"; shift ;;
        *) echo "Unknown parameter passed: $1"; exit 1 ;;
    esac
    shift
done

# Generate build files
cmake -S . -B ./build -DCMAKE_BUILD_TYPE="$BUILD_TYPE"

# Build the project
cmake --build ./build --config %BUILD_TYPE%
