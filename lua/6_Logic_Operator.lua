a = 30
b = 0

if(a and b)
then
    print("a and b: ",(a and b))
end

if(a or b)
then
    print("a or b: ",(a or b))
end

a = 10
b = 0  -- WTF???

if(not(a and b))
then
    print(a and b,"1not(a and b): ",not(a and b))
else
    print(a and b,"0not(a and b): ",not(a and b))
end

if(not(a or b))
then
    print(a or b,"1not(a or b): ",not(a or b))
else
    print(a or b,"0not(a or b): ",not(a or b))
end

a = false
b = true

if(not(a and b))
then
    print("1not(a and b): ",not(a and b))
else
    print("0not(a and b): ",not(a and b))
end

if(not(a or b))
then
    print("1not(a or b): ",not(a or b))
else
    print("0not(a or b): ",not(a or b))
end