# CMakeDemo
Proof that I can use CMake to construct different build environments, inspired by [this tutorial](https://cmake.org/cmake-tutorial/).

When generating to Eclipse CDT, it will likely complain that sh.exe is in the path, probably from the git folder. Either change the name of git folder while generating the build environment, or try the following from [here](https://github.com/filipwasil/fillwave/issues/17):

<code>set PATH=%PATH:{path to git}\bin=%</code>
