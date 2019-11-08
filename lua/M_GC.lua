mytable = {"apple","banana","casher"}

print(collectgarbage("count"))

mytable = nil

print(collectgarbage("count"))
print(collectgarbage("collect"))
print(collectgarbage("count"))