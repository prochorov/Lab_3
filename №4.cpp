#include <iostream>
#include <cstring>

#define INVALID_STRING -1
#define INVALID_KEY -2
#define INVALID_CMD -3

#define CMD_ENCRYPT 1
#define CMD_DECRYPT 2

using namespace std;

void encrypt(const char * source, char * result, int cols, int rows)
{
for (int x = 0; x < cols; x++) {
for (int y = 0; y < rows; y++) {
*result++ = source[y * cols + x];
}
}
*result = 0;
}

void decrypt(const char * source, char * result, int cols, int rows)
{
for(int y = 0; y < rows; y++) {
for(int x = 0; x < cols; x++) {
*result++ = source[x * rows + y];
}
}
*result = 0;
}

int copy_str_with_pad(const char * src, size_t source_len, char * dst, size_t dst_len, char pad)
{
if(dst_len < source_len)
return EINVAL;

// Заполняем буфер заполнителем с конца
while(dst_len >= source_len)
dst[--dst_len] = pad;

// Копируем строку в буфер
while(source_len--)
*dst++ = *src++;

return 0;
}

int main()
{
char cmd;
int m, n, length;
string deist;
string soobsh;

cout << "Выберите, какую операцию нужно выполнить с сообщением, " << endl << "(З)ашифровать или (P)асшифровать [З/Р]: ";
cin >> deist;

if(deist == "з" || deist =="З") {
cmd = CMD_ENCRYPT;
} else if(deist == "р" || deist == "Р") {
cmd = CMD_DECRYPT;
} else {
cout << "Ошибка: недопустимая команда" << endl;
return INVALID_CMD;
}

cout << "Введите сообщение: ";
cin >> soobsh;

for(const char *ptr = soobsh.c_str(); *ptr != 0; ptr++) {
if(*ptr < 'a' || *ptr > 'z') {
cout << "Ошибка: сообщение содержит некорректные символы" << endl;
return INVALID_STRING;
}
}

length = soobsh.size();

cout << "Введите ключ (кол-во строк): ";
cin >> m;

if (m >= (length / 2)) {
cout << "Ошибка: введеный ключ некоректен" << endl;
return INVALID_KEY;
}

n = ((length - 1) / m) + 1;

char * source = new char[m * n];
char * result = new char[m * n + 1];

// Копируем исходную строку, и дозаполняем её пробелами, потому что там сейчас мусор
copy_str_with_pad(soobsh.c_str(), soobsh.size(), source, m*n, ' ');

if(cmd == CMD_ENCRYPT)
encrypt(source, result, n, m);
else
decrypt(source, result, n, m);

cout << "Результат: "<<result << endl;

delete[] result;
delete[] source;

return 0;
}