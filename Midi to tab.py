from mido import MidiFile
import numpy as np

midi_dir = r"your directory here"
mid = MidiFile(midi_dir)

a = 0
b = 0
arr = [0,0,0]
for i, track in enumerate(mid.tracks):
    for msg in track:
        if not(msg.is_meta):
            a = msg.note
            b = msg.time + b
            if msg.type == 'note_on':
                newrow = [a,b,0]
                arr = np.vstack([arr, newrow])
                
arr = np.array(arr)
arr = np.delete(arr, 0, 0)

i = 0
for row in arr:
    arr[i,0] = arr[i,0] - 28
    i = i+1
    
i = 0
if arr[i,0] >= 15:
    arr[i,0] = arr[i,0] - 15
    arr[i,2] = 3
elif arr[i,0] >= 10:
    arr[i,0] = arr[i,0] - 10
    arr[i,2] = 2
elif arr[i,0] >= 5:
    arr[i,0] = arr[i,0] - 5
    arr[i,2] = 1
else:
    arr[i,2] = 2
    
x = 1
for i in range(len(arr)):
    if arr[x,0] - arr[x-1,0] >= 13 and arr[x,0] - 15 >= 0:
        arr[x,0] = arr[x,0] - 15
        arr[x,2] = 3
    elif arr[x,0] - arr[x-1,0] >= 8 and arr[x,0] - 10 >= 0:
        arr[x,0] = arr[x,0] - 10
        arr[x,2] = 2
    elif arr[x,0] - arr[x-1,0] >= 3 and arr[x,0] - 5 >= 0:
        arr[x,0] = arr[x,0] - 5
        arr[x,2] = 1
    else:
        arr[x,2] = 0
    x = x + 1
    
lineas = int((arr[-1,1])/1536+1)
i = 0
tiempo = -12  #el tiempo del guion inicial, cada uno vale 12
for i in range(lineas):
    tiempoI = tiempo
    f1 = []
    f1.append('G')
    for i in range(4):
        f1.append('|')
        for i in range(33):
            if tiempo in arr[:, 1]:
                a = np.where(arr[:,1] == tiempo)
                if arr[a,2] == 3:
                    append = str(arr[a,0])
                    append = str(append).replace('[','').replace(']','')
                    f1.append(append)
                else:
                    f1.append('-')
            else:
                f1.append('-')
            tiempo = tiempo + 12
        tiempo = tiempo - 12
    f1.append('|')
    f2 = []
    f2.append('D')
    tiempo = tiempoI
    for i in range(4):
        f2.append('|')
        for i in range(33):    
            if tiempo in arr[:, 1]:
                a = np.where(arr[:,1] == tiempo)
                if arr[a,2] == 2:
                    append = str(arr[a,0])
                    append = str(append).replace('[','').replace(']','')
                    f2.append(append)
                else:
                    f2.append('-')
            else:
                f2.append('-')
            tiempo = tiempo + 12
        tiempo = tiempo - 12
    f2.append('|')
    f3 = []
    f3.append('A')
    tiempo = tiempoI
    for i in range(4):
        f3.append('|')
        for i in range(33):    
            if tiempo in arr[:, 1]:
                a = np.where(arr[:,1] ==tiempo)
                if arr[a,2] == 1:
                    append = str(arr[a,0])
                    append = str(append).replace('[','').replace(']','')
                    f3.append(append)
                else:
                    f3.append('-')
            else:
                f3.append('-')
            tiempo = tiempo + 12
        tiempo = tiempo - 12
    f3.append('|')
    f4 = []
    f4.append('E')
    tiempo = tiempoI
    for i in range(4):
        f4.append('|')
        for i in range(33):    
            if tiempo in arr[:, 1]:
                a = np.where(arr[:,1] ==tiempo)
                if arr[a,2] == 0:
                    append = str(arr[a,0])
                    append = str(append).replace('[','').replace(']','')
                    f4.append(append)
                else:
                    f4.append('-')
            else:
                f4.append('-')
            tiempo = tiempo + 12
        tiempo = tiempo - 12
    f4.append('|')
    f5 = []
    for i in range(4):
        f5.append(' ')
        f5.append(' ')
        f5.append(' ')
        f5.append('1')
        f5.append(' ')
        f5.append('+')
        f5.append(' ')
        f5.append('+')
        f5.append(' ')
        f5.append('+')
        f5.append(' ')
        f5.append('2')
        f5.append(' ')
        f5.append('+')
        f5.append(' ')
        f5.append('+')
        f5.append(' ')
        f5.append('+')
        f5.append(' ')
        f5.append('3')
        f5.append(' ')
        f5.append('+')
        f5.append(' ')
        f5.append('+')
        f5.append(' ')
        f5.append('+')
        f5.append(' ')
        f5.append('4')
        f5.append(' ')
        f5.append('+')
        f5.append(' ')
        f5.append('+')
        f5.append(' ')
        f5.append('+')
    str1 = ''.join(f1)
    str2 = ''.join(f2)
    str3 = ''.join(f3)
    str4 = ''.join(f4)
    str5 = ''.join(f5)
    with open("Output3.txt", "a") as text_file:
         print(str1, file=text_file)
    with open("Output3.txt", "a") as text_file:
         print(str2, file=text_file)
    with open("Output3.txt", "a") as text_file:
         print(str3, file=text_file)
    with open("Output3.txt", "a") as text_file:
         print(str4, file=text_file)
    with open("Output3.txt", "a") as text_file:
         print(str5, file=text_file)
