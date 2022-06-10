#include <iostream>
using namespace std;

const int MAX_QUEUE = 5;
int sort = 0;

struct Queue
{
    int depan;
    int belakang;
    string data[MAX_QUEUE];
};

void inisialisasi();
void enqueue(string data);
void dequeue();
void clear();
bool isEmpaty();
bool isFull();
void print();
void sorting();

Queue queue;

int main()
{
    inisialisasi();

    int PilihanMenu;
    string data;

    do
    {
        cout << ">>> Pilihan Menu Queue <<<" << endl;
        cout << "1. Menambah item Queue" << endl;
        cout << "2. Menghapus item Queue" << endl;
        cout << "3. Menampilkan item Queue" << endl;
        cout << "4. Mengosongkan item Queue" << endl;
        cout << "5. Mengurutkan item Queue" << endl
             << endl;

        cout << "Masukkan Pilihan Anda :  ";
        cin >> PilihanMenu;

        cout << endl;

        switch (PilihanMenu)
        {
        case 1:
            cout << "Masukkan Data :  ";
            cin >> data;
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;

        case 3:
            print();
            break;
        case 4:
            clear();
            break;
        case 5:
            sorting();
            break;
        default:
            cout << "Pilihan menu salah!" << endl;
            break;
        }
    } while (PilihanMenu != 6);

    cout << endl;

    system("pause");
}

void inisialisasi()
{
    queue.depan = queue.belakang = -1;
}
void enqueue(string data)
{
    if (isFull())
    {
        cout << "Data sudah full" << endl <<endl;
    }
    else
    {
        queue.depan = 0;
        queue.belakang++;
        queue.data[queue.belakang] = data;
        cout << "data berhasil ditambahkan" << endl
             << endl;
    }
}
void dequeue()
{
    if (isEmpaty())
    {
        cout << "Data masih kosong" << endl;
    }
    else
    {

        cout << " Data " << queue.data[queue.depan] << " sudah dihapus" << endl
             << endl;
        for (int i = queue.depan; i <= queue.belakang; i++)
        {
            queue.data[i] = queue.data[i + 1];
        }
        queue.belakang--;
    }
}
void clear()
{
    queue.depan = queue.belakang = -1;
    cout << "Queue sudah dikosongkan" << endl
         << endl;
}
bool isEmpaty()
{
    return (queue.belakang == -1);
}
bool isFull()
{
    return (queue.belakang >= (MAX_QUEUE - 1));
}
void print()
{
    if (isEmpaty())
    {
        cout << "Data masih kosong" << endl;
    }
    else
    {
        cout << "isi queue : ";
        for (int i = queue.depan; i <= queue.belakang; i++)
        {
            cout << queue.data[i] << " ";
        }
        cout << endl
             << endl;
    }
}

void sorting()
{
    if (isEmpaty())
    {
        cout << "Data masih kosong, tidak bisa mengurutkan" << endl;
    }
    else
    {
        for (int i = 0; i <= queue.belakang; i++)
        {
            for (int j = 0; j <= queue.belakang; j++)
            {
                if (queue.data[i] < queue.data[j])
                {
                    string temp = queue.data[i];
                    queue.data[i] = queue.data[j];
                    queue.data[j] = temp;
                }
            }
        }
        print();
    }
}
