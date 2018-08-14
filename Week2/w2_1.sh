echo "Please enter directory"
read directory
cd $directory
echo "The number of single extension files is:"
ls *.[a-z]|wc -l
