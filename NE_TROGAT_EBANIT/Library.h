#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;

void text(string txt, int ms) {
    for (char c : txt) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(ms));
    }
}
struct product_ {
    string name;
    int price;
};

string to_lower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

enum class item_ {
    headphones,
    panties,
    cup,
    magazine,
    notebook,
    espresso,
    americano,
    capuchino
};

string items_item[] = { "��������", "�������", "�����", "������", "�������", "��������","���������","��������" };

struct portal_ {
    string portal_name;
    int target;
};

struct location_ {
    string dis;
    string loc_name;
    vector<portal_> p;
    vector<item_> item_l;
    bool dis_shown = false;
};

struct info {
    int watch = 1;
    string name;
    int current_loc = 0;
    bool life = true;
    bool headphones_on = true;
    vector<item_> item_p;
    int wallet = 1000;
};

struct love {
    int receptionist = 0;
    int accountant = 50;
    int engineer = 50;
    int boss = 20;
    int komusisi = 80;
};

love girl_love;
info player;
vector<product_> coffee_machine;
location_ room[5];
void show_love_levels();
void InitGame();
void game();
void intervio();
void intervio2();
void arcade_game();
void start();

void start() {
    cout << "������� ���� ���: ";
    cin >> player.name;

    cout << "�� ������ ����������� �� ���������� ������������.\n������ �� ������� �� ����������������, ��� ��������� ������� ����������,\n�� ������� �� ��������� ���� ������� �������� �����.\n";
    cout << "�����, " << player.name << "\n�� ���������� �� ����� �����, ������ ������ �������������� ����� �������� ����������� ������.\n������ ������ ����������� � ��� �������� �� ������� � �������.\n";
    cout << "����� ��� �������� ������������ �� ���� ������, �� ��������� ������������� �� ���� � �� �� �����.\n����� �������� �� ��������?\n";
    cout << "1. ���� �� ������������� � ��� ��������\n";
    cout << "2. ���� �� ������������� � ��� ��������\n";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1: intervio(); break;
    case 2: intervio2(); break;
    default: cout << "�������� �����.\n"; break;
    }
}

void intervio() {
    cout << "\n�� ������������ �� ��������� ������� ������, �� ���������, ��� ������ �� ������� �����.\n";
    cout << "������ ����� ������ � �������� ��� ������ �� ������������� � ����������?\n";
    cout << "1. �������� � ��������, �������� ��� ����� ��������� ������\n";
    cout << "2. ����������, ����� �������� ��� ���\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "�� ������ �������� � ��������, ������ ��� ����� ������ �� ������ �� �������������, ��� ��������.\n";
        cout << "����� ���� �������������, � ��� ��������� ��������� ����� ���� ������� ���������.\n";
        cout << "1. �������� � ������� ������, �������, ������, �������, ����\n";
        cout << "2. ������ �� �������������\n";
        cin >> choice;

        if (choice == 1) {
            arcade_game();
        }
        else if (choice == 2) {
            cout << "�� ������ �����������, �� ��� �� �� ��������� � ����� HR.\n";
            cout << "��� ���������� ������� �������� ��������, �� ��������� � ��� ������ ���������� ������.\n";
        }
    }
    else if (choice == 2) {
        cout << "�� ������ �����������, �� ��� �� �� ��������� � ����� HR.\n";
        cout << "��� ���������� ������� �������� ��������, �� ��������� � ��� ������ ���������� ������.\n";
    }
}

void arcade_game() {
    std::cout << "�� ��������� � ��������, ��� ��� ��������� �������������� ����� �����, ������������ ��� ����������� �����������.\n������ �������� � ��� ��������� ��������� �� ������������, ����� �� ���� ���������� ����, �� ������ ��� ��������!\n";
    std::cout << "������� �������� ���� �� ��������! ���� ��������� �������� ����� ������������, ���������� � ������, �������, ������, �������, ����.\n";

    std::cout << "��� ����� (0 - ������, 1 - �������, 2 - ������, 3 - �������, 4 - ����):\n";

    int human;

    std::cin >> human;

    int skynet = std::rand();
    skynet = skynet %= 5;

    if (skynet == 0) {
        std::cout << "������!\n";
    }
    if (skynet == 1) {
        std::cout << "�������!\n";
    }
    if (skynet == 2) {
        std::cout << "������!\n";
    }
    if (skynet == 3) {
        std::cout << "�������!\n";
    }
    if (skynet == 4) {
        std::cout << "����!\n";
    }

    if (skynet == human) {
        std::cout << "�����\n";
    }
    else if (
        (skynet == 0 && human == 1) || // ������ ��������� �������
        (skynet == 0 && human == 3) || // ������ ��������� �������
        (skynet == 1 && human == 0) || // ������� ��������� ������
        (skynet == 1 && human == 4) || // ������� ��������� �����
        (skynet == 1 && human == 2) || // ������ ��������� �������
        (skynet == 2 && human == 3) || // ������ ��������� �������
        (skynet == 3 && human == 4) || // ������� ��������� �����
        (skynet == 3 && human == 1) || // ������� ��������� �������
        (skynet == 4 && human == 2) || // ���� ��������� ������
        (skynet == 4 && human == 0)    // ���� ��������� ������
        ) {
        std::cout << "������������ ���������!\n";
        player.watch = 0;
    }
    else {
        std::cout << "������������ ��������!\n";

    }

    std::cout << "�����������, " << player.name << ", �� ������������ ���������� ��������� ����������,\n�� ������� ��� ��� ������� �����������: ������ � Seven Eleven,\n��� ������������ ��������� ������ ������������ ��������.\n";
    if (player.watch == 0) {
        cout << "� ���� ��, ��� ���� ������ ��� �� ���� �� �� ����������� �����, �� ���������!\n";
    }
}

void intervio2() {
    cout << "�� ������������ � ������ 30 ����� �� �������������.\n";
    cout << "1. ������ ����\n";
    cout << "2. ������ ������\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "�� �������� � �������. ����� ��������� ��������-���.\n";
        cout << "1. ���� � ��������\n";
        cout << "2. ������ ����\n";
        cin >> choice;

        if (choice == 1) {
            cout << "��������-��� ������� ������ ����������. �� ������� �������� � ��� � ������������ �������������.\n";
            girl_love.komusisi += 20;
        }
        else {
            cout << "�� ����� �� ������������� � ������� ����������. ������������� �������� � ��� �� ����� �����!\n";
        }
    }
    else {
        cout << "��� ��������� � ���������. �� ���������� ������ � ������������� ������.\n";
    }

    player.item_p.push_back(item_::headphones);
    cout << "� ��� ���� ��������.\n";
}
void show_love_levels() {
    cout << "������� �������\n";
    cout << "��������-���: " << girl_love.komusisi << endl;
    cout << "��������: " << girl_love.receptionist << endl;
    cout << "�����������: " << girl_love.accountant << endl;
    cout << "����������: " << girl_love.boss << endl;
    cout << "�������: " << girl_love.engineer << endl;

}
void InitGame() {
    room[0].loc_name = "��������";
    room[0].dis = "������� �� ��������� ���� ��������� ����������...\n";
    room[0].p.push_back({ "69", 1 });
    room[0].p.push_back({ "������", 2 });

    room[1].loc_name = "�����������";
    room[1].dis = "�������������� ��������� ����������...\n";
    room[1].p.push_back({ "44", 3 });
    room[1].p.push_back({ "�����", 4 });
    room[1].p.push_back({ "��������", 0 });

    room[2].loc_name = "������";
    room[2].dis = "���������� ������...\n";
    room[2].p.push_back({ "��������", 0 });

    room[3].loc_name = "����� ������";
    room[3].dis = "���� � �������...\n";
    room[3].p.push_back({ "69", 1 });

    room[4].loc_name = "����� ������������";
    room[4].dis = "������� ���������� ���������...\n";
    room[4].p.push_back({ "69", 1 });
    room[4].p.push_back({ "44", 1 });

    room[2].item_l.push_back(item_::panties);
    room[3].item_l.push_back(item_::cup);
    room[3].item_l.push_back(item_::notebook);
    room[4].item_l.push_back(item_::magazine);
}
void coffee_automat() {
    coffee_machine.clear();
    coffee_machine.push_back({ "��������", 150 });
    coffee_machine.push_back({ "���������", 120 });
    coffee_machine.push_back({ "��������", 180 });


    int choice;
    while (player.wallet > 0) {
        cout << "\n=== �������� ������� ===" << endl;
        cout << "��� ������: " << player.wallet << " ���" << endl;
        cout << "�����������:\n";
        cout << "�����\t��������\t����\t\n";

        for (int i = 0; i < coffee_machine.size(); ++i) {
            cout << i + 1 << ".\t" << coffee_machine[i].name << "\t" << coffee_machine[i].price << "\t" << endl;
        }

        cout << "�������� ����� ���� (0 - �����): ";
        cin >> choice;

        if (choice == 0) {
            cout << "�� ������ �� ��������.\n";
            break;
        }

        if (choice < 1 || choice > coffee_machine.size()) {
            cout << "������������ �����.\n";
            continue;
        }

        product_& selected = coffee_machine[choice - 1];



        if (selected.price > player.wallet) {
            cout << "������������ ������� " << ".\n";
            continue;
        }

        player.wallet -= selected.price;
        switch (choice) {
        case 1: player.item_p.push_back(item_::espresso);
            break;
        case 2: player.item_p.push_back(item_::americano);
            break;
        case 3: player.item_p.push_back(item_::capuchino);
            break;
        }

        cout << "�� ������: " << selected.name << ". ������: " << player.wallet << " ���.\n";

    }



}

void game() {
    InitGame();

    while (true) {
        text("�� ���������� � ", 50);
        cout << room[player.current_loc].loc_name << endl;

        if (!room[player.current_loc].dis_shown) {
            text(room[player.current_loc].dis, 50);
            room[player.current_loc].dis_shown = true;
        }

        string chouse;
        cin >> chouse;
        chouse = to_lower(chouse);



        if (chouse == "����") {
            if (player.current_loc == 3) {
                coffee_automat();
            }
            else {
                std::cout << "����� ��� ��������� ��������!" << std::endl;
            }
        }
        if (chouse == "���") {
            for (const auto& portal : room[player.current_loc].p) {
                cout << "�����: " << portal.portal_name << endl;
            }

            cout << "������� �������� �����: ";
            string vxod;
            cin >> vxod;
            bool found = false;
            for (const auto& portal : room[player.current_loc].p) {
                if (to_lower(portal.portal_name) == to_lower(vxod)) {
                    player.current_loc = portal.target;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "������ ������� ���.\n";

        }

        else if (chouse == "������") {
            if (room[player.current_loc].item_l.empty()) {
                cout << "�� ���� ������� ��� ���������.\n";
            }
            else {
                cout << "��������� ��������:\n";
                for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
                    cout << i + 1 << ". " << items_item[(int)room[player.current_loc].item_l[i]] << endl;
                }
                cout << "������� �������� �������� (��� 'no' ��� ������): ";
                cin.ignore();
                string answer;
                getline(cin, answer);
                if (to_lower(answer) != "no") {
                    bool picked = false;
                    for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
                        if (to_lower(answer) == to_lower(items_item[(int)room[player.current_loc].item_l[i]])) {
                            player.item_p.push_back(room[player.current_loc].item_l[i]);
                            cout << "�� ������� " << items_item[(int)player.item_p.back()] << endl;
                            room[player.current_loc].item_l.erase(room[player.current_loc].item_l.begin() + i);
                            picked = true;
                            break;
                        }
                    }
                    if (!picked) cout << "������ �������� ��� �� �������.\n";
                }
            }
        }
        if (chouse == "�������") {
            show_love_levels();
        }


        else if (chouse == "�����") {
            if (player.item_p.empty()) {
                cout << "� ��� ��� ���������.\n";
            }
            else {
                cout << "���� ��������:\n";
                for (auto& item : player.item_p) {
                    cout << "- " << items_item[(int)item] << endl;
                }
                cout << "������� �������� �������� ��� �������� (��� 'no' ��� ������): ";
                cin.ignore();
                string answer;
                getline(cin, answer);
                if (to_lower(answer) != "no") {
                    bool found = false;
                    for (int i = 0; i < player.item_p.size(); ++i) {
                        if (to_lower(answer) == to_lower(items_item[(int)player.item_p[i]])) {
                            item_ item_dropped = player.item_p[i];
                            room[player.current_loc].item_l.push_back(item_dropped);
                            player.item_p.erase(player.item_p.begin() + i);
                            cout << "�� ������ " << answer << endl;
                            if (player.current_loc == 1 && item_dropped == item_::panties) {
                                cout << "\n*** ������! ������� ����������! ***\n";
                                exit(0);
                            }
                            found = true;
                            break;
                        }
                    }
                    if (!found) cout << "� ��� ��� ������ ��������.\n";
                }
            }
        }
        else if (chouse == "�����") {
            if (player.headphones_on) {
                player.headphones_on = false;
                cout << "�� ����� �������� � ������ ������� ����������.\n";

                if (player.current_loc == 0) {
                    cout << "������� �� ����������: \"������� �����, ��� ���!\"\n";
                }
                else if (player.current_loc == 1) {
                    cout << "��������� ����������: \"���� �������, ���� �� ������ ����� �������������\"\n";
                }
                else if (player.current_loc == 3) {
                    cout << "����������: \"�����, ������ ���� �� ���� ������, ������ ��� ������\"\n";
                }
                else if (player.current_loc == 4) {
                    cout << "������� �����: \"�� ����� �����, � �� ��������� ���� ����� �����\"\n";
                }
            }
            else {
                cout << "�� ��� ����� ��������.\n";
            }
        }
        else if (chouse == "�����") {
            if (!player.headphones_on) {
                player.headphones_on = true;
                cout << "�� ������ �������� � ��������� ������� ����������.\n";
            }
            else {
                cout << "�� ��� � ���������.\n";
            }

        }





    }
}




