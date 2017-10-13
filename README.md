[![Build Status](https://travis-ci.org/Polly-99/lab06.svg?branch=master)](https://travis-ci.org/Polly-99/lab06)
## Laboratory work V

Данная лабораторная работа посвещена изучению систем непрерывной интеграции на примере сервиса **Travis CI**

```ShellSession
$ open https://travis-ci.org
```

## Tasks

- [x] 1. Авторизоваться на сервисе **Travis CI** с использованием **GitHub** аккаунта
- [x] 2. Создать публичный репозиторий с названием **lab06** на сервисе **GitHub**
- [x] 3. Ознакомиться со ссылками учебного материала
- [x] 4. Включить интеграцию сервиса **Travis CI** с созданным репозиторием
- [x] 5. Получить токен для **Travis CLI** с правами **repo** и **user**
- [x] 6. Получить фрагмент вставки значка сервиса **Travis CI** в формате **Markdown**
- [x] 7. Установить [**Travis CLI**](https://github.com/travis-ci/travis.rb#installation)
- [x] 8. Выполнить инструкцию учебного материала
- [x] 9. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GITHUB_TOKEN=<полученный_токен>
```
Создание директории новой лабы на основе предыдущей
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab04 lab06
$ cd lab06
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab06
```
Редактирование travis.yml
```ShellSession
$ cat > .travis.yml <<EOF
language: cpp
EOF
```

```ShellSession
$ cat >> .travis.yml <<EOF

script:
- cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
- cmake --build _build
- cmake --build _build --target install
EOF
```

```ShellSession
$ cat >> .travis.yml <<EOF

addons:
  apt:
    sources:
      - george-edison55-precise-backports
    packages:
      - cmake
      - cmake-data
EOF
```
Записывание токена
```ShellSession
$ travis login --github-token ${GITHUB_TOKEN}
```

Проверка работоспособности .travis.yml
```ShellSession
$ travis lint
```
Вставка значка в файл отчета
```ShellSession
$ ex -sc '1i|<фрагмент_вставки_значка>' -cx README.md
```
Коммит изменений
```ShellSession
$ git add .travis.yml
$ git add README.md
$ git commit -m"added CI"
$ git push origin master
```

Комманды trevis
```ShellSession
$ travis lint
Warnings for .travis.yml:
[x] value for addons section is empty, dropping
[x] in addons section: unexpected key apt, dropping

$ travis accounts #вывод аккаунтов и их статусов
Polly-99 (Polly-99): subscribed, 7 repositories

$ travis sync #синхронизация
synchronizing: . done

$ travis repos  #вывод репозиториев и их активности
Polly-99/Game (active: no, admin: yes, push: yes, pull: yes)
Description: ???

Polly-99/Semestr_2 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

Polly-99/Semestr_3 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

Polly-99/TMP (active: no, admin: yes, push: yes, pull: yes)
Description: ???

Polly-99/lab03 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

Polly-99/lab04 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

Polly-99/lab06 (active: yes, admin: yes, push: yes, pull: yes)
Description: ???

$ travis enable #активация проекта
Detected repository as Polly-99/lab06, is this correct? |yes| yes
Polly-99/lab06: enabled :)

$ travis whatsup  #вывод последних действий с файлами
Polly-99/lab06 passed: #1

$ travis branches #вывод веток
master:  #1    passed   added CI

$ travis history #вывод истории
#1 passed:    master added CI  

$ travis show #вывод информации о сборках
Job #1.1:   added CI
State:         passed
Type:          push
Branch:        master
Compare URL:   https://github.com/Polly-99/lab06/compare/5f092b62ae7b^...830a918fce22
Duration:      31 sec
Started:       2017-10-07 21:51:44
Finished:      2017-10-07 21:52:15
Allow Failure: false
Config:        os: linux
```

## Report

Создание отчета
```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=05
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
