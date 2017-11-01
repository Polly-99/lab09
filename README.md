## Laboratory work IX

Данная лабораторная работа посвещена изучению процесса создания пакета на примере **Github Release**

```ShellSession
$ open https://help.github.com/articles/creating-releases/
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab09** на сервисе **GitHub**
- [x] 2. Ознакомиться со ссылками учебного материала
- [x] 3. Получить токен для доступа к репозиториям сервиса **GitHub**
- [x] 4. Сгенерировать GPG ключ и добавить его к аккаунту сервиса **GitHub**
- [x] 5. Выполнить инструкцию учебного материала
- [x] 6. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_TOKEN=<полученный_токен>
$ export GITHUB_USERNAME=<имя_пользователя>
$ alias gsed=sed # for *-nix system
```
Установка github-release
```ShellSession
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
$ go get github.com/aktau/github-release
```
Создание директории новой лабы на основе предыдущей
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab08 projects/lab09
$ cd projects/lab09
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab09
```
Замена "lab07" на "lab08" в файле README.md
```ShellSession
$ gsed -i 's/lab08/lab09/g' README.md
```
Архивация
```ShellSession
$ cmake -H. -B_build -DCPACK_GENERATOR="TGZ"
$ cmake --build _build --target package
```
Активация проекта в travis
```ShellSession
$ travis login --auto
$ travis enable
```
Создание метки
```ShellSession
$ git tag -s v0.1.0.0 # создание метки
$ git tag -v v0.1.0.0 # проверка метки
$ git push origin master --tags 
```
Добавление релиза
```ShellSession
$ github-release --version # вывод версии 
github-release v0.7.2
$ github-release info -u ${GITHUB_USERNAME} -r lab09 #информация о релизах
tags:
- v0.1.0.0 (commit: https://api.github.com/repos/Polly-99/lab09/commits/12371e9d07e5d569b3223d77b8b71e90a79c1496)
releases:
$ github-release release \  #создание нового релиза
    --user ${GITHUB_USERNAME} \
    --repo lab09 \
    --tag v0.1.0.0 \
    --name "libprint" \
    --description "my first release"
```
Загрузка релиза
```ShellSession
$ export PACKAGE_OS=`uname -s` PACKAGE_ARCH=`uname -m` #переменная окружения - операционная система
$ export PACKAGE_FILENAME=print-${PACKAGE_OS}-${PACKAGE_ARCH}.tar.gz #переменная окружения - имя пакета
$ github-release upload \ #загрузка релиза
    --user ${GITHUB_USERNAME} \
    --repo lab09 \
    --tag v0.1.0.0 \
    --name "${PACKAGE_FILENAME}" \
    --file _build/*.tar.gz
```

```ShellSession
$ github-release info -u ${GITHUB_USERNAME} -r lab09 #информация о релизах
tags:
- v0.1.0.0 (commit: https://api.github.com/repos/Polly-99/lab09/commits/12371e9d07e5d569b3223d77b8b71e90a79c1496)
releases:
- v0.1.0.0, name: 'libprint', description: 'my first release', id: 8346712, tagged: 01/11/2017 at 17:58, published: 01/11/2017 at 18:00, draft: ✗, prerelease: ✗
  - artifact: print-Linux-x86_64.tar.gz, downloads: 0, state: uploaded, type: application/octet-stream, size: 2.8 kB, id: 5222058
$ wget https://github.com/${GITHUB_USERNAME}/lab09/releases/download/v0.1.0.0/${PACKAGE_FILENAME}
$ tar -ztf ${PACKAGE_FILENAME}
```print-0.1.0.0-Linux/cmake/
print-0.1.0.0-Linux/cmake/print-config-noconfig.cmake
print-0.1.0.0-Linux/cmake/print-config.cmake
print-0.1.0.0-Linux/lib/
print-0.1.0.0-Linux/lib/libprint.a
print-0.1.0.0-Linux/include/
print-0.1.0.0-Linux/include/print.hpp

## Report
Создание отчета
```ShellSession
$ popd
$ export LAB_NUMBER=09
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```
