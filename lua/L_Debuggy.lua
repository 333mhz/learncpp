--[[
function debuggy()
    print(debug.traceback("Stack trace"))
    print(debug.getinfo(1))
    print("Stack Trace End")

    return 17
end

debuggy()
print(debug.getinfo(1))
]]

-->example

function buggy()
    local a = 0
    local b = 0

    return function ()
        b = a
        a = a+1
        return b
    end
    
end

buggysample = buggy()

print(buggysample())
print(buggysample())

local i = 1

repeat
    name, val = debug.getupvalue(buggysample,i)

    if name
    then
        print("index:",i,name,"=",val)
        if(name == "n")
        then
            debug.setupvalue(buggysample,3,10)
        end

        i = i + 1
    end -- if
until not name

print(buggysample())