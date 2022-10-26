#!/bin/bash
rm -rf ${pwd}newDir
NAME="abc"
echo "${NAME} printed"
mkdir -p ${pwd}newDir
touch ${pwd}newDir/newFile1.txt
touch ${pwd}newDir/newFile2.txt
echo "abcdgedgehgdhseg">>${pwd}newDir/newFile2.txt     
echo "lorem 0chfukjdchyijkugdfhikugydfsiugyfiudhyguiyiuy">>${pwd}newDir/newFile1.txt     
cat ${pwd}newDir/newFile2.txt  
cat ${pwd}newDir/newFile1.txt  
mkdir -p ${pwd}newDir/newDir2
mkdir -p ${pwd}newDir/newDir2/newDir4
mkdir -p ${pwd}newDir/newDir3
echo "newDir/newDir3/newFile3.txt  new text">>${pwd}newDir/newDir3/newFile3.txt     
echo "newDir fhdsfghg ghjgjshdgf dsfhjgsdjhfg  new text">>${pwd}newDir/newDir2/newDir4/newFile4.txt     
cat ${pwd}newDir/newDir3/newFile3.txt
cat ${pwd}newDir/newDir2/newDir4/newFile4.txt
ln ${pwd}newDir/newDir2/newDir4/newFile4.txt ${pwd}newDir/newDir2/newDir4/hardlinkfile.txt


# rm -rf ${pwd}newDir