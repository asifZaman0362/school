echo "Enter the limit: "
read limit
first=0
second=1
echo "Fibonacci sequence: "
echo "$first"
while [[ $second -le $limit ]]; do
	echo "$second"
	temp=$second
	second=$(($first + $second))
	first=$temp
done