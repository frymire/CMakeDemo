

cmake_minimum_required (VERSION 3.10)

# Initialize the project, and set variables to represent its version 
# (CMakeDemo_VERSION_MAJOR, CMakeDemo__VERSION_MINOR).
project(CMakeDemo VERSION 1.2)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Import the CMake check_function_exists macro to check whether this system provides
# log and exp functions. Run these before the following configure_file command, so 
# that HAVE_LOG and HAVE_EXP are properly set in the config file.
include(CheckFunctionExists)
check_function_exists(log HAVE_LOG)
check_function_exists(exp HAVE_EXP)

# Set a custom option to determine whether to link to our own math library. This 
# can be modified in the CMake GUI. Specifying "ON" here just sets the default.
option(USE_MYMATH "Use custom math library" ON)

# You could override the user's choice in the GUI like this.
# set(USE_MYMATH ON)

# Configure a header file to pass CMake settings to the source code.
configure_file(
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
)

# Add the binary tree to the search path for include files, so that we will find Config.h.
include_directories(CMakeDemo PUBLIC "${PROJECT_BINARY_DIR}")

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

# Now we want to run tests.cmake as a module to this CMakeLists.txt file. We could  
# do this with an explicit "include(tests.cmake)" call, but instead, we'll append  
# the directory where it lives to the CMAKE_MODULE_PATH variable. This allows us to    
# include "tests", since CMake will automatically look for .cmake files. 
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})
include(tests)
