clear
echo "Enter the file name: "
read filenm
if [ -e $filenm ]
then
    echo $filenm "file exist"
    if [ -s $filenm ]
    then
        echo $filenm" File has size > 0"
        rm $filenm
        echo $filenm" File is deleted which has size = 0"
    fi
else
    echo "File no exist"
fi