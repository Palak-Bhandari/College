i="y"
while [ $i == "y" ]
do
echo "1. List of files and directories"
echo "2. Create a directory"
echo "3. Change Directory"
echo "4. rename the file"
echo "Enter your choice: "
read ch
case $ch in
1)echo "List of files and directories are displayed"
ls;;
2)echo "Enter the name of the directory you want to create: "
read newdirname
mkdir $newdirname;;
3)echo "To change the directory: "
echo "Enter the dir name: "
read chgdirname
cd $chgdirname;;
4) echo "Enter existing file name: "
read existfname
echo "Enter new name: "
read renamename
mv $existfname $renamename;;
*)
echo "Invalid Choice";;
esac
echo "Do you want to continue"
read i
if [ $i != "y" ]
then
exit
fi
done