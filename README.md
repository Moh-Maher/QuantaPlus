# QuantaPlus
QuantaPlus is a light C++ template library composed solely of header files and dedicated to solving and exploring quantum mechanics problems.  

# Requirements
Eigen 3 (https://eigen.tuxfamily.org/index.php?title=Main_Page).

# Linux 
The package can be installed as follows:
-  sudo apt-get install libeigen3-dev libeigen3-doc

After the installation is complete, you will find header files (on our reference platform, Ubuntu 22.04 LTS) in the area
- /usr/include/eigen3

This area should be added to the include search path (using the -I/usr/include/eigen3 option) in the MakeFile during compilation.


# Windows 
- To configure QuantaPlus for Windows, you will need to follow these steps:

   - Install the Eigen3 library for Windows. You can download the pre-built binaries from the Eigen website (http://eigen.tuxfamily.org/index.php?title=Main_Page#Download) or build it from source.

   - Extract the QuantaPlus folder "quantaplus" and copy it to a directory where you want to keep your header files (e.g. C:\QuantaPlus).

   - Open the command prompt and navigate to the directory where you copied the QuantaPlus folder.
   - Create a new file called "makefile" in the same directory.
   - In the makefile, add the following command to copy the QuantaPlus folder to the include directory:
   ```java
	copy /Y quantaplus C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29910\include\
   ```
   - Then add these command to check if Eigen3 is installed and install it if it's not:
   ```bash
	if not exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29910\include\eigen3" (
	    echo Eigen3 not found, installing...
	    mkdir "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29910\include\eigen3"
	    copy /Y "path\to\eigen3" "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29910\include\eigen3"
	) else (
	    echo Eigen3 found
	)

   ```
   - Save the makefile, and open the command prompt and navigate to the directory where you copied the QuantaPlus folder.
   - Run the command "nmake" to execute the makefile.
   - Now the QuantaPlus library is installed and configured on your Windows system, you can include the library in your C++ projects by adding the following line to your source code:
   
   ```cpp
	#include "quantaplus.h"
   ```
