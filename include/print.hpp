#include <string>
#include <fstream>
#include <iostream>

//!Функция вывода строки в поток вывода
/*!
\param text аргумент типа std::string
\param out аргумент типа std::ostream
*/
void print(const std::string& text, std::ostream& out = std::cout);

//! Функция для вывода строки в файловый поток
/*!
\param text аргумент типа std::string
\param out аргумент типа std::ofstream
*/

void print(const std::string& text, std::ofstream& out);
