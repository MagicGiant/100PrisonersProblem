# Задача о 100 заключенных

## Условие

>Начальник тюрьмы предлагает ста узникам, приговорённым к смертной казни, последний шанс. Узники пронумерованы от 1 до 100, а комната содержит шкаф со 100 ящиками. Начальник случайным образом помещает в каждый ящик по одному из номеров от 1 до 100, во все ящики — разные номера. Узники по очереди входят в комнату. Каждый узник может открыть и проверить 50 ящиков в любом порядке. После каждого узника ящики снова закрываются, а все номера остаются в ящиках. Если каждый из узников найдёт в одном из ящиков свой номер, то все узники будут помилованы; если хотя бы один узник не найдёт свой номер, все узники будут казнены. Прежде чем первый узник войдёт в комнату, узники могут обсудить стратегию, но не могут общаться после этого момента. Какова лучшая для узников стратегия?
Подразумевается, что номера узников распределены по ящикам случайно и потому все перестановки номеров узников по ящикам равновероятны. Также подразумевается, что ящики пронумерованы от 1 до 100, либо об однозначности такой нумерации возможно договориться заранее.

[Симуляция на C++](/main.cpp)

## Итоги симуляции

При стандартном условии (100 коробок/заключенных и 50 попыток), симуляция выдала 0 при случайном выборе коробок и 0.31 при использовании специальной стратегии

Что интересно, используя более лояльные условия (100 коробок/заключенных и 99 попыток), шансы при случайном выборе коробок все ещё 0, но при использовании специального алгоритма, шансы повышаются до 0.98

Попытался выставить самые лояльные настройки: 10000 коробок/заключенных, 9999 попыток и 100 итераций. Это максимум, который может посчитать мой компьютер. Для случайного алгоритма все ещё 0, для специального алгоритма шансы повышаются до 100