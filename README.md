# QuantaPlus
QuantaPlus is a light numerical C++ package to solve and explore quantum mechanics problems. QuantaPlus uses the Eigen3 linear
algebra library.

# Requirements
Eigen 3 (https://eigen.tuxfamily.org/index.php?title=Main_Page).

The package can be installed as follows:
-  sudo apt-get install libeigen3-dev libeigen3-doc

After the installation is complete, you will find header files (on our reference platform, Ubuntu 22.04 LTS) in the area
- /usr/include/eigen3

This area should be added to the include search path (using the -I/usr/include/eigen3 option) in the MakeFile during compilation. 
