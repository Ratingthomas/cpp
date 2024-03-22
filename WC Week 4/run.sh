clear
g++ *.cpp -Wall -Wextra -Wno-conversion -pedantic -std=c++20 -o main.a
#./main.a -cmw -l -L
./main.a -cmw -l -L --help --version anna_karenina.txt count_monte.txt
