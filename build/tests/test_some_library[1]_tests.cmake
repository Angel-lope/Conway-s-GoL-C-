add_test([=[example.example]=]  /home/angel/project/build/bin/test_some_library [==[--gtest_filter=example.example]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[example.example]=]  PROPERTIES WORKING_DIRECTORY /home/angel/project/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  test_some_library_TESTS example.example)
