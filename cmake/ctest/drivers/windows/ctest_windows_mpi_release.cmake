
INCLUDE("${CTEST_SCRIPT_DIRECTORY}/TrilinosCTestDriverCore.windows.msvc.cmake")
INCLUDE("${CTEST_SCRIPT_DIRECTORY}/../../../../Version.cmake")

SET(COMM_TYPE MPI)
SET(BUILD_TYPE Release)
SET(BUILD_DIR_NAME "${COMM_TYPE}_${BUILD_TYPE}_${Trilinos_VERSION}")

TRILINOS_SYSTEM_SPECIFIC_CTEST_DRIVER()
