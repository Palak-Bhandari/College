DAY=$(date +%F)

for FILE in *.png
    do
        mv $FILE ${DAY}-${FILE}
    done