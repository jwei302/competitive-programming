"""
ID: jeffrey88
LANG: PYTHON3
PROG: ride
"""
f = open('ride.in', 'r')
w = open('ride.out', 'w')

data = (f.read()).split('\n')
num1 = list(data[0])
num2 = list(data[1])

product1 = 1
product2 = 1
let_num = {'A':1, 'B':2, 'C':3, 'D':4, 'E':5, 'F':6, 'G':7, 'H':8, 'I':9, 'J':10, 'K':11, 'L':12, 'M':13, 'N':14, 'O':15, 'P':16, 'Q':17, 'R':18, 'S': 19, 'T':20, 'U':21, 'V':22, 'W':23, 'X':24, 'Y': 25, 'Z':26}
for item in num1:
    product1 *= let_num[item]

for item in num2:
    product2 *= let_num[item]

if product1 % 47 == product2 % 47:
  w.write('GO\n')
else:
  w.write('STAY\n')
