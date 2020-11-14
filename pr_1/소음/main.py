num1 = input()
oper = input()
num2 = input()
sum = 0
if oper == "*":
    sum = int(num1) * int(num2)
elif oper == "+":
    sum = int(num1) + int(num2)

print(sum)