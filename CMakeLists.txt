cmake_minimum_required(VERSION 3.11)

project(Vehicles CXX)

set(CMAKE_CXX_STANDARD 23)

# ����������� ��������� ��� ����������� Visual Studio
if(MSVC)
    # ���������� ����������� �������� ��� ������������ ���������
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # �������� ������� ������� ��������������
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")   
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# ��������� ����������
add_library(Vehicle SHARED
    "include/Vehicle.h"
    "include/VehiclesList.h"
    "include/menu_functions.h"
    "src/Vehicle.cc"
    "src/VehiclesList.cc"
    "src/menu_functions.cc"
)
target_include_directories(Vehicle PUBLIC "include")

# ���������� googletest
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/6b63c98ac43efc992122f1da12aaf0a0e0658206.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ��������� �����
add_executable(tests
    "tests/testVehicle.cc"
    "tests/testVehicleList.cc"
)
target_link_libraries(tests Vehicle GTest::gtest_main)

# ��������� ����������� ����
add_executable(main "src/main.cc")
target_link_libraries(main Vehicle)