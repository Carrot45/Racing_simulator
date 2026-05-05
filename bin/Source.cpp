#include <iostream>
#include <set>
#include <string>
#include <array>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "Transport_library.h"
#include "Race_library.h"
#include "Ground_Racing.h"
#include "Air_Racing.h"
#include "Air_and_ground_racing.h"

namespace Consts
{
    constexpr const char* off_road_boots = "off_road_boots";
    constexpr const char* broom = "broom";
    constexpr const char* camel = "camel";
    constexpr const char* centaur = "centaur";
    constexpr const char* eagle = "eagle";
    constexpr const char* swift_Camel = "swift_camel";
    constexpr const char* flying_carpet = "flying_carpet";

    constexpr std::array<const char*, 8> RUSSIAN_NAMES = {
           "",
           "Ботинки-вездеходы",
           "Метла",
           "Верблюд",
           "Кентавр",
           "Орёл",
           "Верблюд-быстроход",
           "Ковер-самолёт"
    };

    inline const char* getRussianName(int num)
    {
        if (num >= 1 && num <= 7) {
            return RUSSIAN_NAMES[num];
        }
        return "Ошибка, выход за пределы массива";
    }
}

struct RaceResult 
{
    double time{};
    std::string name{};
    int transportNumber{};
        
    bool operator<(const RaceResult& other) const
    {
        return time < other.time;  // перегрузка оператора
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);       
    
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
        int choice{};

        switch (type_racing)
        {
        case 1:
            // для наземных ТС
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
                        std::cout << Consts::getRussianName(value) << ", ";
                    }
                    std::cout << std::endl;
                }

                for (int i = 1; i <= 7; i++)
                {
                    std::cout << i << ". " << Consts::getRussianName(i) << std::endl;
                }

                std::cout << "0. Закончить регистрацию" << std::endl;
                std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: " << std::endl;
                std::cin >> choice;

                if ((choice < 0) || (choice > 7))
                {
                    std::cout << "Неправильный выбор " << std::endl;
                    std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: " << std::endl;
                    continue;
                }

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
                    std::cout << Consts::getRussianName(choice) << " уже выбран!" << std::endl;
                    continue;
                }
                else if (groundRace.isValidChoice(choice))
                {
                    options.insert(choice);
                    std::cout << Consts::getRussianName(choice) << " успешно зарегистрирован!" << std::endl;
                }
                else
                {

                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                    continue;
                };
            };

            std::vector<RaceResult> results;

            // Подсчет времени

            if (options.count(1))
            {
                Transport_lib::Off_road_boots boots(distance);
                results.push_back({ boots.find_time(), Consts::getRussianName(1), 1 });
            };

            if (options.count(3))
            {
                Transport_lib::Camel camel(distance);
                results.push_back({ camel.find_time(), Consts::getRussianName(3), 3 });
            };

            if (options.count(4))
            {
                Transport_lib::Centaur centaur(distance);
                results.push_back({ centaur.find_time(), Consts::getRussianName(4), 4 });
            };

            if (options.count(6))
            {
                Transport_lib::Swift_Camel swift_camel(distance);
                results.push_back({ swift_camel.find_time(), Consts::getRussianName(6), 6 });
            };

            std::sort(results.begin(), results.end());
            std::cout << std::endl;
            std::cout << "Результаты гонки:" << std::endl;
            for (size_t i = 0; i < results.size(); ++i)
            {
                std::cout << i + 1 << ". " << results[i].name << ": " << results[i].time << std::endl;
            }
            std::cout << std::endl;
            options.clear();
            break;
        };
        case 2:
            // для воздушных ТС
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
                        std::cout << Consts::getRussianName(value) << ", ";
                    }
                    std::cout << std::endl;
                }

                for (int i = 1; i <= 7; i++)
                {
                    std::cout << i << ". " << Consts::getRussianName(i) << std::endl;
                }

                std::cout << "0. Закончить регистрацию" << std::endl;
                std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: " << std::endl;

                std::cin >> choice;

                if ((choice < 0) || (choice > 7))
                {
                    std::cout << "Неправильный выбор " << std::endl;
                    std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: " << std::endl;
                    continue;
                }

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

                if ((choice < 0) || (choice > 7))
                {
                    std::cout << "Неправильный выбор " << std::endl;
                    std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: " << std::endl;
                    std::cin >> choice;
                    continue;
                }

                if (options.count(choice))
                {
                    std::cout << Consts::getRussianName(choice) << " уже выбран!" << std::endl;
                    continue;
                }

                else if (airRace.isValidChoice(choice))
                {
                    options.insert(choice);
                    std::cout << Consts::getRussianName(choice) << " успешно зарегистрирован!" << std::endl;
                }
                else
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                    continue;
                }
            };

            std::vector<RaceResult> results;

            if (options.count(2))
            {
                Transport_lib::Broom broom(distance);
                results.push_back({ broom.find_time(), Consts::getRussianName(2), 2 });
            };

            if (options.count(5))
            {
                Transport_lib::Eagle eagle(distance);
                results.push_back({ eagle.find_time(), Consts::getRussianName(5), 5 });
            };

            if (options.count(7))
            {
                Transport_lib::Flying_carpet flying_carpet(distance);
                results.push_back({ flying_carpet.find_time(), Consts::getRussianName(7), 7 });
            };

            std::sort(results.begin(), results.end());
            std::cout << std::endl;
            std::cout << "Результаты гонки:" << std::endl;
            for (size_t i = 0; i < results.size(); ++i)
            {
                std::cout << i + 1 << ". " << results[i].name << ": " << results[i].time << std::endl;
            }
            std::cout << std::endl;
            options.clear();
            break;
        };
        case 3:
            // для наземных и воздушных ТС
        {
            Race_lib::Air_and_ground_racing air_and_groundRace; // создание экземпляра класса ТС
            while (true)
            {
                std::cout << "Гонка для наземного и воздушного транспорта. Расстояние: " << distance << std::endl;

                if (!options.empty())
                {
                    std::cout << "Зарегистрированные транспортные средства: ";
                    for (int value : options)
                    {
                        std::cout << Consts::getRussianName(value) << ", ";
                    }
                    std::cout << std::endl;

                }

                for (int i = 1; i <= 7; i++)
                {
                    std::cout << i << ". " << Consts::getRussianName(i) << std::endl;
                }

                std::cout << "0. Закончить регистрацию" << std::endl;
                std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: " << std::endl;

                std::cin >> choice;

                if ((choice < 0) || (choice > 7))
                {
                    std::cout << "Неправильный выбор " << std::endl;
                    std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: " << std::endl;                    
                    continue;
                }

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
                    std::cout << Consts::getRussianName(choice) << " уже выбран!" << std::endl;
                    continue;
                }

                else
                {
                    options.insert(choice);
                    std::cout << Consts::getRussianName(choice) << " успешно зарегистрирован!" << std::endl;
                }
            };

            std::vector<RaceResult> results;

            if (options.count(1))
            {
                Transport_lib::Off_road_boots boots(distance);
                results.push_back({ boots.find_time(), Consts::getRussianName(1), 1 });
            };

            if (options.count(2))
            {
                Transport_lib::Broom broom(distance);
                results.push_back({ broom.find_time(), Consts::getRussianName(2), 2 });
            };

            if (options.count(3))
            {
                Transport_lib::Camel camel(distance);
                results.push_back({ camel.find_time(), Consts::getRussianName(3), 3 });
            };

            if (options.count(4))
            {
                Transport_lib::Centaur centaur(distance);
                results.push_back({ centaur.find_time(), Consts::getRussianName(4), 4 });
            };

            if (options.count(5))
            {
                Transport_lib::Eagle eagle(distance);
                results.push_back({ eagle.find_time(), Consts::getRussianName(5), 5 });
            };

            if (options.count(6))
            {
                Transport_lib::Swift_Camel swift_camel(distance);
                results.push_back({ swift_camel.find_time(), Consts::getRussianName(6), 6 });
            };

            if (options.count(7))
            {
                Transport_lib::Flying_carpet flying_carpet(distance);
                results.push_back({ flying_carpet.find_time(), Consts::getRussianName(7), 7 });
            };

            std::sort(results.begin(), results.end());
            std::cout << std::endl;
            std::cout << "Результаты гонки:" << std::endl;
            for (size_t i = 0; i < results.size(); ++i)
            {
                std::cout << i + 1 << ". " << results[i].name << ": " << results[i].time << std::endl;
            }
            std::cout << std::endl;
            options.clear();
            break;
        };
        }
        int action1{};
        std::cout << "1. Провести еще одну гонку" << std::endl;
        std::cout << "2. Выйти" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> action1;
        continue_racing = (action1 == 1) ? true : false;
    };
    return EXIT_SUCCESS;
}