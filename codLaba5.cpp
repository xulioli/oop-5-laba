/* Построить иерархию классов согласно схеме наследования,
приведенной на рисунке ниже, по любой предметной области.Каждый класс
должен содержать необходимые конструкторы и методы работы с полями
классов.Функция main() должна иллюстрировать работу с массивами
объектов всех созданных классов.При необходимости атрибуты доступа при
наследовании можно изменять.При необходимости самостоятельно
добавить классы для реализации множественного наследования*/
#include <iostream>
#include <string>
#include <locale>

using namespace std;

class virtealn {
public:
    virtual void energia() = 0;
    virtual void dial() = 0;
    virtual void size() = 0;
    virtual void Material() = 0;
    virtual void Cost() = 0;
    virtual void vivod() = 0;
    virtual void choses() = 0;
};

class watches : public virtealn {
protected:
    int cost;
    string Size;
    int schet = 0;
    string material;
    int Energiaa;
    string Energia;
    string dig;

public:
};

class electronicWatches : public watches {
private:
    static const int MAX_WATCHES = 5;
    string watchData[MAX_WATCHES][4];

public:
    bool isValidEnergia(const string& value) {
        int intValue = stoi(value);
        return (intValue >= 5 && intValue <= 48);
    }

    bool isValidDial(const string& value) {
        return (value == "аналоговые" || value == "цифровые" || value == "комбинированные");
    }
    bool isValidMaterial(const string& value) {
        return (value == "кожа" || value == "селикон");
    }

public:
    void energia() override {
        cout << "Введите длительность работы часов (от 5 до 48 часов): ";
        cin >> Energia;
        while (!isValidEnergia(Energia)) {
            cout << "Некорректный ввод. Пожалуйста, введите значение от 5 до 48: ";
            cin >> Energia;
        }
    }

    void dial() override {
        cout << "Введите тип циферблата (аналоговые, цифровые, комбинированные): ";
        cin >> dig;
        while (!isValidDial(dig)) {
            cout << "Некорректный ввод. Пожалуйста, введите 'аналоговые', 'цифровые' или 'комбинированные': ";
            cin >> dig;
        }
    }

    void Material() override {
        cout << "введите материал (кожа, селикон): ";
        cin >> material;
        while (!isValidMaterial(material)) {
            cout << "Некорректный ввод. Пожалуйста, введите 'кожа' или 'селикон': ";
            cin >> material;
        }
    }

    void Cost() override {
        cout << "введите стоимость: ";
        cin >> cost;
    }

    void vivod() override {
        cout << "данные электронных часов:\n";
        for (int i = 0; i < schet; ++i) {
            cout << " часы" << i + 1 << ":\n";
            cout << "тип часов: электронные" << endl;
            cout << "вренмя работы: " << watchData[i][0] << "\n";
            cout << "тип циферблата: " << watchData[i][1] << "\n";
            cout << "материал: " << watchData[i][2] << "\n";
            cout << "стоимость: $" << watchData[i][3] << "\n";
            cout << "-------------------------\n";
        }
    }

    void choses() override {
        watchData[schet][0] = Energia;
        watchData[schet][1] = dig;
        watchData[schet][2] = material;
        watchData[schet][3] = to_string(cost);
        schet++;
    }

    void buyWatch(int watchNumber) {
        if (watchNumber >= 1 && watchNumber <= schet) {
            cout << "Вы купили часы номер " << watchNumber << ". Наслаждайтесь!\n";
            // Remove the bought watch by shifting elements
            for (int i = watchNumber - 1; i < schet - 1; ++i) {
                for (int j = 0; j < 4; ++j) {
                    watchData[i][j] = watchData[i + 1][j];
                }
            }
            schet--;
        }
        else {
            cout << "неверный ввод. попробуйте снова\n";
        }
    }
    void size() {

    }
};


class mechanicWatches : public watches {
private:
    static const int MAXIM_WATCHES = 5;
    string watchData[MAXIM_WATCHES][4];

public:
    bool isValidEnergia(const string& value) {
        int intValue = stoi(value);
        return (intValue >= 5 && intValue <= 100);
    }

    bool isValidDial(const string& value) {
        return (value == "аналоговые" || value == "цифровые" || value == "комбинированные");
    }
    bool isValidMaterial(const string& value) {
        return (value == "кожа" || value == "селикон");
    }

    void energia() override {
        cout << "Введите длительность работы часов (от 5 до 100 часов): ";
        cin >> Energia;
        while (!isValidEnergia(Energia)) {
            cout << "Некорректный ввод. Пожалуйста, введите значение от 5 до 100: ";
            cin >> Energia;
        }
    }

    void dial() override {
        cout << "Введите тип циферблата (аналоговые, цифровые, комбинированные): ";
        cin >> dig;
        while (!isValidDial(dig)) {
            cout << "Некорректный ввод. Пожалуйста, введите 'аналоговые', 'цифровые' или 'комбинированные': ";
            cin >> dig;
        }
    }

    void Material() override {
        cout << "введите материал (кожа, селикон): ";
        cin >> material;
        while (!isValidMaterial(material)) {
            cout << "Некорректный ввод. Пожалуйста, введите 'кожа' или 'селикон': ";
            cin >> material;
        }
    }
    void Cost() override {
        cout << "введите стоимость: ";
        cin >> cost;
    }

    void vivod() override {
        cout << "данные механических часов:\n";
        for (int i = 0; i < schet; ++i) {
            cout << " часы " << i + 1 << ":\n";
            cout << "тип часов: механические" << endl;
            cout << "время работы: " << watchData[i][0] << "\n";
            cout << "тип циферблата: " << watchData[i][1] << "\n";
            cout << "материал: " << watchData[i][2] << "\n";
            cout << "стоимость: $" << watchData[i][3] << "\n";
            cout << "-------------------------\n";
        }
    }

    void choses() override {
        watchData[schet][0] = Energia;
        watchData[schet][1] = dig;
        watchData[schet][2] = material;
        watchData[schet][3] = to_string(cost);
        schet++;
    }

    void buyWatch(int watchNumber) {
        if (watchNumber >= 1 && watchNumber <= schet) {
            cout << "Вы купили часы номер " << watchNumber << ". Наслаждайтесь!\n";
            for (int i = watchNumber - 1; i < schet - 1; ++i) {
                for (int j = 0; j < 4; ++j) {
                    watchData[i][j] = watchData[i + 1][j];
                }
            }
            schet--;
        }
        else {
            cout << "неверный ввод. попробуйте снова\n";
        }
    }
    void size() {

    }
};

class WallClock : public watches {
    static const int WALL_WATCHES = 5;
    string waatchData[WALL_WATCHES][4];
public:

    WallClock(){}

    WallClock(int Energiaa, string dig,string material,int cost) {
        this->Energiaa = Energiaa;
        this->cost = cost;
        this->dig = dig;
        this->material = material;
    }

    bool isValidSize(const string& value) {
        int intSize = stoi(value);
        return(intSize >= 30 && intSize <= 100);
    }
   /* bool isValidEnergia(const int& value) {
        int intValue = value;
        return (intValue >= 5 && intValue <= 100);
    }*/

    bool isValidDial(const string& value) {
        return (value == "аналоговые" || value == "цифровые" || value == "комбинированные");
    }
    bool isValidMaterial(const string& value) {
        return (value == "кожа" || value == "селикон");
    }
    
    void energia() override {
        cout << "Введите длительность работы часов (от 5 до 100 часов): ";
        cin >> Energiaa;
       /* while (!isValidEnergia(Energiaa)) {
            cout << "Некорректный ввод. Пожалуйста, введите значение от 5 до 100: ";
            cin >> Energiaa;
        }*/
    }

    void Material() override {
        cout << "введите материал (кожа, селикон): ";
        cin.ignore();
        getline(cin, material);
        while (!isValidMaterial(material)) {
            cout << "Некорректный ввод. Пожалуйста, введите 'кожа' или 'селикон': ";
            cin >> material;
        }
    }

    void dial() override {
        cout << "Введите тип циферблата (аналоговые, цифровые, комбинированные): ";
        cin >> dig;
        while (!isValidDial(dig)) {
            cout << "Некорректный ввод. Пожалуйста, введите 'аналоговые', 'цифровые' или 'комбинированные': ";
            cin >> dig;
        }
    }

    void Cost() override {
        cout << "введите стоимость: ";
        cin >> cost;
    }

    void size() {
        cout << "введите размер настенных часов: ";
        cin >> Size;
        while (!isValidSize(Size)) {
            cout << "Некорректный ввод. введите размер от 30 до 100см" << endl;
            cin >> Size;
        }
    }

    void vivod() override {
        cout << "данные Настенных часов:\n";
        for (int i = 0; i < schet; ++i) {
            cout << " часы " << i + 1 << ":\n";
            cout << "тип часов: нвстенные" << endl;
            cout << "время работы: " << waatchData[i][0] << "\n";
            cout << "размер: " << waatchData[i][1] << "\n";
            cout << "материал: " << waatchData[i][2] << "\n";
            cout << "стоимость: $" << waatchData[i][3] << "\n";
            cout << "-------------------------\n";
        }
    }

    void buyWatch(int watchNumber) {
        if (watchNumber >= 1 && watchNumber <= schet) {
            cout << "Вы купили часы номер " << watchNumber << ". Наслаждайтесь!\n";
            for (int i = watchNumber - 1; i < schet - 1; ++i) {
                for (int j = 0; j < 5; ++j) {
                    waatchData[i][j] = waatchData[i + 1][j];
                }
            }
            schet--;
        }
        else {
            cout << "неверный ввод. попробуйте снова\n";
        }
    }

    void choses() {
        waatchData[schet][0] = Energia;
        waatchData[schet][1] = dig;
        waatchData[schet][2] = material;
        waatchData[schet][3] = Size;
        waatchData[schet][4] = to_string(cost);
        schet++;
    }
};

int HeadFunction_5() {
    int numWatches;
    int watchToBuy;
    int choses = 0;
    cout << "Введите количество часов: ";
    cin >> numWatches;

    WallClock WallWatches;
    electronicWatches myWatches;
    mechanicWatches mechWatches;
    system("cls");
    cout << "введите данные об электронных часах" << endl;
    for (int i = 0; i < numWatches; ++i) {
        cout << "часы " << i + 1 << ":\n";
        myWatches.energia();
        myWatches.dial();
        myWatches.Material();
        myWatches.Cost();
        myWatches.choses();
    }

    system("cls");
    cout << "введите данные о механических часах" << endl;
    for (int a = 0; a < numWatches; ++a) {
        cout << "часы " << a + 1 << ":\n";
        mechWatches.energia();
        mechWatches.dial();
        mechWatches.Material();
        mechWatches.Cost();
        mechWatches.choses();
    }

    system("cls");
    cout << "введите данные о настенных часах" << endl;
    for (int n = 0;n < numWatches;++n) {
        cout << "часы " << n + 1 << ":\n";
        WallWatches.energia();
        WallWatches.Material();
        WallWatches.size();
        WallWatches.Cost();
        WallWatches.choses();
    }

    cout << "электронные часы: " << endl;
    myWatches.vivod();
    cout << "механические часы: " << endl;
    mechWatches.vivod();
    cout << "1)купить электронные часы\n2)купить механические часы\n3)купить настенные часы\n4)выйти" << endl;
    cin >> choses;
    switch (choses)
    {
    case 1:
        cout << "введите номер электронных часов которые вы бы хотели купить ";
        cin >> watchToBuy;
        myWatches.buyWatch(watchToBuy);
        myWatches.vivod();
        mechWatches.vivod();
        WallWatches.vivod();
        break;
    case 2:
        cout << "введите номер механических часов которые вы бы хотели купить" << endl;
        cin >> watchToBuy;
        mechWatches.buyWatch(watchToBuy);
        myWatches.vivod();
        mechWatches.vivod();
        WallWatches.vivod();
        break;
    case 3:
        cout << "введите номер настенных часов которые вы бы хотели купить " << endl;
        cin >> watchToBuy;
        WallWatches.buyWatch(watchToBuy);
        myWatches.vivod();
        mechWatches.vivod();
        WallWatches.vivod();
        break;
    case 4:

        break;
    }
    return 0;
}