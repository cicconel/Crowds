 #!/bin/sh

 i=0
for nom_fichier in `\ls -1 screenshots/*.png`
do
    number=`printf "%04d" $i`
    mv $nom_fichier screenshots/shot-$number.png
    i=$(($i+1)) 
done


ffmpeg -r 10 -i screenshots/shot-%04d.png -r 10 -sameq video.avi
