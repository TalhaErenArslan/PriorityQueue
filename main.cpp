#include "kilometer_queue.h" 
#include <limits>
using namespace std;

int main()
{
    KilometerQueue q3; 
    q3.setFilename("queue.txt");

    char choice;
    bool exitMenu = false; 
    do
    {
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "1. Uzakligi ve Adresi gir" << endl;
        cout << "2. Kuryeyi yola cikar( Bu secenek yola cikarilmislari gostermez !)" << endl;
        cout << "0. Cikis" << endl; 
        cout << "Secim: "<< endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
            case '1':
            {   
                
                while (true)
                {
                    int kilometer;
                    string address;
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "Km girin (Cikmak icin '0'a basiniz ): "<< endl;
                    cout << "-------------------------------------------------------------------------" << endl;
                    cin >> kilometer;
                    cin.ignore();

                    if (kilometer == 0)
                        break;
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "Adresi ve ismi giriniz: "<< endl;
                    cout << "-------------------------------------------------------------------------" << endl;
                    getline(cin, address);
                    q3.push_back(kilometer, address);
                }

                q3.saveToFile();
                cout << "Veriler kaydedildi." << endl;
                break;
            }
            case '2':
            {
               q3.loadFromFile();
    Customer c;
    c = q3.front();
    while (c.kilometer != -1)
    {
        cout << c.kilometer << ", " << c.address << endl;
        q3.pop_front();
        c = q3.front();
    }
            }
            case '0': 
            {
                exitMenu = true;
                break;
            }
            default:
                cout << "Gecersiz secim." << endl;
        }
    } while (!exitMenu);

    return 0;
}
