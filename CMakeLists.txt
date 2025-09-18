cmake_minimum_required(VERSION 3.10)

# set the project name
project(HelloProj)

#export configuration to source code
configure_file(HelloProjConfig.h.in HelloProjConfig.h)

#add the executable target named HelloWorld
add_executable(HelloWorld hello.cpp)
