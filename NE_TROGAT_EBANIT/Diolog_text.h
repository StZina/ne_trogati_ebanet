#include <string>
#include <vector>

using namespace std;

struct text_ {
    vector<string> dialog;
    vector<string> narativ;
    vector<string> ERROR;
};




//struct narativ {
//    string narativ;
//};

text_ txt;
//vector <diolog> dio;
//diolog


void one() {

    //
    txt.narativ.push_back("Введите ваше имя: ");//0


    //string namequest = "Введите ваше имя: ";
    //
    //cin >> player.name;

    txt.narativ.push_back("Вы только выпустились из Токийского университета.\nТеперь вы инженер по микроэлектронике, вам предстоит выбрать корпорацию,\nна которую вы потратите свою длинную Японскую жизнь.\n");//1
    
    txt.narativ.push_back("Охайо, ");//2
    txt.narativ.push_back("\nВы находитесь на бирже труда, Япония только восстановилась после коллапса финансового пузыря.\nНачало нового тысячелетия — это коктейль из надежды и тревоги.\n");//3
    txt.narativ.push_back("Всего две компании откликнулись на ваше резюме, но назначили собеседование на одно и то же время.\nКакую компанию вы выберете?\n");//4
    txt.narativ.push_back("1. Идти на собеседование в ООО Херовато\n");//5
    txt.narativ.push_back("2. Идти на собеседование в ООО Херанука\n");//6

    //int choice;
    //cin >> choice;

    //switch (choice) {
    //case 1: intervio(); break;
    //case 2: intervio2(); break;
    //default: cout << "Неверный выбор.\n"; break;
    //}
}