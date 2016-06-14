cls
rem @echo off
SET program="%1"
if %program% == "" goto err

%program% test/input1.txt test/input2.txt > test/output1.txt
if ERRORLEVEL 1 goto testFailed
fc /b test\output1.txt test\reference\output1.txt
if ERRORLEVEL 1 goto testFailed  

%program% test/inputEmpty.txt test/input2.txt > test/outputWhitEmptyFile.txt
if ERRORLEVEL 1 goto testFailed
fc /b test\outputWhitEmptyFile.txt test\reference\outputWhitEmptyFile.txt
if ERRORLEVEL 1 goto testFailed  

%program% test/input2Copy.txt test/input2.txt > test/outputSameFile.txt
if ERRORLEVEL 1 goto testFailed
fc /b test\outputSameFile.txt test\reference\outputSameFile.txt
if ERRORLEVEL 1 goto testFailed  

%program% test/inputNegativScale.txt test/inputNegativSize.txt > test/outputNegativData.txt
if ERRORLEVEL 1 goto testFailed
fc /b test\outputNegativData.txt test\reference\outputNegativData.txt
if ERRORLEVEL 1 goto testFailed  

%program% test/inputIncorrect.txt test/inputNegativSize.txt > test/outputIncorrect.txt
if ERRORLEVEL 1 goto testFailed
fc /b test\outputIncorrect.txt test\reference\outputIncorrect.txt
if ERRORLEVEL 1 goto testFailed  


echo OK
exit /b

:testFailed
echo Testing failed
exit /b

:err
echo Usage: test.bat <Path to program>
