#!/usr/bin/python3
import sys
from calculator_1 import add, sub, mul, div

if len(sys.argv) != 4:
    print("Usage: ./100-my_calculator.py <a> <operator> <b>")
    sys.exit(1)

a, operator, b = map(int, sys.argv[1:4])

if operator == '+':
    result = add(a, b)
elif operator == '-':
    result = sub(a, b)
elif operator == '*':
    result = mul(a, b)
elif operator == '/':
    result = div(a, b)
else:
    print("Unknown operator. Available operators: +, -, * and /")
    sys.exit(1)

print("{:d} {:s} {:d} = {:d}".format(a, operator, b, result))
