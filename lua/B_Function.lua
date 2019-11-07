-- Def
function example(arg1, arg2, arg3)
    --statement
    return arg1;
end

--Call
example(1,2,3)

--Assign
myexample = function (arg1)
    print("My example function: ",arg1)
    return arg1;
end

function test(val1,val2,functionP)
    result = val1 + val2
    functionP(result)
end

myexample("test01")
test(1,2,myexample)

-- Varible argument
function average(...)
    result = 0
    local arg = {...}
    for i,v in ipairs(arg)
    do
        result = result + v
    end
    return result/#arg
end
