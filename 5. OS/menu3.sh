i="y"
while [ $i == "y" ]
do
echo "1. Read the File"
echo "2. List of files and directories"
echo "3. Create a directory"
echo "4. Change Directory"
echo "5. rename the file"
echo "6. File size/ exist or not?"
echo "7. Delete the file"
echo "8. Delete the directory"
echo "Enter your choice: "
read ch
case $ch in
1)echo "Enter name of file to be Read: "
read fname
cat $fname;;
2)echo "List of files and directories are displayed"
ls;;
3)echo "Enter the name of the directory you want to create: "
read newdirname
mkdir $newdirname;;
4)echo "To change the directory: "
echo "Enter the dir name: "
read chgdirname
cd $chgdirname;;
5) echo "Enter existing file name: "
read existfname
echo "Enter new name: "
read renamename
mv $existfname $renamename;;

6)
echo "File exist or not"
echo "Enter the filename"
read filename
if [ -e $filename ]
then
echo $filename "File exists"
if [ -s $filename ]
then 
echo $filename "File has size > 0"
fi
else
echo "File doesnt exist"
fi;;

7)echo "Enter name of file to be deleted: "
read fname
rm $fname;;
8)echo "Enter name of file to be deleted: "
read fname
rmdir $fname;;
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