--[[ While
a = 0

while(a<3)
do
    print(a)
    a = a + 1
end
]]
--[[ For
for i = 3,0,-1
do
    print(i)
end
]]
--[[ Repeat until
repeat
    print(a)
    a = a -1
until (a == 0)
]]

-- Nested
a = 0
b = 0
c = 0
for a = 0 , 3
do
    while(b < 3)
    do
        repeat  
            print("C(",a,",",b,",",c,")")       
            c = c + 1
        until(c > 2)
        print("B(",a,",",b,",",c,")")
        b = b + 1   
    end
    print("A(",a,",",b,",",c,")")
    a = a + 1
end