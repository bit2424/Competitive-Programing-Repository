@echo off
g++ -std=c++17 -o a_generator.exe a_generator.cpp
g++ -std=c++17 -o a.exe a.cpp
g++ -std=c++17 -o a_brute.exe a_brute.cpp
for /l %%x in (1, 1, 100) do (
    a_generator > input.in
    a < input.in > output.out 
    a_brute < input.in > output2.out
    fc output.out output2.out > diagnostics || exit /b
    echo %%x
)
echo all a_generators passed
pause