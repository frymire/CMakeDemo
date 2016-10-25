# First, add an executable to generate a table of values.
add_executable(MakeTable MakeTable.cxx)
 
# Generate the source code. The "OUTPUT ..." parameter specifies the output we expect to  
# generate. CMake will automatically mark it with the "GENERATED" source file property. 
# Specifying "DEPENDS MakeTable" forces it to build MakeTable before running the command.
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
)
 
# Add the binary directory to the search path for header files, so that the compiler 
# can find Table.h.
include_directories(${CMAKE_CURRENT_BINARY_DIR})
 
# Add the main library
add_library(MathFunctions funnySqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

# Specify how products should be placed in the install folder.
install(TARGETS MathFunctions DESTINATION bin)
install(FILES MathFunctions.h DESTINATION include)