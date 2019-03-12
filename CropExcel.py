# Cortar una imagen
import cv2
import random
import numpy
import xlrd

excel_dir = r"your excel file here"

book = xlrd.open_workbook(excel_dir) #nombre y ubicacion del archivo excel a leer
first_sheet = book.sheet_by_index(0)
#cy y cx coordenadas del centro del cilindro
i = 0
a = 2249
b = 2
while i < 151:
    cx = first_sheet.cell(a,b).value
    b = 3
    cy = first_sheet.cell(a,b).value
    b = 2
    a=a+1
    cx = cx + random.randint(-15,15)
    cy = cy + random.randint(-15,15)
    h = int(40)
    w = int(40)
    y = int(cy-h/2)
    x = int(cx-w/2)
    if x < 0:
        x = 0
    if x > 600:
        x = 600
    if y < 0:
        y = 0
    if y > 440:
        y = 440
    img = cv2.imread("/home/jtrevinoc/Documents/opencvcode/opencv2_frame_%d.png" % i) #nombre y ubicacion del archivo a leer
    crop_img = img[y:y+h, x:x+w]
    cv2.imwrite("/home/jtrevinoc/practicas/Cilindros nuevo/Cafe movido/Cafe2_%d_movido_crop.png" % i,crop_img)  #nombre y ubicacion del archivo a guardar
    #res = cv2.resize(crop_img,None,fx=(10/4), fy=(10/4), interpolation = cv2.INTER_CUBIC)
    #cv2.imwrite("/home/jtrevinoc/practicas/Vacio/Vacio_%d_crop.png" % i,res)     
    # cv2.imshow("cropped", crop_img)
    cv2.waitKey(0)
    i = i+1