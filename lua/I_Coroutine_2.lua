function getNum()
    local function getNumHelper()
        co = coroutine.create(function ()
            coroutine.yield(1)
            coroutine.yield(2)
            coroutine.yield(3)
            coroutine.yield(4)
            coroutine.yield(5)
            return coroutine.status() --!!!
        end)
        return co
    end

    if(numHelper)
    then
        stat, num = coroutine.resume(numHelper);

        if not(stat)
        --if coroutine.status(numHelper) == "dead"
        then
            numHelper = getNumHelper()
            stat,num = coroutine.resume(numHelper);
        end

        return stat,num
    else
        numHelper = getNumHelper()
        stat,num = coroutine.resume(numHelper);
        return stat,num
    end
end

for i = 1, 10 do
    print(i,getNum())
end