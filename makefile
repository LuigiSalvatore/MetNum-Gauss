_APP = a
_MAIN_NAME = main
_DASH_O = main.o read.o logicaMat.o
_CFLAGS = -c -std=c++11 #-DDEBUG

all: $(_APP)

$(_APP): $(_DASH_O)
    g++ -o $(_APP).exe $(_DASH_O)

main.o:		main.cpp logicamat.h
    g++ ${_CFLAGS} main.cpp

logicaMat.o: logicaMat.cpp logicaMat.h read.h
    g++ ${_CFLAGS} logicaMat.cpp

read.o: read.cpp read.h
    g++ ${_CFLAGS} read.cpp


run1: $(_APP)
    ./$(_APP).exe ./Casos/caso1.txt

run2: $(_APP)
    ./$(_APP).exe ./Casos/caso2.txt

run3: $(_APP)
    ./$(_APP).exe ./Casos/caso3.txt

run4: $(_APP)
    ./$(_APP).exe ./Casos/caso4.txt

run5: $(_APP)
    ./$(_APP).exe ./Casos/caso5.txt

run6: $(_APP)
    ./$(_APP).exe ./Casos/caso6.txt

run7: $(_APP)
    ./$(_APP).exe ./Casos/caso7.txt

run8: $(_APP)
    ./$(_APP).exe ./Casos/caso8.txt

run9: $(_APP)
    ./$(_APP).exe ./Casos/caso9.txt

run10: $(_APP)
    ./$(_APP).exe ./Casos/caso10.txt

test: $(_APP)
    $(_APP).exe ./Casos/caso1.txt > ./Outs/caso1.out
    $(_APP).exe ./Casos/caso2.txt > ./Outs/caso2.out
    $(_APP).exe ./Casos/caso3.txt > ./Outs/caso3.out
    $(_APP).exe ./Casos/caso4.txt > ./Outs/caso4.out
    $(_APP).exe ./Casos/caso5.txt > ./Outs/caso5.out
    $(_APP).exe ./Casos/caso6.txt > ./Outs/caso6.out
    $(_APP).exe ./Casos/caso7.txt > ./Outs/caso7.out
    $(_APP).exe ./Casos/caso8.txt > ./Outs/caso8.out
    $(_APP).exe ./Casos/caso9.txt > ./Outs/caso9.out
    $(_APP).exe ./Casos/caso10.txt > ./Outs/caso10.out

clean: 			
    rm -f ${_DASHOES} ${_APP}