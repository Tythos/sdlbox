# sdlbox

Quick template/proof-of-concept for building and using SDL3 to define a basic cross-platform OpenGL application using cmake. Quick steps to reproduce, after cloning this repository, are as follows:

1. Set up SDL, which is referenced within this project as a submodule:

   ```
   > git submodule update --init --recursive
   ```

1. Configure the build, using cmake:

   ```
   > cmake -S . -B build
   ```

1. Execute the build; using the "--build" flag will tell cmake to compile and link using whatever development environment is available on your platform:

   ```
   > cmake --build build
   ```

1. The above will also build the SDL3 libraries, but before running the main executable you must copy the DLL over:

   ```
   > copy build/SDL/Debug/SDL3.dll build/Debug
   ```

1. Now you can run the program from the build product folder (we assume Windows here with the .EXE extension):

   ```
   > cd build/Debug
   > sdlbox.exe
   ```

If successfull, you should see a pink rectangle filling the window context. Press "ESCAPE" any time to quit the application.
