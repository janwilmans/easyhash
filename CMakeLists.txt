cmake_minimum_required(VERSION 3.18..3.28)

project(easyhash VERSION 1.0 LANGUAGES CXX)

add_subdirectory(easyhash)

include(GNUInstallDirs)
set(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_INCLUDEDIR}/
    CACHE PATH "Location of header files" )

set(SYSCONFIG_INSTALL_DIR ${CMAKE_INSTALL_SYSCONFDIR}/easyhash
    CACHE PATH "Location of configuration files" )

include(CMakePackageConfigHelpers)

configure_package_config_file(easyhashConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/easyhashConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/easyhash
  PATH_VARS INCLUDE_INSTALL_DIR SYSCONFIG_INSTALL_DIR
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/easyhashConfigVersion.cmake
  VERSION 1.0.0
  COMPATIBILITY SameMajorVersion
)

install(
	FILES 
   	${CMAKE_CURRENT_BINARY_DIR}/easyhashConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/easyhashConfigVersion.cmake
    DESTINATION 
	${CMAKE_INSTALL_LIBDIR}/cmake/easyhash
)

install(
  DIRECTORY easyhash/include/
  DESTINATION include
  FILES_MATCHING
  PATTERN "*"
  PATTERN "CMakeLists.txt" EXCLUDE
)

add_subdirectory(tests)