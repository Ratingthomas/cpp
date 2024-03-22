g++ main.cpp options.cpp repeat.cpp -o main.a -std=c++20 -Wall -Wextra -pedantic &&
./main.a --color=red --repeat=1 --color=red -nC "test"
