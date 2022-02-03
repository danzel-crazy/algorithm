def s_to_float(a):
    total = ""
    for i in a:
            
        if(a[i] == ","):
            i+1
        else :
            total = total + a[i]
    print (float(total))

a = "123,456.88"
s_to_float(a)