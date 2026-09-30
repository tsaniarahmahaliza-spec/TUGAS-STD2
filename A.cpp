#include <iostream>

using namespace std;

int main()
{
    string nim[40];
    string nama[40];
    string persentaseAbsen[40];

    for (int i = 0; i < 40; i++)
    {
        cin >> nim[i] >> nama[i] >> persentaseAbsen[i];
    }

    cout << endl;
    cout << "Data Mahasiswa" << endl;
    for (int i = 0; i < 40; i++)
    {
        cout << nama[i] << " / " << nim[i] << " / " << persentaseAbsen[i] << endl;
    }
    return 0;
}