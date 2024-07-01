FROM gcc:14

# Install build tools
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y g++ cmake make lcov

# Install Google Test source
RUN apt-get install -y libgtest-dev

# Build Google Test
WORKDIR /usr/src/gtest
RUN cmake CMakeLists.txt
RUN make

# Copy the library files to a standard library location (if they exist)
RUN find . -type f -name "*.a" -exec cp {} /usr/lib \;

# Set up the project directory
WORKDIR /app
COPY . /app

# Build the project
RUN cmake .
RUN make

# Entry point runs the test and captures coverage data
ENTRYPOINT ["sh", "-c", "./test_calculator && \
                        lcov --capture --directory . --output-file coverage.info && \
                        lcov --remove coverage.info '/usr/*' '*/test_*' --output-file coverage_filtered.info && \
                        lcov --list coverage_filtered.info"]

# Command to run tests
CMD []
