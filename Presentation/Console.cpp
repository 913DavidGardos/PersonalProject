//
// Created by david on 31.03.2021.
//

#include <iostream>
#include <limits>
#include "Console.h"


Console::Console(Service_ptc &se)
:_se{se}
{

}

void Console::run()
{
    std::string command;
    std::cout<<"Choose the mode you want:"<<std::endl;
    std::cout<<"Administrator mode (by typing Admin)"<<std::endl;
    std::cout<<"Client mode (by typing Client)"<<std::endl;

    while (true)
    {
        std::cout<<":))";
        std::cin>>command;
        if(command == "exit")
            return;
        if(command == "Admin")
            this->Admin_mode();
        if(command == "Client")
            Client_mode();
    }
}

void Console::Admin_mode()
{
    std::cout<<"You chose Administrator Mode"<<std::endl;
    std::string command;
    while (true)
    {
        std::cout<<"Admin:";
        std::cin>>command;
        if(command == "exit")
        {
            _se.free_mem_command_manager();
            return;
        }
        // update the info of a trench coat
        //add a new trench coat
        //delete a trench coat
        if(command == "add_trench_coat")
            this->add_trench_coat_ui();
        if(command == "delete_trench_coat")
            this->delete_trench_coat_ui();
        if(command == "update_trench_coat")
            this->update_trench_coat_ui();
        if(command == "see_all_trench_coats")
            this->see_all_trench_coats_ui();
        if(command == "undo")
            this->undo();
        if(command == "redo")
            this->redo();
    }
}

void Console::Client_mode()
{
    std::cout<<"You chose Client Mode"<<std::endl;
    //When the application starts, the user should choose the type of file between CSV or HTML
    std::string file_type;
    std::cout<<"Choose the file format you want to use:"<<std::endl;
    std::cout<<"For CSV type: CSV"<<std::endl;
    std::cout<<"For HTML type: HTML"<<std::endl;
    while(true)
    {
        std::cin>>file_type;
        if(file_type == "CSV" || file_type == "HTML")
            break;
        else
            std::cout<<"Wrong input! Please type CSV or HTML"<<std::endl;
    }

    std::string command;
    while (true)
    {
        std::cout<<"Client:";
        std::cin>>command;
        if(command == "exit")
            return;
        if(command == "see_trench_coat")
            this->see_trench_coat(file_type);
        if(command == "see_shopping_basket")
            this->see_shopping_basket(file_type);
    }
}

void Console::add_trench_coat_ui()
{
    int id;
    std::string size;
    std::string color;
    double price;
    int quantity;
    std::string link;

    try
    {
        std::cin.exceptions(std::iostream::failbit);
        std::cout<<"Enter id: ";
        std::cin>>id;
    }
    catch (...)
    {
        std::cout<<"Invalid numerical type"<<std::endl;
        return;
    }

    std::cout<<"Enter size: ";
    while(std::cin>>size)
    {
        if(size != "S"&& size != "M"&&size != "L"&&size != "XL"&&size != "XXL"&&size != "XXXL")
        {
            std::cout<<"Please enter a valid size like (S/M/L/...)\n";
            std::cout<<"Enter size: ";
        }
        else
            break;
    }

    std::cout<<"Available colors (red/orange/yellow/green/blue/purple/pink/brown/grey/black/white): \n";
    std::cout<<"Enter color: ";
    while(std::cin>>color)
    {
        if(color != "red"&& color != "orange"&&color != "yellow"&&color != "green"&&color != "blue"&&
            color != "purple"&&color != "pink"&& color != "brown"&&color != "grey"&&color != "black"&&
            color != "white")
        {
            std::cout<<"Please enter a valid color like (red/blue/...)\n";
            std::cout<<"Enter color: ";
        }
        else
            break;
    }


    try
    {
        std::cin.exceptions(std::iostream::failbit);
        std::cout<<"Enter price: ";
        std::cin>>price;
    }
    catch (...)
    {
        std::cout<<"Invalid numerical type"<<std::endl;
        return;
    }

    try
    {
        std::cin.exceptions(std::iostream::failbit);
        std::cout<<"Enter quantity: ";
        std::cin>>quantity;
    }
    catch (...)
    {
        std::cout<<"Invalid numerical type"<<std::endl;
        return;
    }
    std::cout<<"Enter link: ";
    std::cin>>link;

    this->_se.add_trench_coat(id, size, color, price, quantity, link);
}

void Console::delete_trench_coat_ui()
{
    std::cout<<"Enter the id of the coat you want to delete:"<<std::endl;
    int id;
    try
    {
        std::cin.exceptions(std::iostream::failbit);
        std::cout<<"Enter id: ";
        std::cin>>id;
    }
    catch (...)
    {
        std::cout<<"Invalid numerical type"<<std::endl;
        return;
    }
    this->_se.delete_trench_coat(id);
}

void Console::update_trench_coat_ui()
{
    int id;
    std::string size;
    std::string color;
    double price;
    int quantity;
    std::string link;

    try
    {
        std::cin.exceptions(std::iostream::failbit);
        std::cout<<"Enter id: ";
        std::cin>>id;
    }
    catch (...)
    {
        std::cout<<"Invalid numerical type"<<std::endl;
        return;
    }

    std::cout<<"Enter size: ";
    while(std::cin>>size)
    {
        if(size != "S"&& size != "M"&&size != "L"&&size != "XL"&&size != "XXL"&&size != "XXXL")
        {
            std::cout<<"Please enter a valid size like (S/M/L/...)\n";
            std::cout<<"Enter size: ";
        }
        else
            break;
    }

    std::cout<<"Available colors (red/orange/yellow/green/blue/purple/pink/brown/grey/black/white): \n";
    std::cout<<"Enter color: ";
    while(std::cin>>color)
    {
        if(color != "red"&& color != "orange"&&color != "yellow"&&color != "green"&&color != "blue"&&
           color != "purple"&&color != "pink"&& color != "brown"&&color != "grey"&&color != "black"&&
           color != "white")
        {
            std::cout<<"Please enter a valid color like (red/blue/...)\n";
            std::cout<<"Enter color: ";
        }
        else
            break;
    }

    try
    {
        std::cin.exceptions(std::iostream::failbit);
        std::cout<<"Enter price: ";
        std::cin>>price;
    }
    catch (...)
    {
        std::cout<<"Invalid numerical type"<<std::endl;
        return;
    }

    try
    {
        std::cin.exceptions(std::iostream::failbit);
        std::cout<<"Enter quantity: ";
        std::cin>>quantity;
    }
    catch (...)
    {
        std::cout<<"Invalid numerical type"<<std::endl;
        return;
    }
    std::cout<<"Enter link: ";
    std::cin>>link;

    this->_se.update_trench_coat(id, size, color, price, quantity, link);
}

void Console::see_all_trench_coats_ui()
{
    std::cout<<"id, size, color, price, quantity, link"<<std::endl;
    this->_se.see_all_trench_coats();
}

void Console::see_shopping_basket(const std::string &file_type)
{
    this->_se.print_shopping_basket();
    if(file_type == "CSV")
    {
        this->_se.open_libre_office_csv();
    }
    else if(file_type == "HTML")
    {
        this->_se.open_browser_html();
    }

}

void Console::see_trench_coat(const std::string &file_type)
{
    double total_sum = 0;
    std::string size;

    std::cout<<"Press Enter to see all items or type anything to choose a specific size:";
    std::cin.ignore();

    if(std::cin.get() != '\n')
    {
        std::cout << "Enter size: ";
        while (std::cin >> size)
        {
            if (size != "S" && size != "M" && size != "L" && size != "XL" && size != "XXL" && size != "XXXL") {
                std::cout << "Please enter a valid size like (S/M/L/...)\n";
                std::cout << "Enter size: ";
            } else {
                this->see_one_by_one_ui(size, total_sum, file_type);
                break;
            }
        }
        if(file_type == "HTML")
            this->_se.end_html_file();
    }
    else
    {
        std::cout << "All trench coats are considered !" << std::endl;
        this->_se.see_all_trench_coats();
    }
}

void Console::see_one_by_one_ui(const std::string &size, double total_sum, const std::string &file_type)
{
    bool next = true;
    int current_position = 1;

    while(true)
    {
        if(next)
        {
            current_position = this->_se.return_position_of_item(size, current_position);
        }

        this->purchase_ui(total_sum, current_position, file_type);
        current_position++;
        if(current_position >= this->_se.return_size_of_vector())
            current_position = 1;

        std::cout<<"if you want to go further enter 1 or 0 to exit"<<std::endl;
        std::cin>>next;

        while(true)
        {
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"Wrong input, please enter 1 or 0"<<std::endl;
                std::cin>>next;
            }
            if(!std::cin.fail())
                break;
        }
        if(next == 0)
        {

            break;
        }

    }
}

void Console::purchase_ui(double total_sum, int current_position, const std::string &file_type)
{
    std::cout<<"To purchase enter p, to skip press enter:"<<std::endl;
    std::cin.ignore();
    if(std::cin.get()=='p')
    {
        bool ok = this->_se.add_item_to_basket(current_position, file_type);

        if(ok)
        {
            total_sum += this->_se.return_total_sum(current_position);
            std::cout<<"Item purchased"<<std::endl;
        }
        std::cout<<"Total sum: "<<total_sum<<std::endl;
    }
    else
        std::cout<<"Item skipped"<<std::endl;
}

void Console::undo()
{
    _se.undo();
}

void Console::redo()
{
    _se.redo();
}



