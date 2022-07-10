echo "Enter the number of elements: "
read len
for (( i = 0; i < len; i++ )); do
	echo "Enter element #$i: "
	read val
	arr[$i]=$val
done
echo "The elements of the array are: "
for (( i = 0; i < len; i++ )); do
	echo ${arr[$i]}
done