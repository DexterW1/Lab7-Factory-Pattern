CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(calculator
    main.cpp
    op.hpp
    base.hpp
    add.h
    sub.h
    div.h
    mult.h
    pow.h
    Operator.h
    factory.h
)
ADD_EXECUTABLE(test
    unit_test.cpp
)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
