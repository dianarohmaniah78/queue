#include<iostream>
using namespace std;

const int MAX_QUEUE = 5;

struct Queue
{
    int depan;
    int belakang;
    int data[MAX_QUEUE];
};

void inisialisasi();
void enqueue(int data);
void dequeue();
void clear();
bool isEmpaty();
bool isFull();
void print();

Queue queue;

int main()
{
    inisialisasi();

    int PilihanMenu;
    int data;

    do
    {
        cout << ">>> Pilihan Menu Queue <<<" << endl;
        cout << "1. Menambah item Queue" << endl;
        cout << "2. Menghapus item Queue" << endl;
        cout << "3. Menampilkan item Queue" << endl;
        cout << "4. Mengosongkan item Queue" << endl;
        cout << "5. Selesai" << endl
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
        }

    } while (PilihanMenu != 5);

    cout << endl;

    system("pause");
}

void inisialisasi()
{
    queue.depan = queue.belakang = -1;
}
void enqueue(int data)
{
    queue.depan = 0;
    queue.belakang++;
    queue.data[queue.belakang] = data;
    cout << "data berhasil ditambahkan" << endl << endl;
}
void dequeue()
{
    cout << " Data " << queue.data[queue.depan] << " sudah dihapus" << endl << endl;
    for(int i = queue.depan; i <= queue.belakang; i++)
    {
        queue.data[i] = queue.data[i+1];

    }
    queue.belakang--;
}
void clear()
{
    queue.depan = queue.belakang = -1;
    cout << "Queue sudah dikosongkan" << endl << endl;
}
bool isEmpaty()
{
    return (queue.belakang == -1);
}
bool isFull()
{
    return (queue.belakang >= (MAX_QUEUE -1 ));
}
void print()
{
    cout << "isi queue : ";
    for(int i = queue.depan; i <= queue.belakang; i++)
    {
        cout << queue.data[i] << " ";

    }
    cout << endl << endl;
}
