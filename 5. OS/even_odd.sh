echo "Enter Number: "
read a
if [ $a == 0 ]
then
	echo "It's zero."
elif [ `expr $a % 2` == 0 ]
then
	echo "It's even."
else
	echo "It's odd."
fi
	echo "End of script"