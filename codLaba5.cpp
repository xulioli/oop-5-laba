/* ��������� �������� ������� �������� ����� ������������,
����������� �� ������� ����, �� ����� ���������� �������.������ �����
������ ��������� ����������� ������������ � ������ ������ � ������
�������.������� main() ������ �������������� ������ � ���������
�������� ���� ��������� �������.��� ������������� �������� ������� ���
������������ ����� ��������.��� ������������� ��������������
�������� ������ ��� ���������� �������������� ������������*/
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
        return (value == "����������" || value == "��������" || value == "���������������");
    }
    bool isValidMaterial(const string& value) {
        return (value == "����" || value == "�������");
    }

public:
    void energia() override {
        cout << "������� ������������ ������ ����� (�� 5 �� 48 �����): ";
        cin >> Energia;
        while (!isValidEnergia(Energia)) {
            cout << "������������ ����. ����������, ������� �������� �� 5 �� 48: ";
            cin >> Energia;
        }
    }

    void dial() override {
        cout << "������� ��� ���������� (����������, ��������, ���������������): ";
        cin >> dig;
        while (!isValidDial(dig)) {
            cout << "������������ ����. ����������, ������� '����������', '��������' ��� '���������������': ";
            cin >> dig;
        }
    }

    void Material() override {
        cout << "������� �������� (����, �������): ";
        cin >> material;
        while (!isValidMaterial(material)) {
            cout << "������������ ����. ����������, ������� '����' ��� '�������': ";
            cin >> material;
        }
    }

    void Cost() override {
        cout << "������� ���������: ";
        cin >> cost;
    }

    void vivod() override {
        cout << "������ ����������� �����:\n";
        for (int i = 0; i < schet; ++i) {
            cout << " ����" << i + 1 << ":\n";
            cout << "��� �����: �����������" << endl;
            cout << "������ ������: " << watchData[i][0] << "\n";
            cout << "��� ����������: " << watchData[i][1] << "\n";
            cout << "��������: " << watchData[i][2] << "\n";
            cout << "���������: $" << watchData[i][3] << "\n";
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
            cout << "�� ������ ���� ����� " << watchNumber << ". �������������!\n";
            // Remove the bought watch by shifting elements
            for (int i = watchNumber - 1; i < schet - 1; ++i) {
                for (int j = 0; j < 4; ++j) {
                    watchData[i][j] = watchData[i + 1][j];
                }
            }
            schet--;
        }
        else {
            cout << "�������� ����. ���������� �����\n";
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
        return (value == "����������" || value == "��������" || value == "���������������");
    }
    bool isValidMaterial(const string& value) {
        return (value == "����" || value == "�������");
    }

    void energia() override {
        cout << "������� ������������ ������ ����� (�� 5 �� 100 �����): ";
        cin >> Energia;
        while (!isValidEnergia(Energia)) {
            cout << "������������ ����. ����������, ������� �������� �� 5 �� 100: ";
            cin >> Energia;
        }
    }

    void dial() override {
        cout << "������� ��� ���������� (����������, ��������, ���������������): ";
        cin >> dig;
        while (!isValidDial(dig)) {
            cout << "������������ ����. ����������, ������� '����������', '��������' ��� '���������������': ";
            cin >> dig;
        }
    }

    void Material() override {
        cout << "������� �������� (����, �������): ";
        cin >> material;
        while (!isValidMaterial(material)) {
            cout << "������������ ����. ����������, ������� '����' ��� '�������': ";
            cin >> material;
        }
    }
    void Cost() override {
        cout << "������� ���������: ";
        cin >> cost;
    }

    void vivod() override {
        cout << "������ ������������ �����:\n";
        for (int i = 0; i < schet; ++i) {
            cout << " ���� " << i + 1 << ":\n";
            cout << "��� �����: ������������" << endl;
            cout << "����� ������: " << watchData[i][0] << "\n";
            cout << "��� ����������: " << watchData[i][1] << "\n";
            cout << "��������: " << watchData[i][2] << "\n";
            cout << "���������: $" << watchData[i][3] << "\n";
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
            cout << "�� ������ ���� ����� " << watchNumber << ". �������������!\n";
            for (int i = watchNumber - 1; i < schet - 1; ++i) {
                for (int j = 0; j < 4; ++j) {
                    watchData[i][j] = watchData[i + 1][j];
                }
            }
            schet--;
        }
        else {
            cout << "�������� ����. ���������� �����\n";
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
        return (value == "����������" || value == "��������" || value == "���������������");
    }
    bool isValidMaterial(const string& value) {
        return (value == "����" || value == "�������");
    }
    
    void energia() override {
        cout << "������� ������������ ������ ����� (�� 5 �� 100 �����): ";
        cin >> Energiaa;
       /* while (!isValidEnergia(Energiaa)) {
            cout << "������������ ����. ����������, ������� �������� �� 5 �� 100: ";
            cin >> Energiaa;
        }*/
    }

    void Material() override {
        cout << "������� �������� (����, �������): ";
        cin.ignore();
        getline(cin, material);
        while (!isValidMaterial(material)) {
            cout << "������������ ����. ����������, ������� '����' ��� '�������': ";
            cin >> material;
        }
    }

    void dial() override {
        cout << "������� ��� ���������� (����������, ��������, ���������������): ";
        cin >> dig;
        while (!isValidDial(dig)) {
            cout << "������������ ����. ����������, ������� '����������', '��������' ��� '���������������': ";
            cin >> dig;
        }
    }

    void Cost() override {
        cout << "������� ���������: ";
        cin >> cost;
    }

    void size() {
        cout << "������� ������ ��������� �����: ";
        cin >> Size;
        while (!isValidSize(Size)) {
            cout << "������������ ����. ������� ������ �� 30 �� 100��" << endl;
            cin >> Size;
        }
    }

    void vivod() override {
        cout << "������ ��������� �����:\n";
        for (int i = 0; i < schet; ++i) {
            cout << " ���� " << i + 1 << ":\n";
            cout << "��� �����: ���������" << endl;
            cout << "����� ������: " << waatchData[i][0] << "\n";
            cout << "������: " << waatchData[i][1] << "\n";
            cout << "��������: " << waatchData[i][2] << "\n";
            cout << "���������: $" << waatchData[i][3] << "\n";
            cout << "-------------------------\n";
        }
    }

    void buyWatch(int watchNumber) {
        if (watchNumber >= 1 && watchNumber <= schet) {
            cout << "�� ������ ���� ����� " << watchNumber << ". �������������!\n";
            for (int i = watchNumber - 1; i < schet - 1; ++i) {
                for (int j = 0; j < 5; ++j) {
                    waatchData[i][j] = waatchData[i + 1][j];
                }
            }
            schet--;
        }
        else {
            cout << "�������� ����. ���������� �����\n";
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
    cout << "������� ���������� �����: ";
    cin >> numWatches;

    WallClock WallWatches;
    electronicWatches myWatches;
    mechanicWatches mechWatches;
    system("cls");
    cout << "������� ������ �� ����������� �����" << endl;
    for (int i = 0; i < numWatches; ++i) {
        cout << "���� " << i + 1 << ":\n";
        myWatches.energia();
        myWatches.dial();
        myWatches.Material();
        myWatches.Cost();
        myWatches.choses();
    }

    system("cls");
    cout << "������� ������ � ������������ �����" << endl;
    for (int a = 0; a < numWatches; ++a) {
        cout << "���� " << a + 1 << ":\n";
        mechWatches.energia();
        mechWatches.dial();
        mechWatches.Material();
        mechWatches.Cost();
        mechWatches.choses();
    }

    system("cls");
    cout << "������� ������ � ��������� �����" << endl;
    for (int n = 0;n < numWatches;++n) {
        cout << "���� " << n + 1 << ":\n";
        WallWatches.energia();
        WallWatches.Material();
        WallWatches.size();
        WallWatches.Cost();
        WallWatches.choses();
    }

    cout << "����������� ����: " << endl;
    myWatches.vivod();
    cout << "������������ ����: " << endl;
    mechWatches.vivod();
    cout << "1)������ ����������� ����\n2)������ ������������ ����\n3)������ ��������� ����\n4)�����" << endl;
    cin >> choses;
    switch (choses)
    {
    case 1:
        cout << "������� ����� ����������� ����� ������� �� �� ������ ������ ";
        cin >> watchToBuy;
        myWatches.buyWatch(watchToBuy);
        myWatches.vivod();
        mechWatches.vivod();
        WallWatches.vivod();
        break;
    case 2:
        cout << "������� ����� ������������ ����� ������� �� �� ������ ������" << endl;
        cin >> watchToBuy;
        mechWatches.buyWatch(watchToBuy);
        myWatches.vivod();
        mechWatches.vivod();
        WallWatches.vivod();
        break;
    case 3:
        cout << "������� ����� ��������� ����� ������� �� �� ������ ������ " << endl;
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