import time

def string_compare(str1,str2):
    if len(str1) != len(str2):
        return False


    for i in range(len(str1)):
        if str1[i] != str2[i]:
            return False
        else:
            time.sleep(0.000001)
    return True

def change_char_string(i,string):
    if i==0:
        string = chr(ord(string[i]) + 1) + string[i+1:]
    elif i == 1:
        string = string[i-1] + chr(ord(string[i]) + 1) + string[i+1:]
    elif i == 2:
        string = string[i-2]+ string[i-1] + chr(ord(string[i]) + 1) + string[i+1:]
    elif i == 3:
        string = string[i-3]+ string[i-2] + string[i-1] + chr(ord(string[i]) + 1) + string[i+1:]
    elif i == 4:
        string = string[i-4]+ string[i-3] + string[i-2] + string[i-1] + chr(ord(string[i]) + 1) + string[i+1:]
    elif i == 5:
        string = string[i-5]+ string[i-4] + string[i-3] + string[i-2] + string[i-1] + chr(ord(string[i]) + 1) + string[i+1:]
    elif i == 6:
        string = string[i-6]+ string[i-5] + string[i-4] + string[i-3] + string[i-2] + string[i-1] + chr(ord(string[i]) + 1) + string[i+1:]
    elif i == 7:
        string = string[i-7]+ string[i-6] + string[i-5] + string[i-4] + string[i-3] + string[i-2] + string[i-1] + chr(ord(string[i]) + 1) + string[i+1:]
    return string

#######################################################################################

print("Timing attack on a ESP")
print("Password: ")
password = input()
password_length = len(password)

test_password = "0" * password_length
best_match = "0" * password_length
best_time = 0
match = False

for j in range(password_length):
    print("====================================")
    print("Switching character", j, "best match:", best_match)
    
    for i in range(10):
        start_time = time.time()
        match = string_compare(password, test_password)
        if match:
            break
        end_time = time.time()
        elapsed_time = end_time - start_time
                
        if elapsed_time > best_time and match==False:
            best_match = test_password
            best_time = elapsed_time
        print("Tested:", test_password, "Time taken:", elapsed_time)
        test_password=change_char_string(j,test_password)
    if match:
        break
    print("Best match:", best_match)
    test_password=best_match
    best_time = 0


if match:
    print("====================================")
    print("Password found:", test_password)
else:
    print("Best match:", best_match)