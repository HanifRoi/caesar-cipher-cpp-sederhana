#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk enkripsi menggunakan Caesar Cipher
string encryptCaesar(string text, int shift) {
    string result = "";

    // Loop melalui setiap karakter dalam teks
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        // Enkripsi huruf besar
        if (isupper(ch)) {
            result += char(int(ch + shift - 65) % 26 + 65);
        }
        // Enkripsi huruf kecil
        else if (islower(ch)) {
            result += char(int(ch + shift - 97) % 26 + 97);
        }
        // Jika bukan huruf, tetap tambahkan tanpa perubahan
        else {
            result += ch;
        }
    }

    return result;
}

// Fungsi untuk dekripsi menggunakan Caesar Cipher
string decryptCaesar(string text, int shift) {
    string result = "";

    // Loop melalui setiap karakter dalam teks
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        // Dekripsi huruf besar
        if (isupper(ch)) {
            result += char(int(ch - shift - 65 + 26) % 26 + 65);
        }
        // Dekripsi huruf kecil
        else if (islower(ch)) {
            result += char(int(ch - shift - 97 + 26) % 26 + 97);
        }
        // Jika bukan huruf, tetap tambahkan tanpa perubahan
        else {
            result += ch;
        }
    }

    return result;
}

int main() {
    string text;
    int shift;

    cout << "Masukkan teks yang ingin dienkripsi: ";
    getline(cin, text);

    cout << "Masukkan nilai shift (kunci): ";
    cin >> shift;

    // Enkripsi
    string encryptedText = encryptCaesar(text, shift);
    cout << "Teks terenkripsi: " << encryptedText << endl;

    // Dekripsi
    string decryptedText = decryptCaesar(encryptedText, shift);
    cout << "Teks setelah dekripsi: " << decryptedText << endl;
	
	cin.ignore();
	cin.get();

    return 0;
}
