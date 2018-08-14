echo "Enter file1"
read file1
cat > $file1
echo "Enter file2"
read file2
cat > $file2
cat < $file2 >> $file1
echo "In sorted file"
sort -g $file1|uniq > sorted.txt
cat sorted.txt
