call ..\..\..\dosrun.bat

cd led
call build.bat %1
cd ..

cd ledprd
call build.bat %1
cd ..

cd tone
call build.bat %1
cd ..

cd post
call build.bat %1
cd ..

cd dsk_app
call build.bat %1
cd ..
