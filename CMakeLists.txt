cmake_minimum_required(VERSION 3.5)
project(evmmechanics VERSION 0.1.0)
find_package(cdt)
include(CDTWasmToolchain)

add_contract(evmmechanics evmmechanics src/evmmechanics.cpp)
