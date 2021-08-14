#include <iostream>
#include "Persistency/TC_Database.h"
#include "Business/Service_ptc.h"
#include "Presentation/Console.h"
#include "Test/Test.h"
#include "GUI/Window.h"
#include <QApplication>
#include <QDebug>
#include <QPushButton>
#include <QToolBar>
#include <QMenuBar>
#include <Undo_Redo/Command.h>
#include <GUI/Client/MyTableModel.h>


int main(int argc, char **argv) {
//    Test t;
//    t.run_all_tests();

    std::string file_path ("/home/david/CLionProjects/A8-9/Persistency/1.txt");
    TC_Database re(file_path);

    File file(file_path);
    CommandManager command_manager;
    //HtmlFile html_file;
    //CsvFile csv_file;

    Service_ptc se(re, file, command_manager);
//    Console c(se);
//    c.run();

    QApplication app(argc, argv);
    MyTableModel m(se);
    Window w{se, m};


    w.show();
    return app.exec();
    return 0;
}

