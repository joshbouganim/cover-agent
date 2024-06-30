#!/bin/bash

# Run the tests
./test_calc

# Capture coverage data for all files
lcov --capture --directory . --output-file coverage.info

# Remove coverage data for test files
lcov --remove coverage.info '*/test_calc.c' --output-file coverage.info

# Print coverage summary to the console
lcov --list coverage.info