-- Comm
string1 = "Hello "
print(string1)

string2 = "Lua!"
print(string2)

-- String.Upper&lower
print(string.upper(string1))
print(string.lower(string2))

--Find & Reverse
print(string.find(string1,"ll"))
string3 = string.reverse(string1)
print(string3)

-- Format
number1 = 10
number2 = 20

string4 = string.format("Basic Format: %d %d",number1,number2)
print(string4)

year = 2019; month = 11; day = 6
print(string.format("Today is %04d/%02d/%02d",year,month,day))

print(string.format("%.3f",1/3))

-- Byte Char Conversion
print(string.byte(string2))
print(string.byte(string2,4))
print(string.byte(string2,-1))

print(string.char(97))

-- Other
print(string1..string2)
print(string.len(string1))
print(string.rep(string2,3))
