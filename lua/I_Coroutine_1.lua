myco = coroutine.create(function(val1,val2)
    local tmp_val3 = 10
    print("Coroutine section 1",val1,val2,tmp_val3)

    local tmp_val1 = coroutine.yield(val1+1,val2+1)
    tmp_val3 = tmp_val3 + val1
    print("Coroutine section 2",tmp_val1,tmp_val2,tmp_val3)

    local tmp_val1,tmp_val2 = coroutine.yield(val1+val2,val1-val2)
    tmp_val3 = tmp_val3 + val1
    print("Coroutine section 3",tmp_val1,tmp_val2,tmp_val3)
    return val2,"end"

end)

print("main",coroutine.resume(myco,3,2))
print("main",coroutine.resume(myco,12,14))
print("main",coroutine.resume(myco,5,6))
print("main",coroutine.resume(myco,10,20))