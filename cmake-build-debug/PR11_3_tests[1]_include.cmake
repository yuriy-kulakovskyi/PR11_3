if(EXISTS "/Users/yura_kulakovskyi/Documents/C++/AP/PR11/PR11_3/cmake-build-debug/PR11_3_tests[1]_tests.cmake")
  include("/Users/yura_kulakovskyi/Documents/C++/AP/PR11/PR11_3/cmake-build-debug/PR11_3_tests[1]_tests.cmake")
else()
  add_test(PR11_3_tests_NOT_BUILT PR11_3_tests_NOT_BUILT)
endif()