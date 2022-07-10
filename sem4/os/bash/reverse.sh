echo "Enter a string: "
read string
reverse=""
for ((i=${#string}-1; i>=0; i--)); do 
	reverse=$reverse"${string:$i:1}"
done
echo "Reverse of $string is $reverse"