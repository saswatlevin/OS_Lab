echo "Enter directory"
read directory
cd $directory
echo "Enter the operation"
read operation
echo "Enter the format"
read format
echo "The result of the operation is:"
$operation $format
