#include <iostream>
#include <set>
#include <string>
#include <windows.h>
#include "Transport_library.h"
#include "NumberConverter.h"
#include "Race_library.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    NumberConverter conv; // создание экземпляра класса
    
    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
    bool continue_racing = true;

    while (continue_racing)
    {
        int type_racing{}, distance{}, action{};
        std::cout << "1. Гонка для наземного транспорта" << std::endl;
        std::cout << "2. Гонка для воздушного транспорта" << std::endl;
        std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
        std::cout << "Выберите тип гонки: ";
        std::cin >> type_racing; // выбор типа гонки
        while ((type_racing < 1) || (type_racing > 3))
        {
            std::cout << "Неправильный выбор " << std::endl;
            std::cout << "Выберите тип гонки: ";
            std::cin >> type_racing;
        };
        std::cout << "Укажите длину дистанции (должна быть положительна): ";
        std::cin >> distance;
        while (distance <= 0)
        {
            std::cout << "Длина дистанции должна быть положительна" << std::endl;
            std::cout << "Укажите длину дистанции: ";
            std::cin >> distance;
        };
        std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
        std::cout << "1. Зарегистрировать транспорт" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> action;
        while (action != 1)
        {
            std::cout << "Неправильный выбор " << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> action;
        };

        std::set<int> options; // создание контейнера
        int choice;

        if (type_racing == 1) // для наземных ТС
        {
            Race_lib::Ground_Racing groundRace; // создание экземпляра класса ТС

            while (true)
            {
                std::cout << "Гонка для наземного транспорта. Расстояние: " << distance << std::endl;

                if (!options.empty())
                {
                    std::cout << "Зарегистрированные транспортные средства: ";
                    for (int value : options)
                    {
                        std::cout << conv.getWord(value) << ", ";
                    }
                    std::cout << std::endl;

                }

                for (int i = 1; i <= 7; i++)
                {
                    std::cout << i << ". " << conv.getWord(i) << std::endl;
                }

                std::cout << "0. Закончить регистрацию" << std::endl;
                std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: " << std::endl;

                std::cin >> choice;


                if (choice == 0)
                {
                    if (options.size() >= 2)
                    {
                        break;
                    }
                    else
                    {
                        std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
                        std::cout << "1. Зарегистрировать транспорт" << std::endl;
                        std::cout << "Выберите действие: ";
                        std::cin >> action;
                        while (action != 1)
                        {
                            std::cout << "Неправильный выбор " << std::endl;
                            std::cout << "Выберите действие: ";
                            std::cin >> action;
                        };
                        continue;
                    }
                }

                if (options.count(choice))
                {
                    std::cout << conv.getWord(choice) << " уже выбран!" << std::endl;;
                    continue;;
                }

                else if (groundRace.isValidChoice(choice))
                {
                    options.insert(choice);
                    std::cout << conv.getWord(choice) << " успешно зарегистрирован!" << std::endl;
                }
                else
                {

                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                    continue;
                }

            }

            ,// Подсчет времени
            if (options.count(1))
            {
                Transport_lib::Off_road_boots boots(distance);
                int result1 = boots.find_time();
                std::cout << result1 << std::endl;
            }
            if (options.count(3))
            {
                Transport_lib::Camel camel(distance);
                int result2 = camel.find_time();
                std::cout << result2 << std::endl;

            }
            if (options.count(4)) {
                Transport_lib::Сentaur centaur(distance);
                int result3 = centaur.find_time();
                std::cout << result3 << std::endl;
            }
            if (options.count(6))
            {
                Transport_lib::Swift_Camel swift_camel(distance);
                int result4 = swift_camel.find_time();
                std::cout << result4 << std::endl;
            }
            options.clear();
        }

        if (type_racing == 2) // для воздушных ТС
        {
            Race_lib::Air_Racing airRace; // создание экземпляра класса ТС

            while (true)
            {
                std::cout << "Гонка для воздушного транспорта. Расстояние: " << distance << std::endl;

                if (!options.empty())
                {
                    std::cout << "Зарегистрированные транспортные средства: ";
                    for (int value : options)
                    {
                        std::cout << conv.getWord(value) << ", ";
                    }
                    std::cout << std::endl;

                }

                for (int i = 1; i <= 7; i++)
                {
                    std::cout << i << ". " << conv.getWord(i) << std::endl;
                }

                std::cout << "0. Закончить регистрацию" << std::endl;
                std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: " << std::endl;

                std::cin >> choice;


                if (choice == 0)
                {
                    if (options.size() >= 2)
                    {
                        break;
                    }
                    else
                    {
                        std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
                        std::cout << "1. Зарегистрировать транспорт" << std::endl;
                        std::cout << "Выберите действие: ";
                        std::cin >> action;
                        while (action != 1)
                        {
                            std::cout << "Неправильный выбор " << std::endl;
                            std::cout << "Выберите действие: ";
                            std::cin >> action;
                        };
                        continue;
                    }
                }

                if (options.count(choice))
                {
                    std::cout << conv.getWord(choice) << " уже выбран!" << std::endl;;
                    continue;;
                }

                else if (airRace.isValidChoice(choice))
                {
                    options.insert(choice);
                    std::cout << conv.getWord(choice) << " успешно зарегистрирован!" << std::endl;
                }
                else
                {

                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                    continue;
                }

            }

            if (options.count(2))
            {
                Transport_lib::Broom broom(distance);
                int result1 = broom.find_time();
                std::cout << result1 << std::endl;
            }
            if (options.count(5))
            {
                Transport_lib::Eagle eagle(distance);
                int result2 = eagle.find_time();
                std::cout << result2 << std::endl;

            }
            if (options.count(7)) {
                Transport_lib::Flying_carpet flying_carpet(distance);
                int result3 = flying_carpet.find_time();
                std::cout << result3 << std::endl;
            }           
        }
        options.clear();
        int action1{};
        std::cout << "1. Провести еще одну гонку" << std::endl;
        std::cout << "2. Выйти" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> action1;
        if (action1 == 1)
        {
            continue_racing = true;
        }
        else
        {
            continue_racing = false;
        }
    }
    
    
}