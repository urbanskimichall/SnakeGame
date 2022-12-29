cmake_minimum_required(VERSION 3.15)
project(Snake)

set(CMAKE_CXX_STANDARD 17)
add_executable(Snake main.cpp Movement.cpp Movement.h Apple.cpp Apple.h GameOver.cpp GameOver.h Spider.cpp Spider.h Food.cpp Food.h Banana.cpp Banana.h Orange.cpp Orange.h Obstacles.cpp Obstacles.h LevelParameters.cpp LevelParameters.h LevelUpdater.cpp LevelUpdater.h Enemy.cpp Enemy.h)
include_directories(C:/SFML/include)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

if(SFML_FOUND)
    include_directories(C:/SFML/include)
    target_link_libraries(Snake sfml-system sfml-window sfml-graphics sfml-audio)
endif()
