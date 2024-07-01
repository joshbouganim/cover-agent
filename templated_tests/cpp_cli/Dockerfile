FROM ubuntu:20.04

# Install build tools
RUN apt-get update && apt-get install -y g++ cmake make

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

# Command to run tests
CMD ["./test_calculator"]
