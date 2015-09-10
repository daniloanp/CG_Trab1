cmake_minimum_required(VERSION 3.3)

project(CG_Trab1)
set(IUP_INCLUDE_DIR "/usr/include/iup/")
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules")


find_package(IUP REQUIRED)
find_package(OpenGL REQUIRED)




set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(. SRC_LIST)
add_executable(CG_Trab1 ${SRC_LIST})

add_custom_command(TARGET CG_Trab1 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/img $<TARGET_FILE_DIR:CG_Trab1>/img)

target_link_libraries(
        ${PROJECT_NAME}
        ${IUPGL_LIBRARY}
        ${IUP_LIBRARY}
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
)