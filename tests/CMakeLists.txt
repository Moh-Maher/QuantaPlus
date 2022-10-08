cmake_minimum_required(VERSION 3.20.0)

#Set the test neme
#project(QuantaPlus VERSION 1.0)
project(test)

#Requires at least version 3.3 of Eigen to be installed in a default location.
find_package (Eigen3 REQUIRED NO_MODULE)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


#add the executable files
#add_executable(test_braket  tests/test_braket.cpp)

add_executable(AngularMomentum  test_angular-momentum.cpp)
add_executable(Braket  test_braket.cpp)
add_executable(ClebschGordon  test_clebschGordon.cpp)
add_executable(Eigenvalue  test_eigenvalue.cpp)
add_executable(Latex  test_latex.cpp)
add_executable(Operators  test_operators.cpp)


# link Eigen3 lib 
#target_link_libraries(test_braket Eigen3::Eigen)

target_link_libraries(AngularMomentum Eigen3::Eigen)
target_link_libraries(Braket Eigen3::Eigen)
target_link_libraries(ClebschGordon Eigen3::Eigen)
target_link_libraries(Eigenvalue Eigen3::Eigen)
target_link_libraries(Latex Eigen3::Eigen)
target_link_libraries(Operators Eigen3::Eigen)

#configure_file(QuantaPlusConfig.h.in QuantaPlusConfig.h)

#target_include_directories(QuantaPlus PUBLIC
#                         "${PROJECT_BINARY_DIR}"
#                        )
