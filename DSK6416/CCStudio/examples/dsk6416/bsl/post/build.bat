echo off
rem This file will rebuild the post example.
rem This script can be run stand-alone if you initialize the 'TIROOT', 'TCONF'
rem and TIMAKE variables.
echo on

set TIROOT=%TI_DIR%
set TCONF=%TIROOT%\bin\utilities\tconf\tconf
set TIMAKE=%TIROOT%\cc\bin\timake

%TCONF% build-post.tcf
%TIMAKE% post.pjt Debug %1

rem Cleanup
erase cc_build_Debug.log
erase Debug.lkf
erase *.paf
erase Debug\*.obj
