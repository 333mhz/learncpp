-- table init
mytable = {}
print(type(mytable)) -->table
-- value assign
mytable[1]="test"
mytable["wtf"] = "meow???"
print("mytable[1]:", mytable[1])
print("mytable[wtf]:", mytable["wtf"] )
-- table refer
extable = mytable
print("extable[1]:", extable[1])
print("extable[wtf]:", extable["wtf"] )

extable["wtf"] = "woam!"
print("mytable[wtf]:", mytable["wtf"] )
-- release
mytable = nil
-- extable still refer the content
extable = nil
-- lua gc will take content away if there's no table refer.

-- Concatenate
fruits = {"banana","orange","apple"}
print(table.concat(fruits))
print(table.concat(fruits,","))
print(table.concat(fruits,",",1,3))
print(table.concat(fruits,",",1,2))
print(table.concat(fruits,",",2,3))

-- Insert
table.insert(fruits,"mango")
print(fruits[4])
table.insert(fruits,2,"grapes")
print(fruits[2],#fruits)

table.remove(fruits,1)
print(fruits[1])

for i,e in ipairs(fruits) do
    print(string.format("(%d,%s)",i,e))
end

table.sort(fruits)
for i,e in ipairs(fruits) do
    print(string.format("(%d,%s)",i,e))
end

