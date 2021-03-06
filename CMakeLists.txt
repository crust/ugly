cmake_minimum_required(VERSION 3.0)

project(ugly)

set(REL_SRC_BASE    ./src)
set(REL_SRC_DIR     ${REL_SRC_BASE}/ugly)
set(REL_EXT_DIR     ${REL_SRC_BASE}/ugly-ext)

set(SRC_FILES
  ${REL_SRC_DIR}/bindguard.cpp
  ${REL_SRC_DIR}/buffer.cpp
  ${REL_SRC_DIR}/context.cpp
  ${REL_SRC_DIR}/enum.cpp
  ${REL_SRC_DIR}/framebuffer.cpp
  ${REL_SRC_DIR}/generated_object.cpp
  ${REL_SRC_DIR}/pipeline.cpp
  ${REL_SRC_DIR}/program.cpp
  ${REL_SRC_DIR}/query.cpp
  ${REL_SRC_DIR}/renderbuffer.cpp
  ${REL_SRC_DIR}/sampler.cpp
  ${REL_SRC_DIR}/shader.cpp
  ${REL_SRC_DIR}/texture.cpp
  ${REL_SRC_DIR}/texture_unit.cpp
  ${REL_SRC_DIR}/transform_feedback.cpp
  ${REL_SRC_DIR}/uniform.cpp
  ${REL_SRC_DIR}/uniform_buffer.cpp
  ${REL_SRC_DIR}/vertex_array.cpp
  ${REL_SRC_DIR}/viewport.cpp
)

set(INCLUDE_FILES
  ${REL_SRC_DIR}/buffer.h
  ${REL_SRC_DIR}/context.h
  ${REL_SRC_DIR}/enum.h
  ${REL_SRC_DIR}/exception.h
  ${REL_SRC_DIR}/framebuffer.h
  ${REL_SRC_DIR}/generated_object.h
  ${REL_SRC_DIR}/gl_type.h
  ${REL_SRC_DIR}/log.h
  ${REL_SRC_DIR}/pipeline.h
  ${REL_SRC_DIR}/program.h
  ${REL_SRC_DIR}/query.h
  ${REL_SRC_DIR}/renderbuffer.h
  ${REL_SRC_DIR}/sampler.h
  ${REL_SRC_DIR}/shader.h
  ${REL_SRC_DIR}/texture.h
  ${REL_SRC_DIR}/texture_unit.h
  ${REL_SRC_DIR}/transform_feedback.h
  ${REL_SRC_DIR}/ugly.h
  ${REL_SRC_DIR}/uniform.h
  ${REL_SRC_DIR}/uniform_buffer.h
  ${REL_SRC_DIR}/vertex_array.h
  ${REL_SRC_DIR}/viewport.h
)

set(SRC_FILES_EXT
  ${REL_EXT_DIR}/image.cpp
)

set(INCLUDE_FILES_EXT
  ${REL_EXT_DIR}/image.h
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Werror")

include_directories(SYSTEM /System/Library/Frameworks/OpenGL.framework/Headers)
include_directories(SYSTEM /System/Library/Frameworks/OpenGL.framework/Headers/OpenGL)
include_directories(SYSTEM /opt/local/include) # png includes for ext

include_directories(${REL_SRC_BASE})

add_library(ugly        STATIC ${SRC_FILES} ${INCLUDE_FILES})
add_library(ugly-ext    STATIC ${SRC_FILES_EXT} ${INCLUDE_FILES_EXT})

