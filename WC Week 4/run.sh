clear
g++ *.cpp -Wall -Wextra -Wno-conversion -pedantic -std=c++20 -o main.a
#./main.a -cmw -l -L test.txt
#./main.a -lmL hello.txt world.md --verbose
./main.a -cmw -l -L --verbose anna_karenina.txt count_monte.txt test.txt