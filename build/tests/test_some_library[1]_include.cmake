if(EXISTS "/home/angel/project/build/tests/test_some_library[1]_tests.cmake")
  include("/home/angel/project/build/tests/test_some_library[1]_tests.cmake")
else()
  add_test(test_some_library_NOT_BUILT test_some_library_NOT_BUILT)
endif()