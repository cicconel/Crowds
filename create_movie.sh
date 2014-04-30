 #!/bin/sh

 i=0
for nom_fichier in `\ls -1 screenshots/*.png`
do
    number=`printf "%08d" $i`
    mv $nom_fichier screenshots/shot-$number.png
    i=$(($i+1)) 
done


ffmpeg -r 25 -i screenshots/shot-%08d.png -r 50 -sameq video.avi
