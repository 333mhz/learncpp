-- r read-only-existed
-- w write-overwrite or create-new-write
-- a append-existed or create-new-append
-- r+ read-wirte-existed
-- w+ remove-existed-wirte or create-new-write 
-- a+ append-read-exited or create-new

-- Implicit mode

-- samplefile = io.open("sample.lua","r")
-- io.input(samplefile)
-- print(io.read())
-- io.close(samplefile)

-- samplefile = io.open("sample.lua","a")
-- io.output(samplefile)
-- io.write(" -- End of the sample.lua")
-- io.close(samplefile)

-- Explicit mode
-- samplefile = io.open("sample.lua","r")
-- print(samplefile:read())
-- samplefile:close()

-- samplefile = io.open("sample.lua","a")
-- samplefile:write(" -- End of the sample.lua")
-- samplefile:close()

-- seek
samplefile = io.open("sample.lua","r")
samplefile:seek("cur",-25)
print(samplefile:read("*a"))
samplefile:close()