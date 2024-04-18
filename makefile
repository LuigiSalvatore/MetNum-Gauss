_APP = a
_MAIN_NAME = main
_DASH_O = main.o read.o 
_CFLAGS = -c -std=c++11 #-DDEBUG

all: $(_APP)

$(_APP): $(_DASH_O)
    g++ -o $(_APP).exe $(_DASH_O)

main.o:		main.cpp read.cpp
    g++ ${_CFLAGS} main.cpp

read.o: read.cpp read.h #probStruct.h
    g++ ${_CFLAGS} read.cpp

probStruct.o: probStruct.cpp probStruct.h
    g++ ${_CFLAGS} probStruct.cpp

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

test: a
    g++ -o a gauss.cpp
    ./a.exe
clean: 			
    rm -f ${_DASHOES} ${_APP}