
## Laboratory work III

Данная лабораторная работа посвещена изучению систем контроля версий на примере **Git**.

```bash
$ open https://git-scm.com
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab03** и с лиценцией **MIT**
- [x] 2. Ознакомиться со ссылками учебного материала
- [x] 3. Выполнить инструкцию учебного материала
- [x] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=Polly-99 
$ export GITHUB_EMAIL=prasnach@mail.ru
$ alias edit=vi
```

```ShellSession
$ mkdir lab03 && cd lab03 #создаем новую директорию и заходим в нее
$ git init  #создается пустой репозиторий в виде директории
$ git config --global user.name ${GITHUB_USERNAME} #указываем имя и адрес электронной почты
$ git config --global user.email ${GITHUB_EMAIL}
$ git config -e --global
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab03 #добавляем удалённый репозиторий
$ touch README.md #создаем пустой файл README.md
$ git status #смотрим состояние проекта, измененные и не добавленные файлы
$ git add README.md #добавляет README.md в индекс для последующего коммита
$ git commit -m"added README.md" #совершение коммита
$ git push origin master #вносим созданные изменения в удаленный репозиторий
```

Добавить на сервисе **GitHub** в репозитории **lab03** файл **.gitignore**
со следующем содержимом:

```ShellSession
*build*/
*install*/
*.swp
```

```ShellSession
$ git pull origin master #забирает изменения и проводит слияние с активной веткой
$ git log #получаем информацию об истории коммитов
```

```ShellSession
#создаем директории
$ mkdir sources
$ mkdir include
$ mkdir examples

#создаем и редактируем файлы print.cpp, print.hpp, example1.cpp и example2.cpp

$ cat > sources/print.cpp <<EOF
#include <print.hpp>

void print(const std::string& text, std::ostream& out) {
  out << text;
}

void print(const std::string& text, std::ofstream& out) {
  out << text;
}
EOF
```

```ShellSession
$ cat > include/print.hpp <<EOF
#include <string>
#include <fstream>
#include <iostream>

void print(const std::string& text, std::ostream& out = std::cout);
void print(const std::string& text, std::ofstream& out);
EOF
```

```ShellSession
$ cat > examples/example1.cpp <<EOF
#include <print.hpp>

int main(int argc, char** argv) {
  print("hello");
}
EOF
```

```ShellSession
$ cat > examples/example2.cpp <<EOF
#include <fstream>
#include <print.hpp>

int main(int argc, char** argv) {
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF
```

```ShellSession
$ edit README.md #редактируем README.md
```

```ShellSession
$ git status #смотрим состояние проекта, измененные и не добавленные файлы
$ git add . ##добавляет все изменения в индекс
$ git commit -m"added sources" #совершение коммита
$ git push origin master #вносим созданные изменения в удаленный репозиторий
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=03
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```
