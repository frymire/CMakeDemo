# Set up tests. 
include(CTest)
 
# Add a command to the build process that automatically runs tests whenever CMakeDemo is built.
add_custom_command(
	TARGET CMakeDemo
	POST_BUILD 
	COMMAND ctest
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
	COMMENT "Automatically testing CMakeDemo for the new build..." 
	VERBATIM
)
	

# Does the application run?
add_test(CMakeDemo-Runs CMakeDemo 25) 

# Does the usage message work?
add_test(CMakeDemo-Usage CMakeDemo)
set_tests_properties(CMakeDemo-Usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")

# Define a macro to simplify adding tests.
macro(doTest name arg result)

	# Add the test and set its expected behavior.
	add_test(CMakeDemo-${name} CMakeDemo ${arg})
	set_tests_properties(CMakeDemo-${name} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
	
endmacro()

# Use the macro to add 3 more tests.
doTest(25 25 "25 is 5")
# doTest("Negative" -25 "-25 is 0")
doTest("Small" 0.0001 "0.0001 is 0.01")