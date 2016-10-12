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

# Set a custom option to determine whether to link to our own math library.
# This can be modified in the CMake GUI.
option(USE_MYMATH "Use custom math library" ON)

# Configure a header file to pass CMake settings to the source code.
configure_file(
  "${PROJECT_SOURCE_DIR}/Config.h.in" 
  "${PROJECT_BINARY_DIR}/Config.h"
)

# Add the binary tree to the search path for include files, so that we will find TutorialConfig.h.
include_directories("${PROJECT_BINARY_DIR}")

# If the user wants to use the custom math library, add it.
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# Add the executable and specify the libraries that it needs.
add_executable(CMakeDemo tutorial.cxx)
target_link_libraries(CMakeDemo ${EXTRA_LIBS})

# Add install targets.
install(TARGETS CMakeDemo DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)


# Set up tests.
#include(CTest)
 
# Does the application run?
#add_test(DemoRuns CMakeDemo 25) 

# Does it sqrt of 25?
#add_test(Demo25 CMakeDemo 25) 
#set_tests_properties(Demo25 PROPERTIES PASS_REGULAR_EXPRESSION “25 is 5”)

# Does it handle negative numbers?
#add_test(DemoNegative CMakeDemo -25)
#set_tests_properties(DemoNegative PROPERTIES PASS_REGULAR_EXPRESSION “-25 is 0”)

# Does it handle small numbers?
#add_test(DemoSmall CMakeDemo 0.0001)
#set_tests_properties(DemoSmall PROPERTIES PASS_REGULAR_EXPRESSION “0.0001 is 0.01”) 

# Does the usage message work?
#add_test(DemoUsage Tutorial)
#set_tests_properties(DemoUsage PROPERTIES PASS_REGULAR_EXPRESSION “Usage:.*number”)
