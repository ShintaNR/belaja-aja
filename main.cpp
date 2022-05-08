#include <iostream>
#include <stdlib.h>
using namespace std;

struct STACK{
    string dataStack[5];
    int top;
};

STACK S;

struct QUEUE {
    string dataQueue[5];
    int rear;
    int front;
};

QUEUE Q;


void inisialisasi() {
    S.top = -1;
}

int IsEmpty();
int IsFull();
bool isEmpty();
bool isFull();

void push(string data);
void enqueue(string data);

void pop();
void dequeue();

void cekdatastack();
void cekdataqueue();

int main() {
    system("cls");
    int pilih;
    string input;
    int jumlah;
    inisialisasi();
    ulang :
    do {
        cout << "=================================" << endl;
        cout << "=====PROGRAM STACK DAN QUEUE=====" << endl;
        cout << "=================================" << endl;
        cout << "1. Tambah Data (Sting)" << endl;
        cout << "2. Tampilkan data Stack" << endl;
        cout << "3. Tampilkan data Queue" << endl;
        cout << "4. Hapus Data Stack (Pop Data)" << endl;
        cout << "5. Hapus Data Queue (Dequeue Data)" << endl;
        cout << "6. Exit" << endl;
        cout << "=================================" << endl;
        cout << endl;
        cout << "Pilih : "; cin >> pilih;
        switch (pilih)
        {
        case 1: {
            cout << "Masukkan data : ";
            getline(cin, input);
            jumlah = input.length();
            for (int i = 0; i < jumlah; i++) {
                if (input[i] == ' ') {
                    jumlah--;
                }
            }
            if (jumlah < 7) {
                push(input);
            }
            else if (jumlah > 7) {
                enqueue(input);
            }
            else {
                push (input);
                enqueue(input);
            }

            cout << endl;
            cin.get();
            break;
        }
        case 2: {
            cout << "Data Stack : " << endl;
            cekdatastack();
            cout << endl;
            cin.get();
            break;
        }
        case 3: {
            cout << "Data Queue : " << endl;
            cekdataqueue();
            cout << endl;
            cin.get();
            break;
        }
        case 4: {
            pop();
            cin.get();
            break;
        }
        case 5: {
            dequeue();
            cin.get();
            break;
        }
        case 6: {
            return 0;
        }
        default: {
            cout << "Tidak ada dalam pilih" << endl;
            cout << " " << endl;
            goto ulang;
            break;
        }
        }
    } while (pilih >= 1 && pilih <= 6);
    cin.get();
}

int IsEmpty(){
    if (S.top == -1){
        return 1;
    }else{
        return 0;
    }
}

bool isEmpty() {
    return Q.rear == 0;
}

bool isFull() {
    if (Q.rear == 5) {
        return true;
    }else{
        return false;
    }
}
int IsFull(){
    if (S.top == 5 - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(string data) {
    if (IsFull() == 1) {
        cout << "Stack penuh" << endl;
    }
    else {
        S.top++;
        S.dataStack[S.top] = data;
    }
}

void enqueue(string data) {
    if (isFull()) {
        cout << "Queue penuh" << endl;
    }
    else {
        Q.dataQueue[Q.rear] = data;
        Q.rear++;
    }
}

void pop(){
    int x;
    cout << "Pop item sebanyak : ";
    cin >> x;
    for (int i = S.top; i <= S.top; i++) {
        S.top = S.top - x;
    }
}

void dequeue() {
    int x;
    if (isEmpty()){
        cout << "Antrian masih kosong" << endl;
    }
    else {
        cout << "Masukkan banyaknya dequeue : ";
        cin >> x;

        for (int i = Q.front; i < x; i++) {
            cout << "Mengambil data \"" << Q.dataQueue[Q.front] << "\"..." << endl;
            for (int i = Q.front; i < Q.rear; i++) {
                Q.dataQueue[i] = Q.dataQueue[i + 1];
            }
            Q.rear--;
        }
    }
}

void cekdatastack() {
    int i;
    if (IsEmpty() == 1) {
        cout << "Stack masih kosong" << endl;
    }
    else {
        for (i = 0; i <= S.top; i++) {
            cout << S.dataStack[i] << " ";
        }
    }
}

void cekdataqueue() {
    int i;
    if (isEmpty()) {
        cout << "Queue masih kosong" << endl;
    }
    else {
        for (int i = Q.front; i < Q.rear; i++){
            cout << Q.dataQueue[i] << ((Q.rear - 1 == i) ? "" : ",");
        }
    }
}
