-- Multi-Dim
arr = {}

for i = -2,2 
do
    arr[i]={}
    for j = -2,2 
    do
        arr[i][j]=i*j
    end
end

for i = -2,2 
do
    for j = -2,2 
    do
        print(string.format("(%d,%d): ",i,j),arr[i][j])
    end
end