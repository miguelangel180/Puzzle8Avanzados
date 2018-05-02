
clear
current_date_time="`date +%Y/%m/%d---%H:%M:%S`";
echo Fecha y hora de comienzo: $current_date_time
echo compilando programa...
make
echo ejecutando programa....
./puzzle8
current_date_time="`date +%Y/%m/%d---%H:%M:%S`";
echo Fecha y hora de termino:  $current_date_time
