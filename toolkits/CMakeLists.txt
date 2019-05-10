# Apps
add_executable(bc bc.cpp)
add_executable(bfs bfs.cpp)
add_executable(cc cc.cpp)
add_executable(pagerank pagerank.cpp)
add_executable(sssp sssp.cpp)

# Debug
add_definitions(-DPRINT_DEBUG_MESSAGES)

# Includes
include_directories("${PROJECT_SOURCE_DIR}")

# FLGAS
add_compile_options(-O0 -g -Wall)

# OpenMP
find_package(OpenMP REQUIRED)
#add_compile_options(-fopenmp)
add_compile_options(${OpenMP_CXX_FLAGS})
#message("OpenMP FLGAS: ${OpenMP_CXX_FLAGS}")
#target_link_libraries(bc PRIVATE OpenMP::OpenMP_CXX)
#target_link_libraries(bfs PRIVATE OpenMP::OpenMP_CXX)
#target_link_libraries(cc PRIVATE OpenMP::OpenMP_CXX)
#target_link_libraries(pagerank PRIVATE OpenMP::OpenMP_CXX)
#target_link_libraries(sssp PRIVATE OpenMP::OpenMP_CXX)
target_link_libraries(bc PRIVATE ${OpenMP_CXX_LIBRARIES})
message("OpenMP Libraries: ${OpenMP_CXX_LIBRARIES}")
target_link_libraries(bfs PRIVATE ${OpenMP_CXX_LIBRARIES})
target_link_libraries(cc PRIVATE ${OpenMP_CXX_LIBRARIES})
target_link_libraries(pagerank PRIVATE ${OpenMP_CXX_LIBRARIES})
target_link_libraries(sssp PRIVATE ${OpenMP_CXX_LIBRARIES})

# MPI
find_package(MPI REQUIRED)
include_directories("${MPI_CXX_INCLUDE_DIRS}")
#message("MPI includes: ${MPI_CXX_INCLUDE_DIRS}")
add_compile_options("${MPI_CXX_LINK_FLAGS}")
#message("MPI Flags: ${MPI_CXX_LINK_FLAGS}")
target_link_libraries(bc PRIVATE ${MPI_CXX_LIBRARIES})
#message("MPI Libraries: ${MPI_CXX_LIBRARIES}")
target_link_libraries(bfs PRIVATE ${MPI_CXX_LIBRARIES})
target_link_libraries(cc PRIVATE ${MPI_CXX_LIBRARIES})
target_link_libraries(pagerank PRIVATE ${MPI_CXX_LIBRARIES})
target_link_libraries(sssp PRIVATE ${MPI_CXX_LIBRARIES})

# Libnuma
#add_compile_options(/usr/lib/x86_64-linux-gnu/libnuma.a)
set(NUMA_LIBRARIES "/usr/lib/x86_64-linux-gnu/libnuma.so")
#target_link_libraries(bc PRIVATE "/usr/lib/x86_64-linux-gnu/libnuma.so")
target_link_libraries(bc PRIVATE ${NUMA_LIBRARIES})
target_link_libraries(bfs PRIVATE ${NUMA_LIBRARIES})
target_link_libraries(cc PRIVATE ${NUMA_LIBRARIES})
target_link_libraries(pagerank PRIVATE ${NUMA_LIBRARIES})
target_link_libraries(sssp PRIVATE ${NUMA_LIBRARIES})
