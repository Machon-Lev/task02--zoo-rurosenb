#include "..\include\zoo.h"
#include <string>
#define ROWS 20
#define COLS 40
        Zoo::Zoo()
        {
            createAnimal('L', "Simba");
            createAnimal('L', "Mufasa");
            createAnimal('M', "Monkey");
            createAnimal('G', "Akka");
            createAnimal('G', "Morten");
        }
        void Zoo::run()
        {
            {
                printAllAnimals();
                int index;
                cout << "Type 'help' to see the list of commands.\n";
                string command;
                while (true) {
                    cout << "> ";
                    getline(cin, command);
                    if (command == "stop") {
                        cout << "enter the animal index\n";
                        cin>>index;
                        stopAnimal(index);
                        stepAnimal();
                        printAllAnimals();
                    }
                    else if (command == "move") {
                        cout << "enter the animal index\n";
                        cin >> index;
                        moveAnimal(index);
                        stepAnimal();
                        printAllAnimals();
                    }
                    else if (command == "create") {
                        char c;
                        string nameA;
                        cout << "enter the First Letter of the animal you want to create:\n Enter: L for Lion , M for Monkey , G for Goose.\n";
                        cin >> c;
                        cout << "enter the name of the animal you want to create \n";
                        cin >> nameA;
                        createAnimal(c,nameA);
                        stepAnimal();
                        printAllAnimals();
                    }
                    else if (command == "del") {
                        cout << "enter the animal index\n";
                        cin >> index;
                        while (index < 0 or index > animals.size())
                        {
                            cout << "wrong index, enter the right animal index\n";
                            cin >> index;
                        }
                        deleteAnimal(index);
                        stepAnimal();
                        printAllAnimals();
                    }
                    else if (command == "delAll") {
                        char c;
                        cout << "Enter the First Letter of the animal you want to delete:\n Enter: L for Lion , M for Monkey , G for Goose.\n";
                        cin >> c;
                        deleteAllAnimalsOfType(c);
                        stepAnimal();
                        printAllAnimals();
                    }
                    else if (command == "help") {
                        printHelp();
                    }
                    else if (command == "exit") {
                        cout << "Exiting the Zoo game.\n";
                        break;
                    }
                    else if (command == ".") {
                        stepAnimal();   
                        printAllAnimals();
                    }
                    else {
                        cout << "Unknown command: " << command << "\n";
                    }

                }
            }
        }

        void Zoo::stopAnimal(int index)
        {
            animals[index]->stop();
        }

        void Zoo::printHelp()
        {
            cout << "Enter help to see the list of commands\n";
            cout << "Enter exit to exit\n";
            cout << "Enter . to step\n";
            cout << "Enter stop to stop an animal\n";
            cout << "Enter move to move an animal\n";
            cout << "Enter create to create a new animal\n";
            cout << "Enter del to delete an animal\n";
            cout << "Enter delAll to delete all animals from one type\n";
        }

        void Zoo::createAnimal(char _type, string _name)
        {
            int _row = rand() % 20;
            int _col = rand() % 40;
            switch (_type) {
            case 'L':
                animals.push_back(make_unique<Lion>(_name, Location(_row, _col)));
                break;
            case 'M':
                animals.push_back(make_unique<Monkey>(_name, Location(_row, _col)));
                break;
            case 'G':
                animals.push_back(make_unique<Goose>(_name, Location(_row, _col)));
                break;
            default:
                cout << "Invalid operation";
                break;
            }
        }

        void Zoo::deleteAnimal(int index)
        {
             animals.erase(animals.begin() + index);
        }

        void Zoo::moveAnimal(int index)
        {
            animals[index]->move();
        }

        void Zoo::deleteAllAnimalsOfType(char c)
        {
            if (c == 'L')
                animals.erase(remove_if(animals.begin(), animals.end(), [](const unique_ptr<Animal>& obj) { return typeid(*obj) == typeid(Lion); }), animals.end());
            if (c == 'M')
                animals.erase(remove_if(animals.begin(), animals.end(), [](const unique_ptr<Animal>& obj) { return typeid(*obj) == typeid(Monkey); }), animals.end());
            if (c == 'G')
                animals.erase(remove_if(animals.begin(), animals.end(), [](const unique_ptr<Animal>& obj) { return typeid(*obj) == typeid(Goose); }), animals.end());

        }

        void Zoo::stepAnimal()
        {
            for (unique_ptr<Animal>& it : animals) {
                it->step();
            }
        }

        void Zoo::printAllAnimals()
        {
            cout << "Here is the map of the zoo.\n";
            bool isExist;
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    isExist = false;
                    for (unique_ptr<Animal>& it : animals) {
                        if (it->getLocation() == Location(i, j))
                        {
                            if (!isExist) {
                                cout << it->getInitial();
                                isExist = true;
                                break;
                            }
                        }
                    }
                    if (!isExist)
                        cout << ".";
                }
                cout << "\n";
            }
            cout << "Here is a list of the existing animals in the zoo:\n";
            int i = 0;
            for (unique_ptr<Animal>& it : animals) {
                cout << "Animal number: " << i++ << " ";
                it->printDetails();
            }
            cout << "Type another command\n";
        }

