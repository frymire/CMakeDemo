cmake_minimum_required (VERSION 3.6.2)
project(CMakeDemo)

# Set variables to represent the project version number.
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

# Import the CMake check_function_exists macro to check whether this system provides
# log and exp functions. Run these before the following configure_file command, so 
# that HAVE_LOG and HAVE_EXP are properly set in the config file.
include(CheckFunctionExists)
check_function_exists(log HAVE_LOG)
check_function_exists(exp HAVE_EXP)

# Set a custom option to determine whether to link to our own math library. This 
# can be modified in the CMake GUI. Specifying "ON" here just sets the default.
option(USE_MYMATH "Use custom math library" ON)

# Configure a header file to pass CMake settings to the source code.
configure_file(
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
)

# Add the binary tree to the search path for include files, so that we will find Config.h.
include_directories("${PROJECT_BINARY_DIR}")

# If the user wants to use the custom math library, add it.
if (USE_MYMATH)
  include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory(MathFunctions)
  set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# Add the executable and specify the libraries that it needs.
add_executable(CMakeDemo CMakeDemo.cxx)
target_link_libraries(CMakeDemo ${EXTRA_LIBS})

# Add install targets.
install(TARGETS CMakeDemo DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/Config.h" DESTINATION include)


# Set up tests. 
include(CTest)
 
# Does the application run?
add_test(CMakeDemo-Runs CMakeDemo 25) 

# Does the usage message work?
add_test(CMakeDemo-Usage CMakeDemo)
set_tests_properties(CMakeDemo-Usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")

# Define a macro to simplify adding tests.
macro(do_test name arg result)
	add_test(CMakeDemo-${name} CMakeDemo ${arg})
	set_tests_properties(CMakeDemo-${name} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)

# Use the macro to add 3 more tests.
do_test(25 25 "25 is 5")
do_test("Negative" -25 "-25 is 0")
do_test("Small" 0.0001 "0.0001 is 0.01")
