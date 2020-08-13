# Display Numbers

A GUI-based application with a scalable layout
that lets the user display numbers from 1 to 10 
in bases 2, 8, 10, and 16.

Made in Qt (C++).

## Compiling using `qmake` and `gcc` on Windows

 - Use `qmake` to create the required files for compilation.
   ```
   > qmake
   ```
 - After verifying the generated `Makefile`, build the application.
   ```
   > make
   ```
   For MinGW or MinGW-w64 in Windows, use `mingw32-make` instead.
   To ensure the deployment of the compiled executable with all Qt-related dependencies, `windeployqt` will automatically be executed to copy the required files.

The compiled application will now be found in the `release` subfolder.