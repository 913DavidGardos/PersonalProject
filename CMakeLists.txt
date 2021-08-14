cmake_minimum_required(VERSION 3.17)
project(A8-9)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SOURCE_FILES main.cpp)
set(CMAKE_PREFIX_PATH "/home/david/Qt/5.15.2/gcc_64/lib/cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(A8-9 main.cpp Persistency/TC_Database.cpp Persistency/TC_Database.h Business/Service_ptc.cpp Business/Service_ptc.h Presentation/Console.cpp Presentation/Console.h Test/Test.cpp Test/Test.h Domain/TrenchCoat.cpp Domain/TrenchCoat.h Exceptions/RepoValidator.cpp Exceptions/RepoValidator.h Persistency/File.cpp Persistency/File.h Persistency/CsvFile.cpp Persistency/CsvFile.h Persistency/HtmlFile.cpp Persistency/HtmlFile.h GUI/Window.cpp GUI/Window.h GUI/AdminMenu.cpp GUI/AdminMenu.h GUI/Admin/AdminAdd.cpp GUI/Admin/AdminAdd.h GUI/Admin/AdminDelete.cpp GUI/Admin/AdminDelete.h GUI/Admin/AdminUpdate.cpp GUI/Admin/AdminUpdate.h GUI/Admin/AdminSee.cpp GUI/Admin/AdminSee.h GUI/ClientMenu.cpp GUI/ClientMenu.h GUI/Client/ClientSeeTrench.cpp GUI/Client/ClientSeeTrench.h Exceptions/MyWarning.cpp Exceptions/MyWarning.h GUI/Client/ClientSelectSize.cpp GUI/Client/ClientSelectSize.h Undo_Redo/Command.cpp Undo_Redo/Command.h Undo_Redo/AddCommand.cpp Undo_Redo/AddCommand.h Undo_Redo/CommandManager.cpp Undo_Redo/CommandManager.h Undo_Redo/RemoveCommand.cpp Undo_Redo/RemoveCommand.h Undo_Redo/UpdateCommand.cpp Undo_Redo/UpdateCommand.h GUI/Client/MyTableModel.cpp GUI/Client/MyTableModel.h GUI/Client/TableView.cpp GUI/Client/TableView.h)

find_package(Qt5Sql REQUIRED)
find_package(Qt5Widgets REQUIRED)

target_link_libraries(A8-9 Qt5::Widgets Qt5::Sql)
target_link_libraries(A8-9 Qt5::Widgets)