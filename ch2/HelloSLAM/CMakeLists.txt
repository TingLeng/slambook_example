cmake_minimum_required(VERSION 3.10)
project(hello_slam VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} SHARED libHelloSLAM.cpp)

# target_include_directories(${PROJECT_NAME} INTERFACE
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
#         $<INSTSALL_INTERFACE:include>)


set(config_file_path lib/cmake/${PROJECT_NAME})
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

configure_package_config_file(Config.cmake.in
                    ${CMAKE_BINARY_DIR}/${PROJECT_NAME}Config.cmake
                    INSTALL_DESTINATION ${config_file_path}
                    PATH_VARS CMAKE_INSTALL_INCLUDEDIR)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake 
    VERSION ${CMAKE_PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets)
    
install(EXPORT ${PROJECT_NAME}Targets 
        DESTINATION ${config_file_path})

install(
    TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(
    DIRECTORY .
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN *.h
)

install(FILES
        ${CMAKE_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        ${CMAKE_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake 
        DESTINATION ${config_file_path})

