//
// Created by david on 05.04.2021.
//

#include "Test.h"
#include "../Domain/TrenchCoat.h"
#include "../Persistency/TC_Database.h"
#include "../Business/Service_ptc.h"
#include "../Presentation/Console.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include <Undo_Redo/Command.h>
#include <Undo_Redo/AddCommand.h>


void Test::run_all_tests()
{
    std::cout<<"Tests started!"<<std::endl;
    //this->run_domain_tests();
    //this->run_repo_tests();
    //this->run_service_tests();
//    this->run_file_tests();
    this->run_command_tests();
    std::cout<<"Finishing tests !"<<std::endl;
}


void Test::run_domain_tests() {
    std::cout<<"Domain Tests started!"<<std::endl;

    TrenchCoat t(1, "M", "red", 23.5, 4, "www.farmaciainimicatena.ro/srtghsdf");
    assert(t.get_id() == 1);
    assert(t.get_size() == "M");
    assert(t.get_color() == "red");
    assert(t.get_price() == 23.5);
    assert(t.get_quantity() == 4);
    assert(t.get_link() == "www.farmaciainimicatena.ro/srtghsdf");

    TrenchCoat t1(4, "S", "black", 22.5, 2, "www.catdedepartepotimerge.ro/srtghsdf");
    assert(t1.get_id() == 4);
    assert(t1.get_size() == "S");
    assert(t1.get_color() == "black");
    assert(t1.get_price() == 22.5);
    assert(t1.get_quantity() == 2);
    assert(t1.get_link() == "www.catdedepartepotimerge.ro/srtghsdf");

    TrenchCoat t2{t1};
    t1.set_price(12);
    t1.set_size("M");

    assert(t2.get_id() == 4);
    assert(t2.get_size() == "S");
    assert(t2.get_color() == "black");
    assert(t2.get_price() == 22.5);
    assert(t2.get_quantity() == 2);
    assert(t2.get_link() == "www.catdedepartepotimerge.ro/srtghsdf");

    t1.set_size("S");
    t1.set_price(22.5);
    TrenchCoat t3 = t1;
    t1.set_price(12);
    t1.set_size("M");

    assert(t3.get_id() == 4);
    assert(t3.get_size() == "S");
    assert(t3.get_color() == "black");
    assert(t3.get_price() == 22.5);
    assert(t3.get_quantity() == 2);
    assert(t3.get_link() == "www.catdedepartepotimerge.ro/srtghsdf");

    TrenchCoat t4;
    t4 = t3;
    assert(t4.get_id() == 4);
    assert(t4.get_size() == "S");
    assert(t4.get_color() == "black");
    assert(t4.get_price() == 22.5);
    assert(t4.get_quantity() == 2);
    assert(t4.get_link() == "www.catdedepartepotimerge.ro/srtghsdf");

    assert(t4 == t3);
    TrenchCoat t5;
    std::cin>>t5;
    std::cout<<t5;

    std::cout<<"Domain Tests finishing!"<<std::endl;
}

void Test::run_repo_tests() {
    std::cout<<"Repo Tests started!"<<std::endl;

//    TrenchCoat t1;
//    TC_Database re;
//    re.vec.emplace_back(t1);
//    assert(t1 == re.vec.at(0));
//    TrenchCoat t2;
//    TrenchCoat t3;
//    TrenchCoat t4;
//    TrenchCoat t5;
//    TrenchCoat t6;
//    re.vec.emplace_back(t2);
//    re.vec.emplace_back(t3);
//    re.vec.emplace_back(t4);
//    re.vec.emplace_back(t5);
//    re.vec.emplace_back(t6);
//    assert(t2 == re.vec.at(1));
//    assert(t3 == re.vec.at(2));
//    assert(t4 == re.vec.at(3));
//    assert(t5 == re.vec.at(4));
//    assert(t6 == re.vec.at(5));
//
//    // test add_from_file
//    re.add_from_file();

    std::cout<<"Repo Tests finishing!"<<std::endl;

}

void Test::run_service_tests() {
//    std::cout<<"Service Tests started!"<<std::endl;
//    std::vector<std::string> vec;
//    Command command(vec);
//    CsvFile csv_file;
//    TC_Database re;
//    HtmlFile html_file;
//    File file;
//    Service_ptc se(re, file, csv_file, html_file, command);
//
//    se.add_trench_coat(3, "S", "black", 22.4, 2, "www.wtf.com");
//    assert(re.vec.at(0).get_id() == 3);
//    se.add_trench_coat(4, "M", "black", 22.4, 2, "www.wtf.com");
//    assert(re.vec.at(1).get_id() == 4);
//    se.add_trench_coat(5, "M", "black", 22.4, 2, "www.wtf.com");
//    assert(re.vec.at(2).get_id() == 5);
//    //add_trench_coat test
//
//    se.see_all_trench_coats();
//
//    se.delete_trench_coat(5);
//    assert(re.vec.size() == 2);


    std::cout<<"Service Tests finishing!"<<std::endl;
}

void Test::run_file_tests()
{

//    std::vector<std::string> vec;
//    Command command(vec);
//    TC_Database re;
//    File file;
//    HtmlFile html_file;
//    CsvFile csv_file;
//    Service_ptc se(re, file, csv_file, html_file, command);
//    Console c{se};
//    re.add_from_file();

//    se.add_trench_coat(11,"S","brown",200,3,"www.google.com");
//    se.add_trench_coat(12,"S","brown",200,3,"www.google.com");

    //std::cout<<"vector at position 10 "<<re.vec.at(10)<<std::endl;
    //std::cout<<"vector at position 11 "<<re.vec.at(11)<<std::endl;
    //assert(re.vec.at(0).get_id() == 3);
}

void Test::run_command_tests()
{

    std::string file_path ("/home/david/CLionProjects/A8-9/Persistency/1.txt"); //nice
    TC_Database re(file_path);

    File file(file_path);
    CommandManager command_manager;
    //HtmlFile html_file;
    //CsvFile csv_file;

    Service_ptc se(re, file, command_manager);
    Console c(se);

    // TEST UNDO REDO for ADD and REMOVE

//    se.add_trench_coat(11,"S","brown",200,3,"------ 1st -----");
//    se.add_trench_coat(13,"S","brown",200,3,"------ 2nd -----");
//    se.delete_trench_coat(4);
//    se.add_trench_coat(14,"S","brown",200,3,"------ 3rd -----");
//    se.delete_trench_coat(11);
//    se.delete_trench_coat(6);
//    se.add_trench_coat(11,"S","brown",200,3,"------ 4rd -----");
//    se.add_trench_coat(16,"S","brown",200,3,"------ 5rd -----");
//
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();

    // TEST for UPDATE

//    se.update_trench_coat(2,"S","brown",200,3,"UPDATE");
//    se.update_trench_coat(4,"S","brown",200,3,"UPDATE");
//    se.update_trench_coat(6,"S","brown",200,3,"UPDATE");
//    se.update_trench_coat(8,"S","brown",200,3,"UPDATE");

    // TEST for UNDO REDO UPDATE

//    se.update_trench_coat(5,"S","brown",200,3,"UPDATE");
//    se.update_trench_coat(8,"S","brown",200,3,"UPDATE");
//    se.update_trench_coat(6,"S","brown",200,3,"UPDATE");
//    se.update_trench_coat(8,"S","brown",200,3,"UPDATE");
//
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();

    // TEST for UNDO REDO UPDATE ADD REMOVE

//    se.add_trench_coat(11,"S","brown",200,3,"------ 1st -----");
//    se.update_trench_coat(5,"S","brown",200,3,"THIS WAS UPDATED");
//    se.add_trench_coat(13,"S","brown",200,3,"------ 2nd -----");
//    se.delete_trench_coat(4);
//    se.add_trench_coat(14,"S","brown",200,3,"------ 3rd -----");
//    se.delete_trench_coat(11);
//    se.delete_trench_coat(6);
//    se.add_trench_coat(11,"S","brown",200,3,"------ 4rd -----");
//    se.update_trench_coat(13,"S","brown",200,3,"THIS WAS UPDATED");
//    se.add_trench_coat(16,"S","brown",200,3,"------ 5rd -----");
//
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//    se.redo();
//
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();
//    se.undo();



// TEST for UNDO REDO ADD

//    se.add_trench_coat(11,"S","brown",200,3,"------ 1st -----");
//    se.add_trench_coat(13,"S","brown",200,3,"------ 2nd -----");
//
//    se.undo();
//    se.redo();
//    se.undo();
//    se.redo();
}
