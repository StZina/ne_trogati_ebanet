#include "Library.h"


    int main() {
        setlocale(LC_ALL, "Russian");
        SetConsoleCP(1251);
        InitGame();
        game();



        /*string g =  "TEST";
        to_lower(g);
        cout << g;*/



    }
    //void diolog(); {
      //    if (player.current_loc != 4) {
      //        cout << "���";

      //    }
      //    if (player.current_loc == 0 && find(player.item_p.begin(), player.item_p.end(), item_::notebook) != player.item_p.end()) {
      //        auto it = remove_if(player.item_p.begin(), player.item_p.end(), [](const item_& x) { return x == item_::notebook; });
      //        player.item_p.erase(it, player.item_p.end());

      //        // ������� ������� �� ���������
      //        text("\n������� �� ��������� ���������� ���������� � �������: \"�������!\"\n", 100);
      //    }
      //}
    /*if (chouse == "item") {

        for (int i = 0; i < player.item_p.size(); i++) {
            cout << "Predmet: " << items_item[(int)player.item_p[i]] << endl;
        }

    }

    if (chouse == "seek") {
        for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
            cout << "Predmet " << room[player.current_loc].item_l[i] << endl;
        }
    }
    }*/
    //#include <iostream>
    //#include <string> // ���������� ���������� ��� ������
    //#include <vector>
    //
    //using namespace std;
    //
    //enum class item_ { // ��������� ���������, � ��� ������������� �������� � ���� �����, axe �������� � ���� 0, sword �������� 1 � �.�
    //
    //    axe,
    //    sword,
    //    hemlet,
    //    key
    //};
    //
    //string itemLib[] = { "axe","sword","hemlet", "key" }; // ������ ������ � ������� ���������, � ������� ����� ������������ �������� 
    //
    //struct player_ {
    //
    //    int current_loc = 0; // ���������� �������� � ����� ������� ����� ���������� �����
    //    bool life = true; // ����������, ���������� �� ����� ������
    //    vector<item_> item; // ������� ������ ���� item_, ��� ����� ��� ��������, ��� ����� ��������� ���� �������� � ���� ����.
    //};
    //
    //
    //struct portal_ { // ��������� �������, � ������� ����� ������ ��� ����������, ��������� � ��������
    //
    //    string name; // ��� �������
    //    int target;  // ���� ����� ����� ������, � ����� �������
    //    bool activ;
    //
    //};
    //
    //struct location_ {      // ������� ��������� �������, � ��� ���� ��� � ���� ������, �� ������� �� ����� ������������
    //
    //    string name; // ��� �������
    //    vector<portal_>portal; // ������ ������ ��� ���� int, �� ��� ��� �� �������� ��������� ��������, � ����� �������� � ���������, ����� ����� ������ ��� ���� portal_ 
    //    vector<item_>item;
    //
    //};
    //
    //player_ user; // ������� ���������� ���������� ������
    //location_ room[4];
    //
    //void InitGame() {       // ������� ������� ������� ����� �������� ��� ���� �������� � ������ room
    //
    //    room[0].name = "Home"; // ������ ����� ������� ���
    //    room[0].portal.push_back({ "green_door", 1 , false }); // ���������� � ������� portal � ������� ������: ���, � ���� ����� �������
    //    room[0].portal.push_back({ "black_door", 2, false });
    //    room[0].item.push_back((item_::axe));// ������� �������
    //
    //    room[1].name = "room";
    //    room[1].portal.push_back({ "back", 0 , true });
    //    room[1].item.push_back((item_::sword));// �������� �������
    //    room[1].item.push_back((item_::hemlet));
    //
    //    room[2].name = "Entrance";
    //    room[2].portal.push_back({ "back", 0 , true });
    //    room[2].portal.push_back({ "iron_door", 3, false });
    //
    //    room[3].name = "Street";
    //
    //    user.item.push_back(item_::key); // �������� � ��� ��������� �����, ����� ��������������
    //
    //}
    //
    //// use ������, ���������� ������� �������
    //int main()
    //{
    //
    //    InitGame();
    //    string chouse; // ������� ���������� ��� ����� ������������
    //
    //    cout << "You're in location: " << room[user.current_loc].name << endl; // ������� ��� �������  � ������� ��������� �����
    //
    //    while (user.life) { // ���� ����, ���� ������������ �����
    //
    //        cin >> chouse;
    //
    //        if (chouse == "help") {
    //
    //            cout << "1.go\n2.list\n3.trunk\n4.pick\n5.drop\n6.use\n";
    //        }
    //
    //
    //        if (chouse == "go") { // ������ ������ ����� ������, ���� ����� go, ��� ����� ������������ ��� ��������� ������� � �������, ��� ��������� �����
    //
    //            for (int i = 0; i < room[user.current_loc].portal.size(); i++) {  // ���� �� ������� �������� � ����� ������ ��� ��������� ��������
    //
    //                auto p = room[user.current_loc].portal[i];
    //
    //                cout << room[user.current_loc].portal[i].name << (p.activ ? " is unlocked" : " is locked") << endl; // ����� ����� ��� �� ����� � ����� ��������.
    //            }
    //
    //
    //            cin >> chouse;// ��������� ���� �� ��� �������
    //
    //
    //            for (int i = 0; i < room[user.current_loc].portal.size(); i++) {
    //
    //
    //                if (chouse == room[user.current_loc].portal[i].name) { // ���� ���� ������������ �������� � ������ ������� �������
    //
    //                    if (room[user.current_loc].portal[i].activ) { // ��������, �� ������� �� ������
    //
    //                        user.current_loc = room[user.current_loc].portal[i].target; // �� �� ������� ������� ������, ������ �� ������ �������, ���� ����� ������, � ����� �������
    //
    //                        cout << "You're in location: " << room[user.current_loc].name << endl;
    //                    }
    //                    else {
    //                        cout << "LOCKED\n";
    //                    }
    //                }
    //            }
    //        }
    //
    //        if (chouse == "trunk") {
    //
    //            for (int i = 0; i < user.item.size(); i++) { // ���� �� ������� item, ��� ����� ��� ����������� 
    //                cout << itemLib[(int)user.item[i]] << endl; // � ��������� �������� ����������, ������� ��������� � ������� ��������� � int � ������� � ������ string
    //
    //            }
    //
    //        }
    //
    //        if (chouse == "list") { //  �������� ��� ��������, ����������� � �������
    //
    //            cout << "You have found: \n";
    //
    //            for (int i = 0; i < room[user.current_loc].item.size(); i++) {
    //
    //                cout << itemLib[(int)room[user.current_loc].item[i]] << endl;
    //            }
    //
    //        }
    //
    //        if (chouse == "pick") { // ��������� �������
    //
    //            cin >> chouse;
    //
    //            for (int i = 0; i < room[user.current_loc].item.size(); i++) {
    //
    //                if (chouse == itemLib[(int)room[user.current_loc].item[i]]) {
    //
    //                    cout << "You have picked item: " << itemLib[(int)room[user.current_loc].item[i]] << endl;
    //                    user.item.emplace_back(room[user.current_loc].item[i]); // ������� ������� � ��������� ������
    //                    room[user.current_loc].item.erase(room[user.current_loc].item.cbegin() + i); // ������ ������� �� �������
    //
    //                }
    //
    //            }
    //
    //        }
    //
    //        if (chouse == "drop") {
    //
    //            cin >> chouse;
    //
    //            for (int i = 0; i < user.item.size(); i++) {
    //
    //                if (chouse == itemLib[(int)user.item[i]]) {
    //
    //                    cout << "You have deleted item: " << itemLib[(int)user.item[i]] << endl;
    //                    room[user.current_loc].item.emplace_back(user.item[i]); // ������� ������� � ��������� �������
    //                    user.item.erase(user.item.cbegin() + i); // ������ ������� �� ��������� ������
    //
    //                }
    //
    //            }
    //
    //        }
    //
    //
    //        if (chouse == "use") {
    //
    //            int dir;
    //
    //            if (!user.item.empty()) {
    //
    //                for (int i = 0; i < user.item.size(); i++) {
    //
    //                    cout << i + 1 << ". " << itemLib[(int)user.item[i]] << endl;
    //
    //                }
    //
    //                cout << "Enter number item\n";
    //
    //                cin >> dir;
    //
    //
    //
    //
    //                switch ((int)user.item[dir - 1]) {
    //
    //                case 0: {
    //
    //                    cout << "use axe\n";
    //                    break;
    //
    //                }
    //
    //                case 1: {
    //
    //                    cout << "use sword\n";
    //                    break;
    //
    //                }
    //
    //                case 2: {
    //
    //                    cout << "use hemlet\n";
    //                    break;
    //
    //                }
    //
    //                case 3: {
    //
    //                    for (int i = 0; i < room[user.current_loc].portal.size(); i++) {
    //
    //                        cout << i + 1 << ". " << room[user.current_loc].portal[i].name << endl;
    //
    //                    }
    //                    cout << "Enter number door: \n";
    //
    //                    cin >> dir;
    //
    //                    room[user.current_loc].portal[dir - 1].activ ? room[user.current_loc].portal[dir - 1].activ = false : room[user.current_loc].portal[dir - 1].activ = true; //������� ��� ��������� ��������
    //
    //                    cout << "You're " << (room[user.current_loc].portal[dir - 1].activ ? "unlocked door " : "locked door ") << room[user.current_loc].portal[dir - 1].name << endl;
    //
    //                    break;
    //
    //                }
    //
    //                }
    //
    //
    //            }
    //        }
    //    }
    //}

