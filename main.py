import re

#password strength check

def strengthCheck(password):
    point=0

    #length of password
    if len(password) < 8:
        point = point - 1
    else:
        point = point + 1
        #characters in password
        num=re.search("[0-9]",password)
        alphaU=re.search("[a-z]",password)
        alphaL=re.search("[A-Z]",password)
        specialChar=re.search("[~`!@#$%^&*()_+=-{}\[\];:''\"\"\\<>,./?|*]",password)
    
        #now check the presence of above
        if num is None:
            point=point-1
        else : 
            point = point +1
    
        if alphaU is None:
            point=point-1
        else : 
            point = point +1
    
        if alphaL is None:
            point=point-1
        else : 
            point = point +1
    
        if specialChar is None:
            point=point-1
        else : 
            point = point +1
