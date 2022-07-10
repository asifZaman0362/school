echo "Enter a string: "
read string
reverse=""
for ((i=${#string}-1; i>=0; i--)); do 
	reverse=$reverse"${string:$i:1}"
done
if [[ "$string" = "$reverse" ]]; then
	echo "$string is pallindrome"
else
	echo "$string is not pallindrome"
fi