-- 1
-- require "printFormatter"
-- printFormatter.simpleFormat
-- 2
-- local formatter = require “printFormatter”
-- formatter.simpleFormat（“test”）
-- 3
-- require "printFormatter"\
-- local formatterFunction = printFormatter.simpleFormat
-- formatterFunction("test")

local mymath = {}

function mymath.add(a,b)
    print(a+b)
end

function mymath.sub(a,b)
    print(a-b)
end

function mymath.mul(a,b)
    print(a*b)
end

function mymath.div(a,b)
    print(a/b)
end

return mymath