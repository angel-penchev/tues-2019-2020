def accumulate_left(function, base, collection):
    converted_collection = list(collection)
    base = function(base, converted_collection[0])
    del converted_collection[0]
    
    if(not not converted_collection):
        return accumulate_left(function, base, converted_collection)
    else:
        return base
    

def accumulate_right(function, base, collection):
    converted_collection = list(collection)
    base = function(converted_collection[-1], base)
    del converted_collection[-1]
    
    if(not not converted_collection):
        return accumulate_right(function, base, converted_collection)
    else:
        return base
        
print(accumulate_left(lambda a, b: a / b, 64, [2, 4, 8]))
print(accumulate_right(lambda a, b: a / b, 8, [16, 32, 64]))
