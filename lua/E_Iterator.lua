-- Stateless
function square(iteratorMax,currentNum)
    if(currentNum < iteratorMax)
    then
        currentNum = currentNum + 1
        return currentNum, currentNum^2
    end
end

function squares(iteratorMax)
    return square,iteratorMax,0
end

for i,n in squares(3)
do
    print(string.format("(%d,%d)",i,n))
end

-- Stateful
arr = {"Hello ", "lua!"}

function elementIter(colle)
    local i = 0
    return functluaion()
        -- Closure
        i = i + 1
        if i <= #colle
        then
            return colle[i]
        end
    end
end

for element in elementIter(arr)
do
    print(element)
end
