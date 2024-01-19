import re
point=0
fpoint=0

#is in database  1  -1
def leakCheck(password):
    global fpoint
    with open("pfile1.txt","r") as file:
        data1=file.read()
    with open("pfile2.txt","r") as file:
        data2=file.read()
    if password in data1 or password in data2:
        fpoint=fpoint-1
    else:
        fpoint=fpoint+1

#character check  7 -4
def charCheck(password):
    global point
    #characters in password
    num=re.search("[0-9]",password)
    alphaL=re.search("[a-z]",password)
    alphaU=re.search("[A-Z]",password)
    specialChar=re.search("[~`!@#$%^&*()_+=-{};:''\"\"\\<>,./?|*]",password)
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
        point=point +1
    
    #reverse
    revPassword=password[::-1]
    revSpecialChar=re.search("[~`!@#$%^&*()_+=-{};:''\"\"\\<>,./?|*]",revPassword)
    revNum=re.search("[0-9]",revPassword)
    revAlphaL=re.search("[a-z]",revPassword)
    revAlphaU=re.search("[A-Z]",revPassword)

    #Special character is between first and last character
    if specialChar is not None:
        if specialChar.start() >0 or revSpecialChar.start() >0:
            point=point+1
        else:
            point=point-1
    if num is not None:
        if num.start() >0 or revNum.start() >0:
            point=point+1
        else:
            point=point-1
    if alphaL is not None:
        if alphaL.start() >0 or revAlphaL.start() >0:
            point=point+1
        else:
            point=point-1
    if alphaU is not None:
        if alphaU.start() >0 or revAlphaU.start() >0:
            point=point+1
        else:
            point=point-1
    
    leakCheck(password)


#length Checker   2 -2
def lenCheck(password):
    global point
    #length of password
    if len(password) < 8:
        point=point-2
    elif len(password) <12:
        point=point+1
        charCheck(password)
    else :
        point=point+2
        charCheck(password)

#main function password strength check   
def strengthCheck():
    
    global fpoint,point
    password=input("Check password strength : ")

    lenCheck(password)
    
    totalPoint=point+fpoint
    
    very_weak_threshold = -5
    weak_threshold = 0
    average_threshold = 3
    good_threshold = 6
    strong_threshold = 8
    
    # Check password strength based on total points
    if totalPoint <= very_weak_threshold:
        print("Oh no! Your password is as secure as a house no door.")
    elif totalPoint <= weak_threshold:
        print("Your password is a bit like leaving your front door unlocked.")
    elif totalPoint <= average_threshold:
        print("Try more!! Your password is like having a rope on your door.")
    elif totalPoint <= good_threshold:
        print("you can improve the password."+ "Total points: ")
    elif totalPoint < strong_threshold:
        print("Nice ! Your password is like a fortress protecting your secrets.")
    else:
        print("Wow! Your password is like Fort Knox. You're a security superhero!")
    print("Total points: ",totalPoint)
    
strengthCheck()