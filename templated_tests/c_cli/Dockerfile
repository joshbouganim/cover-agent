FROM gcc:14

# Install CUnit and lcov for coverage reporting
RUN apt-get update && apt-get install -y libcunit1-dev lcov

# Copy source files into the container
COPY . /usr/src/myapp

# Set the working directory inside the container
WORKDIR /usr/src/myapp

# Compile the main calculator application with coverage options
RUN gcc -o calc main.c calc.c -lm -fprofile-arcs -ftest-coverage

# Compile the CUnit test application with coverage options
RUN gcc -o test_calc test_calc.c calc.c -lm -lcunit -fprofile-arcs -ftest-coverage

# Set the entrypoint to a script that runs tests and collects coverage
COPY ./run_tests_and_coverage.sh /usr/src/myapp
RUN chmod +x /usr/src/myapp/run_tests_and_coverage.sh
ENTRYPOINT ["/usr/src/myapp/run_tests_and_coverage.sh"]
CMD []