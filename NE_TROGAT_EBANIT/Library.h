#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random> 
#include <Windows.h>
#include <chrono>
#include <thread>


using namespace std;

void text(string txt, int ms) {

    for (int i = 0; i < txt.size(); i++) {

        cout << txt[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(ms));
    }
}

enum class item_ {
    panties,
    cup,
    magazine,
    notebook

};

string items_item[4]{ "�������","�����","������","�������" };

struct info {
    int watch = 1;
    std::string name;
    int current_loc = 0;
    bool life;
    vector<item_> item_p;
};


struct portal_ {
    string portal_name;
    int target;
};


struct location_ {

    bool story;
    string dis;
    string loc_name;
    vector <portal_> p;
    vector<item_> item_l;

};


location_ room[5];


info player;


void InitGame() {



    room[0].loc_name = "��������";
    room[0].dis = "������� �� ��������� ���� ��������� ���������� � �������� ��������.\n��� ������ ���� ��� ����� ������ ������� � ������ � ��������� ��������� : - ���������.\n� ����� ��������� � ����������� ��� ���������� �� ������, ������� ���������� ������. ���.\n";
    room[0].p.push_back({ "69", 1 });
    room[0].p.push_back({ "������", 2 });
    room[0].story = false;


    room[1].loc_name = "�����������";
    room[1].p.push_back({ "44", 3 });
    room[1].p.push_back({ "�����", 4 });
    room[1].p.push_back({ "��������", 0 });
    room[1].dis = "������ �����. �������������� ��������� �������� ���������� �������� ��������� � ��������, ��� �� ����� ��� ����� � ��� �������� ������ ���������.\n����� ���������� � ������ � ����������, ��� ������� ������� ���� � ���������� ����� ������ �������, �������� � ������� ������.\n";

    room[2].loc_name = "������";
    room[3].loc_name = "����� ������";
    room[4].loc_name = "����� ������������";
    room[2].dis = "���������� ������ �������� ������ ��������, ���� ������ ����� �������� �� �������� ����\n� ����������� �� ����������� ������� ������� � ������ ������� �������.\n��� ����������, ����� ��������� � ����, ���� ��������� ����� ��������.\n";
    room[3].dis = "�� ������� ��������������� ���� ����� ���������� ������� ������ �������, ��� �� ������?\n������ ��������� �� ����� � ��������� �� ������ ������������ ��������, ��������� �� �������� � ����������� ���������� ���������� ��������.\n������ ��������� ������� ��������, ���� ���� �������� �� ����.\n";
    room[4].dis = "������ ������ ������ ����������, ������ �������� ������������ ������ �������� ��������, ������� � ������ �������.\n��� ������� ����������: - �� ���� ���������, �������! ������� ����, ������ ��� ������� �����.\n";

    room[2].p.push_back({ "���������", 0 });
    room[3].p.push_back({ "69", 1 });
    room[4].p.push_back({ "69", 1 });
    room[4].p.push_back({ "44", 1 });

    room[2].item_l.push_back(item_::panties);
    room[3].item_l.push_back(item_::cup);
    room[3].item_l.push_back(item_::notebook);
    room[4].item_l.push_back(item_::magazine);
}


string to_lower(string s) {
    for (char& c : s) s = tolower((unsigned char)c);
    return s;
}


void game() {

    while (true) {
        text("�� ���������� � ", 30);
        cout << room[player.current_loc].loc_name << endl;
        auto x = room[player.current_loc];
        if (!x.story) {
            text(x.dis, 30);
            room[player.current_loc].story = true;
        }
        
     

        //����� ������ ������ ��������� ))


        string chouse;
        cin >> chouse;
        to_lower(chouse);

     

        if (chouse == "���") {

            for (int i = 0; i < room[player.current_loc].p.size(); ++i) {
                cout << "�����: ";
                text(room[player.current_loc].p[i].portal_name,
                    100);
                cout << "\n";
            }

            string vxod;
            cout << "������� �������� �����: ";
            cin >> vxod;

            bool found = false;

            for (int i = 0; i < room[player.current_loc].p.size(); ++i) {
                if (room[player.current_loc].p[i].portal_name == vxod) {
                    player.current_loc = room[player.current_loc].p[i].target;
                    found = true;
                    break;
                }

            }
            //
            if (!found) {
                cout << "������ ������� ���! ���������� �����." << endl;
                continue;
            }

        }




        if (chouse == "������") {
            // ������ ��������� �� ������� �������
            if (room[player.current_loc].item_l.empty()) {
                cout << "�� ���� ������� ��� ���������." << endl;
            }
            else {
                cout << "����� �������� ��������� �����:" << endl;
                for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
                    cout << i + 1 << ". " << items_item[(int)room[player.current_loc].item_l[i]] << endl;
                }

                // ������� ������ ����� �������� ��� �������
                cout << "�������� �������� �������� ��� ������� (��� 'no' ��� ������): ";
                string answer;
                cin >> answer;

                if (answer != "no") {

                    for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
                        // ��������� ��������� �������

                        if (answer == items_item[(int)room[player.current_loc].item_l[i]]) {

                            player.item_p.push_back(room[player.current_loc].item_l[i]);

                            cout << "�� ������� ������� " << items_item[(int)player.item_p.back()] << "." << endl;
                            room[player.current_loc].item_l.erase(room[player.current_loc].item_l.cbegin() + i);
                        }
                    }
                }
                if (answer == "no") {
                    cout << "�������� �����. ���������� ��� ���." << endl;
                }
            }
        }


        if (chouse == "�����") {
            if (player.item_p.empty()) {
                cout << "� ��� ��� ���������." << endl;
            }
            else {
                cout << "���� ��������:" << endl;
                for (int i = 0; i < player.item_p.size(); i++) {
                    cout << "- " << items_item[(int)player.item_p[i]] << endl;
                }

                cout << "������� �������� �������� ��� �������� (��� 'no' ��� ������): ";
                string answer;
                cin.ignore(); // ������� �����
                getline(cin, answer); // �� ������ ����� � ���������

                if (answer != "no") {
                    bool found = false;

                    for (int i = 0; i < player.item_p.size(); ++i) {
                        // ���������� �������� ������ � ��������� ��������
                        if (answer == items_item[(int)player.item_p[i]]) {
                            item_ item_dropped = player.item_p[i];

                            // ������� ������� �� ��������� � ����� � ������� �������
                            room[player.current_loc].item_l.push_back(item_dropped);
                            player.item_p.erase(player.item_p.begin() + i);

                            cout << "�� ������ �������: " << answer << "." << endl;

                            // ������: ���� � ����������� � ������ �������
                            if (player.current_loc == 1 && item_dropped == item_::panties) {
                                cout << "\n*** ������! ������� ���������� � �����������! ***\n";
                                exit(0); // ���������� ����
                            }

                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "� ��� ��� ������ ��������. ���������, ��� ��������� �����." << endl;
                    }
                }
            }
        }


    }

}



