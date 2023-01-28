# QuantaPlus
QuantaPlus is a light C++ template library dedicated to solve and explore quantum mechanics problems. QuantaPlus uses the Eigen3 linear
algebra library.

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

   - Run the command "nmake" to execute the makefile.
   - Now the QuantaPlus library is installed and configured on your Windows system, you can include the library in your C++ projects by adding the following line to your source code:
   
   ```cpp
   	#include <quantaplus.h>
   '''
