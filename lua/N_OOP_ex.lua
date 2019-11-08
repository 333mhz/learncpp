-- Meta class
Shape = {area = 0}

-- Basic class
function Shape:new(o,side)
    o = o or {}
    setmetatable(o,self)
    self.__index = self
    side = side or 0
    self.area = side * side
    return o
end

function Shape:prt()
    print("Shape area:",self.area)
end

-- create object
o_shape = Shape:new(nil,10)
o_shape:prt()

-- Derived class
Square = Shape:new()

function Square:new(o,side)
    o = o or Shape:new(o,side)
    setmetatable(o,self)
    self.__index = self
    return o
end

function Square:prt()
    print("Square area:",self.area)
end

o_square = Square:new(nil,4)
o_square:prt()

Rectangle = Shape:new()

function Rectangle:new(o,length,breadth)
    o = o or Shape:new(o)
    setmetatable(o, self)
    self.__index = self
    self.area = length*breadth
    return o
end

function Rectangle:prt()
    print("Rectangle area:",self.area)
end

o_rectangle = Rectangle:new(nil,3,4)
o_rectangle:prt()
