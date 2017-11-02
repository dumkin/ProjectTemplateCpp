#!/bin/sh

mkdir -p build
cd build

rm -rf *
cmake ../sources/

OUT_INFO=$(cat <<'EOTEXT'
-- Приложение: Завершение
Статус код: %x.
Приложение работало %e секунд.
Максимальный размер используемой памяти: %M килобайт.
Загруженность центрального процессора %P.

Приложение было выгружено из памяти %W раз.
Процесс был переключён %c раз, потому что истек промежуток времени.
Процесс был переключён %w раз, на добровольной основе.
Чтение из файловой системы %I раз.
Запись в файловую систему %O раз.
Получено %r сокет сообщений.
Отправлено %s сокет сообщений.
В процесс передано %k сигналов.
EOTEXT
)

while true
do
	clear
	echo -n "-- Применение стилей: "
	find ../sources/ -name '*.hpp' -or -name '*.cpp' | xargs clang-format-5.0 -i -style=file $1
	echo "Готово"

	echo -n "-- Копирование файлов: "
	cp ../sources/Main.lua Main.lua
	echo "Готово"

	echo "-- Компиляция: Запуск"
	make
	echo "-- Компиляция: Завершение"

	echo "-- Приложение: Запуск"
	/usr/bin/time -f "$OUT_INFO" ./App

	read operation

	if [ $operation ] && [ $operation = "cmake" ]
	then
		clear
		rm -rf *
		cmake ../sources/
	fi

	if [ $operation ] && [ $operation = "debug" ]
	then
		gdbgui App
	fi
done
