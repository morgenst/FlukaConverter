function(add_boost_test SRC_FNAME)

    get_filename_component(TEST_EXEC_NAME ${SRC_FNAME} NAME_WE)
    add_executable(${TEST_EXEC_NAME} ${SRC_FNAME})
    target_link_libraries(${TEST_EXEC_NAME} ${DEP_LIB} ${BOOST_UNIT_TEST_FRAMEWORK_LIB})

    file(READ "${SRC_FNAME}" SRC_CONTENTS)
    string(REGEX MATCHALL "BOOST_AUTO_TEST_CASE\\( *([A-Za-z_0-9]+) *\\)"
            FOUND_TESTS ${SRC_CONTENTS})

    foreach(HIT ${FOUND_TESTS})
        string(REGEX REPLACE ".*\\( *([A-Za-z_0-9]+) *\\).*" "\\1" TEST_NAME ${HIT})

        add_test(NAME "${TEST_EXEC_NAME}.${TEST_NAME}"
                 COMMAND ${TEST_EXEC_NAME}
                 --run_test=${TEST_NAME} --catch_system_error=yes)
    endforeach()

endfunction()