cmake_minimum_required (VERSION 2.6)
project (wav2mp3)

include_directories("${PROJECT_SOURCE_DIR}/lame/include")
link_directories("${PROJECT_SOURCE_DIR}/lame/lib")

add_executable(wav2mp3	src/DataProcesser.cpp
						src/fs_utils.cpp
						src/wav2mp3.cpp)
						
target_link_libraries(wav2mp3 libmp3lame-static libmpghip-static)

target_include_directories(wav2mp3
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include)