-- _index
-- mytable = setmetatable({key1 = "val1"},{
--     __index = function(mytable,key)
--     if key == "key2"
--     then
--         return "metatableval"
--     else
--         return mytable[key]
--     end
--     end
-- })
-- mytable = setmetatable({key1 = "val1"},{
--     __index = { key2 = "metatableval"}
-- })
-- print(mytable.key1,mytable.key2)

-- mymetatable = {}
-- mytable = setmetatable({key1 = "val1"},{__newindex = mymetatable})

-- print(mytable.key1)

-- mytable.newkey = "new val2"
-- print(mytable.newkey,mymetatable.newkey)


-- mytable.key1 = "new val1"
-- print(mytable.key1,mymetatable.key1)

-- mytable = setmetatable({1,2,3},{
--     __add = function(mytable,newtable)
--         for i = 1,#(newtable)do
--             table.insert(mytable,#(mytable)+1,newtable[i])
--             --return mytable
--         end
--         return mytable
--     end
-- })

-- sectable = {4,5,6}
-- mytable = mytable + sectable
-- for i,n in ipairs(mytable)do
--     print(i,n)
-- end

-- mytable = setmetatable({10},{
--     __call = function(mytable,newtable)
--     sum = 0
--         for i = 1, #(mytable)do
--             sum = sum +mytable[1]
--         end

--         for i = 1, #(newtable)do
--             sum = sum + newtable[i]
--         end
--         return sum
--     end
-- })

mt1 = {1,2,3}
local mf = {}
mt2 = {2,2,3}
mf.__tostring = function (mf)
    sum = 0
    for i,n in pairs(mf)do
        sum = sum + n
    end
    return "Sum: "..sum
end

setmetatable(mt1,mf)
print(mt1)

