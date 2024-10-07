#include <iostream>
#include <string>

using namespace std;


string encrypt(string text, int shift) {
    string result = "";


    for (int i = 0; i < text.length(); i++) {
        
        if (isupper(text[i])) {
            result += char(int(text[i] + shift - 65) % 26 + 65);
        }
        
        else if (islower(text[i])) {
            result += char(int(text[i] + shift - 97) % 26 + 97);
        }
       
        else {
            result += text[i];
        }
    }
    return result;
}


string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift);
}

int main() {
    string text;
    int shift;
    char choice;

    do {
        cout << "Pilih: \n1. Enkripsi \n2. Dekripsi \n3. Keluar\n";
        cin >> choice;

        if (choice == '1') {
            
            cout << "Masukkan teks yang ingin dienkripsi: ";
            cin.ignore();  
            getline(cin, text);
            cout << "Masukkan jumlah pergeseran: ";
            cin >> shift;

            cout << "Hasil enkripsi: " << encrypt(text, shift) << endl;

        } else if (choice == '2') {
            
            cout << "Masukkan teks yang ingin didekripsi: ";
            cin.ignore();
            getline(cin, text);
            cout << "Masukkan jumlah pergeseran: ";
            cin >> shift;

            cout << "Hasil dekripsi: " << decrypt(text, shift) << endl;

        } else if (choice == '3') {
          
            cout << "Keluar dari program." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Coba lagi." << endl;
        }

        cout << "\n";

    } while (true);

    return 0;
}

