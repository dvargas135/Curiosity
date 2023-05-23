@echo off
setlocal

rem Set the root directory to the current script's directory
set "root=%~dp0"

rem Call the subroutine to process files
call :ProcessFolder "%root%"

rem End of the script
exit /b

:ProcessFolder
rem Loop through each file in the specified folder
for /r "%~1" %%F in (*.cxx) do (
  rem Retrieve the relative path of the file
  set "relativePath=%%~pnxF"
  
  rem Remove the leading backslash if present
  if "!relativePath:~0,1!"=="\" set "relativePath=!relativePath:~1!"
  
  rem Print the relative path
  echo !relativePath!
)

rem Recursively call the subroutine for each subfolder
for /d %%D in ("%~1\*") do (
  call :ProcessFolder "%%D"
)

exit /b
