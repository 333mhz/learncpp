function add(arg1, arg2)
    --assert(type(arg1) == "number","a must be a number")
    --assert(type(arg2) == "number","b must be a number")
    return arg1+arg2
end

if pcall(add,1,2)
then
    print("Success")
else
    print("Failure")
end

status, err = pcall(add)
print(status)
print(err)

function errHandler(err)
    print("Error:", err)
end

status = xpcall(add,errHandler)
print(status)