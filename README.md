

## Laboratory work IV

Данная лабораторная работа посвещена изучению систем автоматизации сборки проекта на примере **CMake**

```ShellSession
$ open https://cmake.org/
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab04** на сервисе **GitHub**
- [x] 2. Ознакомиться со ссылками учебного материала
- [x] 3. Выполнить инструкцию учебного материала
- [x] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=<имя_пользователя>
```

```ShellSession
Создание директории новой лабы на основе предыдущей
$ git clone https://github.com/${GITHUB_USERNAME}/lab03.git lab04 #клонируем репозиторий lab03 в директорию lab04
$ cd lab04 #переходим в данную директорию
$ git remote remove origin #удаляем текущую ветку origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab04.git #добавляем удалённый репозиторий
```

```ShellSession
Компиляция файлов print.cpp и example1.cpp
$ g++ -I./include -std=c++11 -c sources/print.cpp #компиляция print.cpp
$ ls print.o #проверка на наличие файла
$ ar rvs print.a print.o #архивация объектного файла, создание статической библиотеки
$ file print.a #вывод информации о файле
$ g++ -I./include -std=c++11 -c examples/example1.cpp  #компиляция example1.cpp
$ ls example1.o #проверка на наличие файла
$ g++ example1.o print.a -o example1 # сборка с учетом библиотеки print.a
$ ./example1 && echo #вывод текста
```

```ShellSession
Компиляция example2.cpp
$ g++ -I./include -std=c++11 -c examples/example2.cpp
$ ls example2.o
$ g++ example2.o print.a -o example2
$ ./example2
$ cat log.txt && echo
```

```ShellSession
Удаление файлов и библиотеки
$ rm -rf example1.o example2.o print.o 
$ rm -rf print.a 
$ rm -rf example1 example2
$ rm -rf log.txt
```

```ShellSession
Редактирование CMakeLists.txt

$ cat > CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.0)
project(print)
EOF
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
EOF
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF
add_library(print STATIC \${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
EOF
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF
include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)
EOF
```

```ShellSession
Запуск сборки cmake
$ cmake -H. -B_build
$ cmake --build _build
```

```ShellSession
Редактирование CMakeLists.txt
$ cat >> CMakeLists.txt <<EOF

add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF

target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF
```

```ShellSession
Сборка файлов
$ cmake --build _build
$ cmake --build _build --target print
$ cmake --build _build --target example1
$ cmake --build _build --target example2
```

```ShellSession
Проверка работы примеров
$ ls -la _build/libprint.a #информация о libprint.a
$ _build/example1 && echo
hello
$ _build/example2
$ cat log.txt && echo
hello
```

```ShellSession
перемещение файла CMakeLists
$ git clone https://github.com/tp-labs/lab04 tmp #клонируем репозиторий lab04 в директорию tmp
$ mv -f tmp/CMakeLists.txt . #перемещение файла CMakeLists.txt в текущую директорию
$ rm -rf tmp #удаление tmp
```

```ShellSession
Сборка проекта
$ cat CMakeLists.txt #просмотр файла
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
$ cmake --build _build --target install
$ tree _install #отображение проекта в виде дерева
```

```ShellSession
Коммит изменений
$ git add CMakeLists.txt
$ git commit -m"added CMakeLists.txt"
$ git push origin master
```

## Report

```ShellSession
Создание отчета 
$ cd ~/workspace/labs/
$ export LAB_NUMBER=04
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
