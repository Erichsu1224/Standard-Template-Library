@echo off

cls

g++ -o $1 $1.cpp

if %ERRORLEVEL% EQU 0 (
	for i in (1000 5000 10000 50000 100000 500000) do (
		for j in (100 500 1000) do (
			
		)
	)
)