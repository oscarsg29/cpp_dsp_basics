set(REPO_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../..")
idf_component_register(
    SRCS "main.cpp" "${REPO_ROOT}/tests/test_suite.cpp"
    INCLUDE_DIRS "${REPO_ROOT}/include"
)
target_compile_features(${COMPONENT_LIB} PRIVATE cxx_std_17)
