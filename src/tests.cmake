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