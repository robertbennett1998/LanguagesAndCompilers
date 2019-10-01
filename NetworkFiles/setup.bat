: # This is a special script which intermixes both sh
: # and cmd code. It is written this way because it is
: # used in system() shell-outs directly in otherwise
: # portable code. See http://stackoverflow.com/questions/17510688
: # for details.
: #
: # This is particularly interesting for Languages and compilers as the script
: # is an example of a program that is syntactically correct in two languages!
: #
:<<"::ENDOFWINDOWS"
@echo off
REM Batch file to map the T: drive for quick testing
REM Brian Tompsett Feb 2013
::
:: History:
::    Ver 1 : Feb 2013
::    Ver 2 : Apr 2013 Added interactive version
::            Sep 2013 08238 version
:: ``````````````````````````````````````````````````````````````````
:: We can check how the script was called %cmdcmdline% can be the null string 
:: or sometime "C: (unpaired quote!)
:: or the string  cmd /c ""T:\lab1test.bat" "
:: We have to discover which
:: There is magic space at the end of the following line to remove a null string
set invoker=%cmdcmdline% 
:: Now remove any troublesome quotes
REM %invoker%
set invoker=%invoker:"=`%
REM %invoker%
:: See if drive T: is mapped to anything
setlocal enabledelayedexpansion
set mapping=
for /f skip^=1^ tokens^=*^ delims^=^ eol^= %%s in ('wmic logicaldisk T: get description 2^>nul') do set mapping=!mapping!%%s
IF "%mapping%." == "." GOTO :GoSubst
:: Now the T: drive might already be a subst. Check
:: set to a blank
set aliased= 
:: Check if alias exists - delete if it does, so new one replaces old
for /f "tokens=2 delims==" %%i in ('subst ^| find "T:" ') do set aliased=%%i
if "%aliased:~2%" == "" GOTO :NoAlias
echo Deleting old mapping of T: to %aliased:~2%
SUBST T: /D
:NoAlias
:: Was not a subst, must be a map
IF "%mapping%." == "." GOTO :GoSubst
:: Ask the user
:AskAgain
set /p Answer=Drive T: mapping %mapping% needs to be deleted. OK to proceed? [y/n] 
if /i "%Answer%" == "y" GOTO :UnMap
if /i "%Answer%" == "n" exit /b
GOTO :AskAgain
:UnMap
net use t: /delete
:GoSubst
:: Do the Subst
::   Find containing folder
SET myhome=%~dp0
:: Chop off trailing backslash in subst
SUBST T: "%myhome:~0,-1%"
:: Now check that we are in the University 
:: - I do not want to support copies of this code as it makes 
:: a maintenance and configuration management problem - bugs propagate and
:: do not get fixed.
:: Please use the university VPN to map the drive properly
Echo "Script Directory: %~dp0"
:: Call net use and strip out the desired line and select the third field!
for /f "tokens=3 delims= " %%i in ('net use U: ^| find "Remote name" ') do set netdrive=%%i
Echo "Shared drive is ``U:%netdrive: =%``"
if /I NOT "%netdrive: =%" == "\\data.adir.hull.ac.uk\studentshare" GOTO :BadLocation
if NOT exist "U:\Computer Science\600087\Lab\" GOTO :BadLocation
If /I "%~dp0" == "U:\Computer Science\600087\Lab\" GOTO :AtUni
if /I NOT "%~dp0" == "T:\" GOTO :WrongDrive
:: set to a blank
set aliased= 
for /f "tokens=2 delims==" %%i in ('subst ^| find "T:" ') do set aliased=%%i
if /I "%aliased:~2%" == "U:\Computer Science\600087\Lab" GOTO :AtUni
:BadLocation
  (echo Script not running from correct directory: %netdrive% :: %~dp0) 1>&2
  (echo If you are using your own PC,) 1>&2                                
  (echo Please use the university VPN to map the drive U:) 1>&2        
  pause      
GOTO :End
:WrongDrive
  (echo Script not running from correct directory: %netdrive% :: %~dp0) 1>&2
  (echo You cannot make copies of the test scripts as they are updated) 1>&2
GOTO :End
:AtUni
:: ---------------------------------------
:: Add extra checks for missing software components to fix the path
:: Due to fault software installation at university 2017
set theValue=
for /f "delims=" %%a in ('where gcc 2^>nul') do @set theValue=%%a 
if NOT "%theValue%."=="." GOTO :TestBison
echo Warning GCC not installed
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvars32.bat"
DOSKEY gcc=cl $* /link "T:\GnuWin32\lib\libfl.a"
set NoGCC=Yes
:TestBison
set theValue=
for /f "delims=" %%a in ('where bison 2^>nul') do @set theValue=%%a 
if NOT "%theValue%."=="." GOTO :HasBison
set PATH=C:\Gnuwin32\Bison\bin;C:\Gnuwin32\Flex\bin;%PATH%
:OffPath
%COMSPEC%
GOTO :DOSLaunch
:HasBison
IF "%NoGCC%" == "YES" GOTO :OffPath
:OnPath
:: Here we must quote the line as it might contain meta characters
IF /I "%invoker:~0,3%" == "cmd" GOTO :Clicked
:: For some reason, sometime the full path is used - and the case varies
IF /I "%invoker:~0,27%" == "C:\WINDOWS\system32\cmd.exe" GOTO :Clicked
GOTO :DOSLaunch
:Clicked
@color 4e
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo The drive alias T: has been created to run the tests more easily.
echo You can access the tests as t:a.SPL and t:Makefile etc
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
subst
pause
:DOSLaunch
Subst
EXIT /b
echo MELON, MELON - Out of cheese Error - Please Reboot Universe!
::ENDOFWINDOWS
# Bash script file to map the T variable to the current directory for quick testing
# As this modifies the environemnt it must be executed by using the '. setup.at' method
#
# Brian Tompsett Dec 204
#
# History:
#    Ver 1 : Dec 2014 Cloned from windows version
#
# First find the directory with the test scripts and test programs
#  They could be mounted in a OS/X or cygwin format
#
# http://stackoverflow.com/questions/59895/can-a-bash-script-tell-what-directory-its-stored-in
#
# The file is used for both bash and windows and has windows line breaks of \r\n
# Each line ends in a comments to protect the \r character which bash does not like
# Some of the lines are very long because we can't have \r in continuations in bash
#
SOURCE="${BASH_SOURCE[0]}" #
while [ -h "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
  DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )" #
  SOURCE="$(readlink "$SOURCE")" #
  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
done #
T="$( cd -P "$( dirname "$SOURCE" )" && pwd )" #
echo Variable T set to $T
export T #
 #
