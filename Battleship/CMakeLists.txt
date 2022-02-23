cmake_minimum_required(VERSION 3.14)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp AiPlayer.cpp AiPlayer.h Utility.cpp Utility.h BattleShipGame.cpp BattleShipGame.h Player.cpp Player.h GameAttributes.cpp GameAttributes.h Board.cpp Board.h Ship.cpp Ship.h ShipPosition.cpp ShipPosition.h HumanPlayer.cpp HumanPlayer.h CheatingAI.cpp CheatingAI.h RandomAI.cpp RandomAI.h HuntDestroyAI.cpp HuntDestroyAI.h Move.cpp Move.h)

target_compile_options(BattleShip PRIVATE -Wall -Werror)