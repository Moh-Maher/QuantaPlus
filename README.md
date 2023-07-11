# QuantaPlus

QuantaPlus is a light C++ template library composed solely of header files and dedicated to solving and exploring problems in quantum mechanics. It provides a set of classes, functions, and utilities that facilitate quantum-related calculations and simulations.

The library is designed to be lightweight and easy to use. Being composed solely of header files means that you don't need to link any external libraries or perform separate compilation steps. Simply including the necessary header files in your C++ code allows you to access the functionality provided by QuantaPlus.

QuantaPlus offers a range of modules that cover various aspects of quantum mechanics. These modules include utilities, operators, eigenvectors, brakets, and more. Each module provides specific classes and functions tailored to its area of focus, allowing you to perform calculations, manipulate quantum objects, and explore quantum phenomena.

By leveraging the power of C++ templates, QuantaPlus offers flexibility and efficiency in handling different data types and mathematical operations. It allows you to work with complex numbers, matrices, vectors, and other mathematical entities commonly used in quantum mechanics.

The library is intended to assist researchers, students, and developers working in the field of quantum mechanics. It aims to simplify the implementation of quantum algorithms, simulations, and calculations, enabling users to focus on the core aspects of their work without worrying about low-level details.

Whether you need to perform calculations involving angular momentum, calculate Clebsch-Gordan coefficients, compute eigenvalues and eigenvectors, or simulate quantum systems, QuantaPlus provides the necessary tools to facilitate these tasks.

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
