#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>

#include <windows.h>
#include <tchar.h>
#include <stdint.h>

void driverFunction() {
    
    // --- Character Types ---

    char a = 'A';                                 // Single-byte ASCII character, UTF-8 compatible
    std::cout << "char: " << a << "\n";

    wchar_t wa = L'A';                            // Wide character (UTF-16 on Windows), used for Unicode
    std::wcout << L"wchar_t: " << wa << L"\n";

    char16_t c16 = u'A';                          // UTF-16 character (Unicode code unit)
    std::wcout << L"char16_t (UTF-16 as wchar_t): " << (wchar_t)c16 << L"\n";

    char32_t c32 = U'A';                          // UTF-32 character (full Unicode code point)
    std::wcout << L"char32_t (UTF-32 as wchar_t): " << (wchar_t)c32 << L"\n";


    // --- String Types ---

    const char* asciiStr = "Hello ASCII";         // Null-terminated ASCII string (UTF-8 compatible)
    std::cout << "ASCII string: " << asciiStr << "\n";

    const wchar_t* wideStr = L"Hello UTF-16";     // UTF-16 string (used in Windows APIs)
    std::wcout << L"Wide string: " << wideStr << L"\n";

    const char16_t* utf16Str = u"नमस्ते";         // UTF-16 encoded string literal
    std::wcout << L"char16_t* as wchar_t*: " << (wchar_t*)utf16Str << L"\n";

    const char32_t* utf32Str = U"🌍🌎🌏";           // UTF-32 encoded string literal
    std::wcout << L"char32_t* as wchar_t*: " << (wchar_t*)utf32Str << L"\n";


    // --- Windows TCHAR / LP* Types ---

    TCHAR tcharStr[] = _T("Generic TCHAR string");  // TCHAR: maps to char (ANSI) or wchar_t (Unicode)
    std::wcout << L"TCHAR string: " << (wchar_t*)tcharStr << L"\n";

    LPSTR lpstr = (LPSTR)"Narrow LPSTR";            // LPSTR: pointer to null-terminated ANSI string
    std::cout << "LPSTR: " << lpstr << "\n";

    LPWSTR lpwstr = (LPWSTR)L"Wide LPWSTR";         // LPWSTR: pointer to null-terminated wide string
    std::wcout << L"LPWSTR: " << lpwstr << L"\n";

    LPCSTR lpcstr = "Narrow LPCSTR";                // LPCSTR: const ANSI string pointer
    std::cout << "LPCSTR: " << lpcstr << "\n";

    LPCWSTR lpcwstr = L"Wide LPCWSTR";              // LPCWSTR: const wide string pointer
    std::wcout << L"LPCWSTR: " << lpcwstr << L"\n";


    // --- Windows Integer Types ---

    BYTE b = 255;                                   // Unsigned 8-bit (0–255), often used for raw data
    std::cout << "BYTE: " << +b << "\n";

    WORD w = 65535;                                 // Unsigned 16-bit value (0–65535)
    std::cout << "WORD: " << w << "\n";

    DWORD dw = 4294967295;                          // Unsigned 32-bit (0–4,294,967,295)
    std::cout << "DWORD: " << dw << "\n";

    LONG l = -123456789;                            // Signed 32-bit integer
    std::cout << "LONG: " << l << "\n";

    ULONG ul = 123456789;                           // Unsigned 32-bit integer
    std::cout << "ULONG: " << ul << "\n";


    // --- Fixed-width Integer Types (stdint.h) ---

    int8_t i8 = -128;                               // Signed 8-bit (int8), exact-width
    std::cout << "int8_t: " << +i8 << "\n";

    uint8_t u8 = 255;                               // Unsigned 8-bit (uint8), exact-width
    std::cout << "uint8_t: " << +u8 << "\n";

    int16_t i16 = -32768;                           // Signed 16-bit (int16), exact-width
    std::cout << "int16_t: " << i16 << "\n";

    uint16_t u16 = 65535;                           // Unsigned 16-bit (uint16), exact-width
    std::cout << "uint16_t: " << u16 << "\n";

    int32_t i32 = -2147483648;                      // Signed 32-bit (int32), exact-width
    std::cout << "int32_t: " << i32 << "\n";

    uint32_t u32 = 4294967295;                      // Unsigned 32-bit (uint32), exact-width
    std::cout << "uint32_t: " << u32 << "\n";

    int64_t i64 = -9223372036854775807LL;           // Signed 64-bit (int64), exact-width
    std::cout << "int64_t: " << i64 << "\n";

    uint64_t u64 = 18446744073709551615ULL;         // Unsigned 64-bit (uint64), exact-width
    std::cout << "uint64_t: " << u64 << "\n";

}


int main()
{
    // Redirect standard input to read from input.txt
    // std::ifstream inFile("input.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(inFile.rdbuf());

    // // Redirect standard output to write to output.txt
    // std::ofstream outFile("output.txt");
    // std::streambuf *coutbuf = std::cout.rdbuf(outFile.rdbuf());

    // // Your Code Goes Here
    // driverFunction();

    // // Restore the original buffers (optional)
    // std::cin.rdbuf(cinbuf);
    // std::cout.rdbuf(coutbuf);

    driverFunction();

    return 0;
}