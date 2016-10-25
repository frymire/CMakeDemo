# CMakeDemo
Proof that I can use CMake to construct different build environments.

When generating to Eclipse CDT, it will likely complain that sh.exe is in the path, probably from the git folder. Either change the name of git folder while generating the build environment, or try the following from [here](https://github.com/filipwasil/fillwave/issues/17):

	> set PATH=%PATH:{path to git}\bin=%

If you want the funnySqrt() function to use the iterativeSqrt() function, edit the #ifdef syntax the bottom of funnySqrt.cxx.

To run CMake tests, first build the project, then run

	> ctest

from the build directory.