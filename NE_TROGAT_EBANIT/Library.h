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

class Hero {
public:
    string name;
    int current_loc = 0;
    int wallet = 1000;
    vector<item_> item_p;
    bool headphones_on = true;

    Hero() {}

    Hero(string name, int loc = 0, int wallet = 1000, bool headphones = true)
        : name(name), current_loc(loc), wallet(wallet), headphones_on(headphones) {
    }
};

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

string items_item[] = { "наушники", "трусики", "чашка", "журнал", "блокнот", "Эспрессо","Американо","Капучино" };

struct portal_ {
    string portal_name;
    int target;
    portal_(string a, int b) : portal_name(a), target(b) {}
};

struct location_ {
    string dis;
    string loc_name;
    vector<portal_> p;
    vector<item_> item_l;
    bool dis_shown = false;
   
};

class Player : public Hero {
public:
    int watch = 1;
    bool life = true;

    Player() {}

    Player(string name, int watch, bool life, int loc = 0, bool headphones = true)
        : Hero(name, loc, 1000, headphones), watch(watch), life(life) {
    }

    void print() {
        cout << watch << "\n" << life << "\n" << headphones_on << "\n" << current_loc << "\n";
    }
};



class Girl : public Hero {
public:
    int love_level = 0;

    Girl(string name, int love, int loc = 0)
        : Hero(name, loc), love_level(love) {
    }
};


vector<Girl> girls;
vector <portal_> port;
vector<product_> coffee_machine;
location_ room[5];
Player player;

void InitGame();
void game();
void intervio();
void intervio2();
void arcade_game();
void start();
//void 


void start() {

    player = Player("ИмяИгрока", 1, true);

    girls.push_back(Girl("Ресепшен", 0, 0));
    girls.push_back(Girl("Бухгалтерия", 50, 1));
    girls.push_back(Girl("Инженер", 50, 4));
    girls.push_back(Girl("Начальница", 20, 3));
    girls.push_back(Girl("Комусиси-тян", 80, 3));
    

    cout << txt.narativ[0];
   
    cin >> player.name;

    text(txt.narativ[1],10);
    cout << "Охайо, " << player.name << endl;
    for (int i = 3; i < 7; i++) {
        text(txt.narativ[i],10);
    }
   
    int choice;
    cin >> choice;

    switch (choice) {
    case 1: intervio(); break;
    case 2: intervio2(); break;
    default: cout << "Неверный выбор.\n"; break;
    }
}

void intervio() {
    cout << "\nВы просыпаетесь от звукового сигнала поезда, он оповещает, что прибыл на станцию Тикай.\n";
    cout << "Хотите пойти играть в автоматы или прийти на собеседование с опозданием?\n";
    cout << "1. Поиграть в автоматы, издалека они сияют неоновыми огнями\n";
    cout << "2. Ускориться, эйчар возможно еще ждёт\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Вы решили поиграть в автоматы, потому что лучше вообще не прийти на собеседование, чем опоздать.\n";
        cout << "Двери зала распахиваются, и вас мгновенно окутывают яркие огни игровых автоматов.\n";
        cout << "1. Поиграть в автомат Камень, ножницы, бумага, ящерица, Спок\n";
        cout << "2. Бежать на собеседование\n";
        cin >> choice;

        if (choice == 1) {
            arcade_game();
        }
        else if (choice == 2) {
            cout << "Вы слегка опаздываете, но вас всё же провожают в отдел HR.\n";
            cout << "Вам предлагают позицию младшего инженера, но испытание — три месяца бесплатной работы.\n";
        }
    }
    else if (choice == 2) {
        cout << "Вы слегка опаздываете, но вас всё же провожают в отдел HR.\n";
        cout << "Вам предлагают позицию младшего инженера, но испытание — три месяца бесплатной работы.\n";
    }
}

void arcade_game() {
    std::cout << "Вы подходите к автомату, где вас встречает величественный образ Спока, выполняющего своё легендарное приветствие.\nСердце замирает — вам предстоит сразиться за человечество, пусть на кону подарочные часы, вы верите что победите!\n";
    std::cout << "Скайнет вызывает тебя на поединок! Тебе предстоит отстоять честь человечества, сразившись в Камень, ножницы, бумага, ящерица, Спок.\n";

    std::cout << "Ваш выбор (0 - Камень, 1 - Ножницы, 2 - Бумага, 3 - Ящерица, 4 - Спок):\n";

    int human;

    std::cin >> human;

    int skynet = std::rand();
    skynet = skynet %= 5;

    if (skynet == 0) {
        std::cout << "Камень!\n";
    }
    if (skynet == 1) {
        std::cout << "Ножницы!\n";
    }
    if (skynet == 2) {
        std::cout << "Бумага!\n";
    }
    if (skynet == 3) {
        std::cout << "Ящерица!\n";
    }
    if (skynet == 4) {
        std::cout << "Спок!\n";
    }

    if (skynet == human) {
        std::cout << "Ничья\n";
    }
    else if (
        (skynet == 0 && human == 1) || // камень побеждает ножницы
        (skynet == 0 && human == 3) || // камень побеждает ящерицу
        (skynet == 1 && human == 0) || // ножницы побеждают камень
        (skynet == 1 && human == 4) || // ножницы побеждают Спока
        (skynet == 1 && human == 2) || // бумага побеждает ножницы
        (skynet == 2 && human == 3) || // бумага побеждает ящерицу
        (skynet == 3 && human == 4) || // ящерица побеждает Спока
        (skynet == 3 && human == 1) || // ящерица побеждает ножницы
        (skynet == 4 && human == 2) || // Спок побеждает бумагу
        (skynet == 4 && human == 0)    // Спок побеждает камень
        ) {
        std::cout << "Человечество проиграло!\n";
        player.watch = 0;
    }
    else {
        std::cout << "Человечество победило!\n";

    }

    std::cout << "Поздравляем, " << player.name << ", вы наслаждались мгновенным всплеском адреналина,\nно впереди вас ждёт мрачная перспектива: работа в Seven Eleven,\nгде единственным утешением станут просроченные продукты.\n";
    if (player.watch == 0) {
        cout << "К тому же, ваш отец выгнал вас из дома из за проигранных часов, вы неудачник!\n";
    }
}

void intervio2() {
    cout << "Вы просыпаетесь и видите 30 минут до собеседования.\n";
    cout << "1. Выпить кофе\n";
    cout << "2. Прийти раньше\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Вы заходите в кофейню. Заказ принимает Комусиси-тян.\n";
        cout << "1. Кофе и пирожное\n";
        cout << "2. Только кофе\n";
        cin >> choice;

        if (choice == 1) {
            cout << "Комусиси-тян делится своими проблемами. Вы решаете остаться с ней и проваливаете собеседование.\n";
            girls[4].love_level += 20;
        }
        else {
            cout << "Вы идете на собеседование в хорошем настроении. Собеседование отменено — вас всё равно берут!\n";
        }
    }
    else {
        cout << "Вас провожают к директору. Он предлагает работу с испытательным сроком.\n";
    }

    player.item_p.push_back(item_::headphones);
    cout << "У вас есть наушники.\n";
}
//void InitGirls() {
//    girls.push_back(Girl("Ресепшен", 0));
//    girls.push_back(Girl("Бухгалтерия", 50));
//    girls.push_back(Girl("Инженер", 50));
//    girls.push_back(Girl("Начальница", 20));
//    girls.push_back(Girl("Комусиси-тян", 80));
//}

void InitGame() {
    port.push_back(portal_("Ресепшен", 0));
    port.push_back(portal_("69", 1));
    port.push_back(portal_("Туалет", 2));
    port.push_back(portal_("44", 3));
    port.push_back(portal_("Завод", 4));
    
    room[0].loc_name = "Ресепшен";
    room[0].dis = "Сегодня на ресепшене меня встретила незнакомка...\n";
    room[0].p.push_back({ "69", 1 });
    room[0].p.push_back({ "Туалет", 2 });

    room[1].loc_name = "Бухгалтерия";
    room[1].dis = "Очаровательная помощница бухгалтера...\n";
    room[1].p.push_back({ "44", 3 });
    room[1].p.push_back({ "Завод", 4 });
    room[1].p.push_back({ "Ресепшен", 0 }); 

    room[2].loc_name = "Тубзик";
    room[2].dis = "Прохладный воздух...\n";
    room[2].p.push_back({ "Ресепшен", 0 });

    room[3].loc_name = "Место отдыха";
    room[3].dis = "Кофе и блокнот...\n";
    room[3].p.push_back({ "69", 1 });

    room[4].loc_name = "Отдел производства";
    room[4].dis = "Инженер приветливо улыбается...\n";
    room[4].p.push_back({ "69", 1 });
    room[4].p.push_back({ "44", 1 });

    room[2].item_l.push_back(item_::panties);
    room[3].item_l.push_back(item_::cup);
    room[3].item_l.push_back(item_::notebook);
    room[4].item_l.push_back(item_::magazine);

    //coffee_machine.clear();
    coffee_machine.push_back({ "Эспрессо", 150 });
    coffee_machine.push_back({ "Американо", 120 });
    coffee_machine.push_back({ "Капучино", 180 });

}

void coffee_automat() {

    int choice;
    while (player.wallet > 0) {
        cout << "\n=== Кофейный автомат ===" << endl;
        cout << "Ваш баланс: " << player.wallet << " йен" << endl;
        cout << "Ассортимент:\n";
        cout << "Номер\tНазвание\tЦена\t\n";

        for (int i = 0; i < coffee_machine.size(); ++i) {
            cout << i + 1 << ".\t" << coffee_machine[i].name << "\t" << coffee_machine[i].price << "\t" << endl;
        }

        cout << "Выберите номер кофе (0 - выход): ";
        cin >> choice;

        if (choice == 0) {
            cout << "Вы отошли от автомата.\n";
            break;
        }

        if (choice < 1 || choice > coffee_machine.size()) {
            cout << "Некорректный выбор.\n";
            continue;
        }

        product_& selected = coffee_machine[choice - 1];



        if (selected.price > player.wallet) {
            cout << "Недостаточно средств " << ".\n";
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

        cout << "Вы купили: " << selected.name << ". Баланс: " << player.wallet << " йен.\n";

    }



}

void game() {
    

    while (true) {
        text("Вы находитесь в ", 50);
        cout << room[player.current_loc].loc_name << endl;

        if (!room[player.current_loc].dis_shown) {
            text(room[player.current_loc].dis, 50);
            room[player.current_loc].dis_shown = true;
        }

        string chouse;
        cin >> chouse;
        chouse = to_lower(chouse);



        if (chouse == "кофе") {
            if (player.current_loc == 3) {
                coffee_automat();
            }
            else {
                std::cout << "Здесь нет кофейного автомата!" << std::endl;
            }
        }
        if (chouse == "иди") {
            for (const auto& portal : room[player.current_loc].p) {
                cout << "Дверь: " << portal.portal_name << endl;
            }

            cout << "Введите название двери: ";
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
            if (!found) cout << "Такого портала нет.\n";

        }

        else if (chouse == "возьми") {
            if (room[player.current_loc].item_l.empty()) {
                cout << "На этой локации нет предметов.\n";
            }
            else {
                cout << "Доступные предметы:\n";
                for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
                    cout << i + 1 << ". " << items_item[(int)room[player.current_loc].item_l[i]] << endl;
                }
                cout << "Введите название предмета (или 'no' для отмены): ";
                cin.ignore();
                string answer;
                getline(cin, answer);
                if (to_lower(answer) != "no") {
                    bool picked = false;
                    for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
                        if (to_lower(answer) == to_lower(items_item[(int)room[player.current_loc].item_l[i]])) {
                            player.item_p.push_back(room[player.current_loc].item_l[i]);
                            cout << "Вы подняли " << items_item[(int)player.item_p.back()] << endl;
                            room[player.current_loc].item_l.erase(room[player.current_loc].item_l.begin() + i);
                            picked = true;
                            break;
                        }
                    }
                    if (!picked) cout << "Такого предмета нет на локации.\n";
                }
            }
        }
      


        else if (chouse == "отдай") {
            if (player.item_p.empty()) {
                cout << "У вас нет предметов.\n";
            }
            else {
                cout << "Ваши предметы:\n";
                for (auto& item : player.item_p) {
                    cout << "- " << items_item[(int)item] << endl;
                }
                cout << "Введите название предмета для передачи (или 'no' для отмены): ";
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
                            cout << "Вы отдали " << answer << endl;
                            if (player.current_loc == 1 && item_dropped == item_::panties) {
                                cout << "\n*** ПОБЕДА! Трусики доставлены! ***\n";
                                exit(0);
                            }
                            found = true;
                            break;
                        }
                    }
                    if (!found) cout << "У вас нет такого предмета.\n";
                }
            }
        }
        else if (chouse == "снять") {
            if (player.headphones_on) {
                player.headphones_on = false;
                cout << "Вы сняли наушники и начали слышать окружающих.\n";

                if (player.current_loc == 0) {
                    cout << "Девушка за ресепшеном: \"Сколько можно, иди уже!\"\n";
                }
                else if (player.current_loc == 1) {
                    cout << "Помощница бухгалтера: \"Кофе остынет, если ты будешь здесь прохлаждаться\"\n";
                }
                else if (player.current_loc == 3) {
                    cout << "Начальница: \"Ладно, можешь пить из моей кружки, считай это премия\"\n";
                }
                else if (player.current_loc == 4) {
                    cout << "Старшая смены: \"Ты очень милый, я бы накормила тебя своей кимчи\"\n";
                }
            }
            else {
                cout << "Вы уже сняли наушники.\n";
            }
        }
        else if (chouse == "одеть") {
            if (!player.headphones_on) {
                player.headphones_on = true;
                cout << "Вы надели наушники и перестали слышать окружающих.\n";
            }
            else {
                cout << "Вы уже в наушниках.\n";
            }

        }





    }
}

// (СТРУКТУРА )ВЕКТОР СУЧКИ , ОПИСАНИЕ, ФЛАГИ
// наследование 



