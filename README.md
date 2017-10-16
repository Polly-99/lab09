## Laboratory work VI

Данная лабораторная работа посвещена изучению фреймворков для тестирования на примере **Catch**

```ShellSession
$ open https://github.com/philsquared/Catch
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab06** на сервисе **GitHub**
- [x] 2. Выполнить инструкцию учебного материала
- [x] 3. Ознакомиться со ссылками учебного материала
- [x] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=Polly-99
```

Создание директории новой лабы на основе предыдущей
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab05 lab06
$ cd lab06
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab06
```

Создание тестов
```ShellSession
$ mkdir tests #создание директории tests
$ wget https://github.com/philsquared/Catch/releases/download/v1.9.3/catch.hpp -O tests/catch.hpp # #получение catch.hpp с сайта, записывание его в директорию tests
$ cat > tests/main.cpp <<EOF # создание и редактирование файла main.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
EOF
```

Создание CMakeLists.txt
```ShellSession
$ sed -i '/option(BUILD_EXAMPLES "Build examples" OFF)/a\ #добавляем строку в потоковом текстовом редакторе
option(BUILD_TESTS "Build tests" OFF)
' CMakeLists.txt
$ cat >> CMakeLists.txt <<EOF # редактирование файла CMakeLists.txt
if(BUILD_TESTS)
	enable_testing() # включение тестирования
	file(GLOB \${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
	add_executable(check \${\${PROJECT_NAME}_TEST_SOURCES})
	target_link_libraries(check \${PROJECT_NAME} \${DEPENDS_LIBRARIES})
	add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")  # Добавление теста к проекту; -s - вывод успешного выполнения тестов ; -r compact - формат вывода
endif()
EOF
```

Создание теста
```ShellSession
$ cat >> tests/test1.cpp <<EOF
#include "catch.hpp"
#include <print.hpp>

TEST_CASE("output values should match input values", "[file]") {
  std::string text = "hello";
  std::ofstream out("file.txt");
  
  print(text, out);
  out.close();
  
  std::string result;
  std::ifstream in("file.txt");
  in >> result;
  
  REQUIRE(result == text);
}
EOF
```

Сборка и запуск тестов
```ShellSession
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install -DBUILD_TESTS=ON
$ cmake --build _build
$ cmake --build _build --target test #запуск теста после сборки
Running tests...
Test project /home/polina/lab06/_build
    Start 1: check
1/1 Test #1: check ............................  Passed   0.04 sec.

100% tests passed, 0 tests faild out of 1

Total Test time (real) =  0.05 sec

```

Редактирование файлов
```ShellSession
$ sed -i 's/lab05/lab06/g' README.md # замена "lab05" на "lab06"
$ sed -i 's/\(DCMAKE_INSTALL_PREFIX=_install\)/\1 -DBUILD_TESTS=ON/' .travis.yml # дописывание строки 
$ sed -i '/cmake --build _build --target install/a\ #добавление строки - cmake --build _build --target test после cmake --build _build --target install
- cmake --build _build --target test
' .travis.yml
```

Проверка работоспособности .travis.yml
```ShellSession
$ travis lint
```

Коммит изменений
```ShellSession
$ git add .
$ git commit -m"added tests"
$ git push origin master
```

Вход в travis, активация проекта
```ShellSession
$ travis login --auto
$ travis enable
```

Screenshot
```ShellSession
$ mkdir artifacts
$ screencapture -T 20 artifacts/screenshot.jpg
<Command>-T
$ open https://github.com/${GITHUB_USERNAME}/lab06
```

## Report

```ShellSession
Создание отчета
$ cd ~/workspace/labs/
$ export LAB_NUMBER=06
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```
```
